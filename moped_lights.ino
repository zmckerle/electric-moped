#include <FastLED.h>

#define BUTTON_PIN_1  0 
#define BUTTON_PIN_2  3 
#define LED_PIN_1     6 
#define LED_PIN_2     9 
#define NUM_LEDS     10 

#define LONG_PRESS_DURATION 10 
#define ANIMATION_BREAK_DELAY 170 

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];

void colorWave(CRGB leds[], int numLeds);

void setup() {
  Serial.begin(9600); 
  FastLED.addLeds<NEOPIXEL, LED_PIN_1>(leds1, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, LED_PIN_2>(leds2, NUM_LEDS);
  FastLED.show(); 
  pinMode(BUTTON_PIN_1, INPUT_PULLUP); 
  pinMode(BUTTON_PIN_2, INPUT_PULLUP); 
}

void loop() {
  if (digitalRead(BUTTON_PIN_1) == LOW) {
    unsigned long buttonPressTime = millis();

    while (digitalRead(BUTTON_PIN_1) == LOW) {
      if (millis() - buttonPressTime >= LONG_PRESS_DURATION) {
        colorWave(leds1, NUM_LEDS);
        break; 
      }
    }
  } else {
    fill_solid(leds1, NUM_LEDS, CRGB::Black); 
    FastLED.show();
  }

  if (digitalRead(BUTTON_PIN_2) == LOW) {
    unsigned long buttonPressTime = millis();

    while (digitalRead(BUTTON_PIN_2) == LOW) {
      if (millis() - buttonPressTime >= LONG_PRESS_DURATION) {
        colorWave(leds2, NUM_LEDS);
        break; 
      }
    }
  } else {
    fill_solid(leds2, NUM_LEDS, CRGB::Black); 
    FastLED.show();
  }
}

void colorWave(CRGB leds[], int numLeds) {
  static int colorWavePosition = 0; 


  for (int i = 0; i < numLeds; i++) {
    leds[i] = CRGB(255, 0, 0); 
    FastLED.show(); 
    delay(65);
  }

  fill_solid(leds, numLeds, CRGB::Black); 
  FastLED.show(); 
  delay(ANIMATION_BREAK_DELAY); 

  colorWavePosition = 0; 
}
