#include <BleKeyboard.h>

BleKeyboard bleKeyboard;
const int iPin = 23; // Pin connected to one side of the push button
const int oPin = 22; // Pin connected to the other side of the push button
const int iPin2 = 0; // Pin connected to the other side of the push button
const int led = 2;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  
  pinMode(iPin, INPUT_PULLUP);
  pinMode(iPin2, INPUT_PULLUP);
  pinMode(oPin, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(oPin, LOW); 
}

void loop() {
  if(bleKeyboard.isConnected()) {
    int buttonState2 = digitalRead(iPin);
    if (buttonState2 == LOW) {
        Serial.println("Button is pressed!");   
        Serial.println("Sending Play/Pause media key...");
        bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
    }

    int buttonState0 = digitalRead(iPin2);
    if (buttonState0 == LOW) {
        Serial.println("Button is pressed!");   
        Serial.println("Sending Play/Pause media key...");
        bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
    }
    delay(10);
    //Serial.println(buttonState0);
    //Serial.println(buttonState2);
  }
}
