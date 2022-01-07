#include "pitches.h"


int melody[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

void Playtone13()
{
  for (int thisNote = 0; thisNote < 8; thisNote++)
{

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(8);

  }
}

void Playtone24()
{
  for (int thisNote = 0; thisNote < 8; thisNote++)
{

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(A5, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(A5);

  }
}


// Assumption: We begin with a green for pedestrians
// and it repeats after an entire cycle
const int g1 = 2;
const int y1 = 3;
const int r1 = 4;
const int g2 = 5;
const int y2 = 6;
const int r2 = 7;
const int g3 = A4;
const int y3 = 9;
const int r3 = 10;
const int g4 = 11;
const int y4 = 12;
const int r4 = 13;
const int pred = A2;
const int pgreen = A3;
const int pred1=A0;
const int pgreen1=A1;
 const int pIN=8;
const int pIN1=A5;
void setup()

{
pinMode (r1, OUTPUT);
pinMode (y1, OUTPUT);
pinMode (g1, OUTPUT);
pinMode (r2, OUTPUT);
pinMode (y2, OUTPUT);
pinMode (g2, OUTPUT);
pinMode (r3, OUTPUT);
pinMode (y3, OUTPUT);
pinMode (g3, OUTPUT);
pinMode (r4, OUTPUT);
pinMode (y4, OUTPUT);
pinMode (g4, OUTPUT);
pinMode (pred, OUTPUT);
pinMode (pgreen, OUTPUT);
pinMode (pred1, OUTPUT);
pinMode (pgreen1, OUTPUT);
digitalWrite (r1, HIGH);
digitalWrite (r2, HIGH);
digitalWrite (r3, HIGH);
digitalWrite (r4, HIGH);
digitalWrite (pgreen, HIGH);
digitalWrite (pred1, HIGH);
pinMode (pIN, INPUT);//Button 8
pinMode (pIN1, INPUT);//Button A5


}

void loop() {
WalkCycle13();

WalkCycle24();





}
// The WalkCycle function is for pedestrians
void WalkCycle13() {
  delay(350);
digitalWrite (g1, LOW);digitalWrite (g2, HIGH);digitalWrite (g3, LOW);digitalWrite (g4, HIGH);
digitalWrite (y1, LOW);digitalWrite (y2, LOW);digitalWrite (y3, LOW);digitalWrite (y4, LOW);
digitalWrite (r1, HIGH);digitalWrite (r2, LOW);digitalWrite (r3, HIGH);digitalWrite (r4, LOW);


   
  digitalWrite (pgreen, HIGH);
  Playtone13();
  digitalWrite (pred, LOW);
  delay (3000);
  digitalWrite (pgreen, LOW);
  //digitalWrite(pIN, LOW);  // Turn off green Pedestrian Light
  delay(250);
  for (int x = 0; x < 5; x++) {  // Flash green Ped LED 5X
    digitalWrite(pgreen, HIGH);
    Playtone13();
    delay(250);
    digitalWrite(pgreen, LOW);
    delay(250);
  }
  digitalWrite(pred, HIGH);
  turn();
}
void WalkCycle24() {
  delay(350);
digitalWrite (g1, HIGH);digitalWrite (g2, LOW);digitalWrite (g3, HIGH);digitalWrite (g4, LOW);
digitalWrite (y1, LOW);digitalWrite (y2, LOW);digitalWrite (y3, LOW);digitalWrite (y4, LOW);
digitalWrite (r1, LOW);digitalWrite (r2, HIGH);digitalWrite (r3, LOW);digitalWrite (r4, HIGH);

   
  digitalWrite (pgreen1, HIGH);
  Playtone24();
  digitalWrite (pred1, LOW);
  delay (3000);
  digitalWrite (pgreen1, LOW);
  //digitalWrite(pIN, LOW);  // Turn off green Pedestrian Light
  delay(250);
  for (int x = 0; x < 5; x++) {  // Flash green Ped LED 5X
    digitalWrite(pgreen1, HIGH);
    Playtone24();
    delay(250);
    digitalWrite(pgreen1, LOW);
    delay(250);
  }
  digitalWrite(pred1, HIGH);
  turn();
}
void turn(){
  delay(100);  
digitalWrite (r1, LOW);    
digitalWrite(g1,HIGH); //1st Light
digitalWrite(r2,HIGH);
digitalWrite(r3,HIGH);
digitalWrite(r4,HIGH);
delay(4000);


digitalWrite(g1,LOW);

digitalWrite(y1,HIGH);
digitalWrite(r2,HIGH);
digitalWrite(r3,HIGH);
digitalWrite(r4,HIGH);
delay(2000);
 
digitalWrite(y1,LOW);
digitalWrite(r2,LOW);

digitalWrite(r1,HIGH);
digitalWrite(g2,HIGH); //2nd light
digitalWrite(r3,HIGH);
digitalWrite(r4,HIGH);
delay(4000);

digitalWrite(g2,LOW);

digitalWrite(y2,HIGH);
digitalWrite(r1,HIGH);
digitalWrite(r3,HIGH);
digitalWrite(r4,HIGH);
delay(2000);

digitalWrite(y2,LOW);
digitalWrite(r3,LOW);

digitalWrite(g3,HIGH);//3rd light
digitalWrite(r1,HIGH);
digitalWrite(r2,HIGH);
digitalWrite(r4,HIGH);
delay(4000);

digitalWrite(g3,LOW);

digitalWrite(y3,HIGH);
digitalWrite(r1,HIGH);
digitalWrite(r2,HIGH);
digitalWrite(r4,HIGH);
delay(2000);

digitalWrite(y3,LOW);
digitalWrite(r3,LOW);
digitalWrite(r4,LOW);

digitalWrite(g4,HIGH);//4th light
digitalWrite(r1,HIGH);
digitalWrite(r2,HIGH);
digitalWrite(r3,HIGH);
delay(4000);

digitalWrite(g4,LOW);
digitalWrite(r4,LOW);


digitalWrite(y4,HIGH);
digitalWrite(r1,HIGH);
digitalWrite(r2,HIGH);
digitalWrite(r3,HIGH);
delay(2000);

digitalWrite(y4,LOW);
digitalWrite(r4,LOW);
digitalWrite(r1,LOW);
}
