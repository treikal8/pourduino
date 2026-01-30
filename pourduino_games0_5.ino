#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Teclas (pines digitales)
#define IZQUIERDA 2
#define DERECHA 3
#define A 6
#define B 7
#define START 8
 
#define OLED_RESET 4

Adafruit_SSD1306 display(128,32, &Wire, OLED_RESET);


/*SPRITES*/
 
/*MENU*/


// 'pou_feliz', 15x15px
const unsigned char PROGMEM  pou_feliz [] = {
	0x00, 0x7f, 0x00, 0x00, 0x01, 0xff, 0xf0, 0x00, 0x01, 0xe1, 0xf0, 0x00, 0x07, 0x80, 0x18, 0x00, 
	0x06, 0x00, 0x08, 0x00, 0x0e, 0x00, 0x0f, 0x00, 0x78, 0x61, 0x87, 0x80, 0x78, 0x61, 0x87, 0x80, 
	0x70, 0x61, 0x80, 0x80, 0xf0, 0x61, 0x80, 0xe0, 0xc0, 0x00, 0x00, 0x60, 0xc0, 0x00, 0x00, 0x60, 
	0xc0, 0x00, 0x00, 0x60, 0xc1, 0x80, 0xe0, 0x60, 0xc0, 0x7f, 0x00, 0x60, 0xf0, 0x00, 0x00, 0xe0, 
	0x78, 0x00, 0x07, 0x80, 0x78, 0x00, 0x07, 0x80, 0x0f, 0xff, 0xf8, 0x00
};


// 'pou_dormidoa', 27x19px
const unsigned char PROGMEM pou_dormidoa []  = {
	0x00, 0x7f, 0x00, 0x00, 0x01, 0xff, 0xf0, 0x00, 0x01, 0xe1, 0xf0, 0x00, 0x07, 0x80, 0x18, 0x00, 
	0x06, 0x00, 0x08, 0x00, 0x0e, 0x00, 0x0f, 0x00, 0x7c, 0x00, 0x0f, 0x80, 0x78, 0x00, 0x07, 0x80, 
	0x71, 0xf3, 0xe0, 0x80, 0xf0, 0x00, 0x00, 0xe0, 0xc0, 0x00, 0x00, 0x60, 0xc0, 0x00, 0x00, 0x60, 
	0xc0, 0x1f, 0x00, 0x60, 0xc0, 0x31, 0x80, 0x60, 0xc0, 0x20, 0x80, 0x60, 0xf0, 0x20, 0x80, 0xe0, 
	0x78, 0x1f, 0x07, 0x80, 0x78, 0x00, 0x07, 0x80, 0x0f, 0xff, 0xf8, 0x00
};
// 'pou_enfermoa', 27x19px
const unsigned char PROGMEM pou_enfermoa []  = {
	0x00, 0x7f, 0x00, 0x00, 0x01, 0xff, 0xf0, 0x00, 0x01, 0xe1, 0xf0, 0x00, 0x07, 0x80, 0x18, 0x00, 
	0x06, 0x00, 0x08, 0x00, 0x0e, 0xf1, 0xef, 0x00, 0x7d, 0x11, 0x1f, 0x80, 0x79, 0x11, 0x17, 0x80, 
	0x71, 0x11, 0x10, 0x80, 0xf1, 0x11, 0x10, 0xe0, 0xc0, 0xf1, 0xe0, 0x60, 0xc0, 0x00, 0x00, 0x60, 
	0xc0, 0x00, 0x00, 0x60, 0xc0, 0x3f, 0x80, 0x60, 0xc0, 0x40, 0x40, 0x60, 0xf0, 0x40, 0x40, 0xe0, 
	0x78, 0x7f, 0xc7, 0x80, 0x78, 0x00, 0x07, 0x80, 0x0f, 0xff, 0xf8, 0x00
};
// 'pou_facheroa', 27x19px
const unsigned char pou_facheroa [] PROGMEM = {
	0x00, 0x7f, 0x00, 0x00, 0x01, 0xff, 0xf0, 0x00, 0x01, 0xe1, 0xf0, 0x00, 0x07, 0x80, 0x18, 0x00, 
	0x06, 0x00, 0x08, 0x00, 0x0e, 0x00, 0x0f, 0x00, 0x7f, 0xff, 0xff, 0x80, 0x7b, 0x3b, 0x7f, 0x80, 
	0x71, 0x71, 0x70, 0x80, 0xf1, 0xe1, 0xe0, 0xe0, 0xc0, 0x00, 0x00, 0x60, 0xc0, 0x1f, 0xfc, 0x60, 
	0xc0, 0x10, 0x0a, 0x60, 0xc0, 0x1c, 0x0a, 0x60, 0xc0, 0x07, 0xfe, 0x60, 0xf0, 0x00, 0x00, 0xe0, 
	0x78, 0x00, 0x07, 0x80, 0x78, 0x00, 0x07, 0x80, 0x0f, 0xff, 0xf8, 0x00
};
// 'pou_molestoa', 27x19px
const unsigned char pou_molestoa [] PROGMEM = {
	0x00, 0x7f, 0x00, 0x00, 0x01, 0xff, 0xf0, 0x00, 0x01, 0xe1, 0xf0, 0x00, 0x07, 0x80, 0x18, 0x00, 
	0x06, 0x00, 0x08, 0x00, 0x0e, 0x00, 0x0f, 0x00, 0x7c, 0x00, 0x0f, 0x80, 0x78, 0x00, 0x07, 0x80, 
	0x71, 0xf0, 0x04, 0x80, 0xf0, 0x18, 0xf8, 0xe0, 0xc0, 0x4b, 0x80, 0x60, 0xc0, 0x0e, 0x20, 0x60, 
	0xc0, 0xe0, 0x08, 0x60, 0xc0, 0x30, 0x70, 0x60, 0xc0, 0x00, 0x00, 0x60, 0xf0, 0x00, 0x00, 0xe0, 
	0x78, 0x1f, 0x07, 0x80, 0x78, 0x00, 0x07, 0x80, 0x0f, 0xff, 0xf8, 0x00
};
// 'pou_hambrientoa', 27x19px
const unsigned char pou_hambrientoa [] PROGMEM = {
	0x00, 0x7f, 0x00, 0x00, 0x01, 0xff, 0xf0, 0x00, 0x01, 0xe1, 0xf0, 0x00, 0x07, 0x80, 0x18, 0x00, 
	0x06, 0x00, 0x08, 0x00, 0x0e, 0x22, 0x0c, 0x00, 0x0c, 0x22, 0x0c, 0x00, 0x08, 0x22, 0x04, 0x00, 
	0x08, 0x22, 0x04, 0x00, 0x08, 0x00, 0x04, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0b, 0x7f, 0x94, 0x00, 
	0x09, 0x40, 0xb4, 0x00, 0x09, 0x00, 0x24, 0x00, 0x09, 0x80, 0x24, 0x00, 0x0c, 0x80, 0x2c, 0x00, 
	0x06, 0x00, 0x18, 0x00, 0x03, 0xff, 0xf0, 0x00, 0x01, 0xff, 0xe0, 0x00
};
// 'pou_tristea', 27x19px
const unsigned char pou_tristea [] PROGMEM = {
	0x00, 0x7f, 0x00, 0x00, 0x01, 0xff, 0xf0, 0x00, 0x01, 0xe1, 0xf0, 0x00, 0x07, 0x80, 0x18, 0x00, 
	0x06, 0x00, 0x08, 0x00, 0x0e, 0x00, 0x0f, 0x00, 0x78, 0x61, 0x87, 0x80, 0x78, 0x61, 0x87, 0x80, 
	0x70, 0x61, 0x80, 0x80, 0xf0, 0x61, 0x80, 0xe0, 0xc0, 0x00, 0x00, 0x60, 0xc0, 0x00, 0x00, 0x60, 
	0xc0, 0x00, 0x00, 0x60, 0xc0, 0x7f, 0x80, 0x60, 0xc0, 0x80, 0x40, 0x60, 0xf1, 0x00, 0x40, 0xe0, 
	0x79, 0x00, 0x27, 0x80, 0x78, 0x00, 0x07, 0x80, 0x0f, 0xff, 0xf8, 0x00
};
// 'pou_dormidoa2', 27x19px
const unsigned char pou_dormidoa2 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x03, 0xc0, 0x70, 0x00, 
	0x07, 0x00, 0x38, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x3c, 0x00, 0x0f, 0x80, 0x78, 0x00, 0x07, 0xc0, 
	0x71, 0x0a, 0x10, 0xc0, 0xf1, 0x0a, 0x10, 0xe0, 0xc1, 0x0a, 0x10, 0x60, 0xc1, 0x0a, 0x10, 0x60, 
	0xc0, 0xf1, 0xe0, 0x60, 0xc0, 0x00, 0x00, 0x60, 0xc0, 0x00, 0x00, 0x60, 0xf0, 0x00, 0x00, 0xe0, 
	0x78, 0x00, 0x07, 0x80, 0x78, 0x00, 0x07, 0x80, 0x0f, 0xff, 0xf8, 0x00
};



/*Minijuego de la comida*/
// 'poum', 8x8px
const unsigned char PROGMEM poum []  = {
	0x07, 0xf8, 0x00, 0x08, 0x04, 0x00, 0x12, 0x12, 0x00, 0x22, 0x11, 0x00, 0x40, 0x00, 0x80, 0x47, 
	0xf8, 0x80, 0x88, 0x04, 0x40, 0x90, 0x02, 0x40, 0x90, 0x02, 0x40, 0x90, 0x02, 0x40, 0x90, 0x02, 
	0x40, 0x90, 0x02, 0x40, 0x4f, 0xfc, 0x80, 0x20, 0x01, 0x00, 0x1f, 0xfe, 0x00
};
// 'machete', 8x8px
const unsigned char PROGMEM machete []= {
	0xc2, 0x66, 0x3e, 0x3e, 0x78, 0xfc, 0xf6, 0xc3
};
// 'helado', 8x8px
const unsigned char PROGMEM helado []= {
	0x7e, 0xff, 0xff, 0x7f, 0x22, 0x12, 0x0a, 0x06
};


/*Minijuego Flappy Pou*/
const unsigned char PROGMEM tubo [] = {
	0xff, 0x81, 0x81, 0xff
};

const unsigned char PROGMEM cohete_pou []  = {
	0x2c, 0x5e, 0x75, 0xbf, 0xbf, 0xff, 0x1e
};

int puntaje_max_gloton=0;
int puntaje_max_flappypou=0;
int monedas=0;
uint8_t fallos=0;
int randnum=0; //PARA NUMEROS ALEATORIOS
int timer=0;

char salas[20][20] = {"Juegos","Cocina","Cuarto","Aseo","Salud"};
uint8_t largos[5]={14,6,6,12,10};

uint8_t precios_comidas[6]={7,15,6,30,4,5};//helado,sopa,manzana,sushi
uint8_t cura_comidas[6]={8,40,9,30,1,1};


//Estructura Pou
struct Pou{
  int saciedad;
  int salud;
  int energia;
  int alegria;
  int nivel;
  bool limpieza;
};
Pou Yo={70,70,70,70,0,false};


void reduccion_valores(){
  timer++;
  if(timer==1000){
    Yo.saciedad-=2;
    Yo.energia-=1;
    Yo.alegria-=2;
  }
  if(timer==2000){
    Yo.energia-=2;
    Yo.saciedad-=1;
    Yo.alegria-=1;
    Yo.salud-=1;
    Yo.nivel++;
    timer=0;
  }
  if(Yo.salud<87){
    Yo.limpieza=true;
  }
  if(Yo.saciedad<40 && timer==500){
    Yo.salud-=2;
    Yo.energia-=1;
  }
  if(Yo.energia<50 && timer==500){
    Yo.salud-=1;
    Yo.saciedad-=1;
  }
  if(Yo.limpieza && timer==500){
    Yo.salud-=4;
  }
}

void comida(){
  uint8_t i=0;
  delay(500);
  while(digitalRead(B)==1){
    bool lectura1;
    bool lectura2;
    lectura1=digitalRead(IZQUIERDA);
    lectura2=digitalRead(DERECHA);

    if(lectura1==false && i!=0){
      i--;
    }
    if(lectura2==false && i!=2){
      i++;
    }
    //Lista de juegos
    display.setCursor(40,0);
    display.print("Comida");
    display.setCursor(10,8);
    display.print("helado     $");
    display.setCursor(100,8);
    display.print(precios_comidas[0]);
    display.setCursor(10,16);
    display.print("sopa       $");
    display.setCursor(100,16);
    display.print(precios_comidas[1]);
    display.setCursor(10,24);
    display.print("manzana    $");
    display.setCursor(100,24);
    display.print(precios_comidas[2]);


    //Cursor
    display.setCursor(0,i*8 + 8);
    display.print(">");
    if(digitalRead(A)==0){
      if(monedas<precios_comidas[i]){
        display.clearDisplay();
        delay(30);
        display.setCursor(0,0);
        display.print("No tienes dinero");
        display.display();
        delay(500);
        display.clearDisplay();
        break;
      }
      monedas-=precios_comidas[i]; 
      Yo.saciedad+=cura_comidas[i];
      if(i==0) Yo.alegria+=4;Yo.energia++;
      if(i==1) Yo.salud+=20;
      if(i==2) Yo.salud+=6;
      display.clearDisplay();
      delay(30);
      display.setCursor(0,0);
      display.print("Comprado");
      display.setCursor(0,8);
      display.print("y comido");
      display.setCursor(0,24);
      display.print("monedas: ");
      display.setCursor(80,24);
      display.print(monedas);
      display.display();
      delay(500);
      break;
    }
    reduccion_valores();
    display.display();
    delay(150);
    display.clearDisplay();
  }
}

void tienda(){
  delay(200);
  while(digitalRead(B)==1){
    //Lista de juegos
    display.setCursor(40,0);
    display.print("Tienda");
    display.setCursor(10,8);
    display.print("Comida");
    //Cursor
    display.setCursor(0,8);
    display.print(">");
    if(digitalRead(A)==0){
      comida(); break;
    }
    display.display();
    reduccion_valores();
    delay(30);
    display.clearDisplay();
  }
}




void estadisticas(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("saciedad: ");
  display.setCursor(100,0);
  display.print(Yo.saciedad);
  display.setCursor(0,8);
  display.print("energia: ");
  display.setCursor(100,8);
  display.print(Yo.energia);
  display.setCursor(0,16);
  display.print("alegria: ");
  display.setCursor(100,16);
  display.print(Yo.alegria);
  display.setCursor(0,24);
  display.print("salud: ");
  display.setCursor(100,24);
  display.print(Yo.salud);
  display.display();
  delay(1400);
  display.clearDisplay();
  display.setCursor(0,8);
  display.print("Nivel: ");
  display.setCursor(100,8);
  display.print(Yo.nivel);
  display.setCursor(0,24);
  display.print("Monedas: ");
  display.setCursor(100,24);
  display.print(monedas);
  display.display();
  delay(1000);
  display.clearDisplay();
}

/*CLASES*/
class Menu{
  int habitacion;
  public:
    Menu(int);
    void eleccion();
    void sala_de_juegos();
    void cocina();
    void cuarto();
    void sala_de_aseo();
    void area_salud();
    void lista_de_juegos();
    int get_habitacion();
    void pasar_habitacion(bool);
    void set_habitacion(int);
};

Menu::Menu(int _habitacion){
  habitacion=_habitacion;
}

void Menu::eleccion(){
  switch(habitacion){
    case 0: sala_de_juegos();break;
    case 1: cocina();break;
    case 2: cuarto();break;
    case 3: sala_de_aseo();break;
    case 4: area_salud();break;
  }
}

void Menu::cocina(){
  display.setCursor(20,0);
  display.print("Cocina");
  if(digitalRead(A)==0){
    tienda();
  }
}

void Menu::pasar_habitacion(bool condi){
  if(condi){
    habitacion++;
  }
  else habitacion--;
}

void Menu::set_habitacion(int i){
  habitacion=i;
}

int Menu::get_habitacion(){
  return habitacion;
}

void Menu::cuarto(){
  display.setCursor(20,0);
  display.print("Cuarto");
  if(digitalRead(A)==0 && Yo.energia<80){
    int i=0;
    display.clearDisplay();
    display.display();
    delay(10);
    display.setCursor(0,0);
    display.print("ZZZ");
    display.drawBitmap(30,8,pou_dormidoa,27,19,WHITE);
    display.display();
    delay(1000);
    display.clearDisplay();
    display.drawBitmap(30,8,pou_dormidoa2,27,19,WHITE);
    display.display();
    
    while(digitalRead(B)==1 && Yo.energia<100){
      i++;
      if(i==400){
        Yo.energia+=2;
        Yo.salud-=1;
        Yo.saciedad-=1;
      }
      
      if(i==1000){
        Yo.saciedad-=1;
        Yo.alegria-=1;
        Yo.nivel++;
        i=0;
        
      } 
      delay(60);
    }
  }
}

void Menu::sala_de_aseo(){
  display.setCursor(20,0);
  display.print("Aseo");
  if(digitalRead(A)==0 && Yo.limpieza){
    display.clearDisplay();
    display.setCursor(20,0);
    display.print("limpiando...");
    display.display();
    Yo.salud+=20;
    Yo.limpieza=false;
    delay(1000);
  }
}

void Menu::area_salud(){
  display.setCursor(20,0);
  display.print("Salud");
  if(digitalRead(A)==0 && Yo.salud<60){
    display.clearDisplay();
    display.setCursor(20,0);
    display.print("Curando");
    display.display();
    Yo.salud=100;
    delay(1000);
  }
}

class Gloton{
  float x;
  float y;
  //ancho=18;
  //largo=15;
  public:
    Gloton(int,int);
    void dibujar();
    bool colision(int);
    void colision_ene(int);
    void set_x(int);
    void set_y(int);
};

Gloton::Gloton(int _x,int _y){
  x=_x;
  y=_y;
}

void Gloton::dibujar(){
  int lectura1=digitalRead(IZQUIERDA);
  int lectura2=digitalRead(DERECHA);
  int lectura3=digitalRead(A);
  int lectura4=digitalRead(B);
  if(lectura1==0 && x>40){
    x-=7.2;
    if(x<40) x=40;
  }
  else if(lectura2==0 && x<110){
    x+=7.2;
    if(x>110) x=110;
  }
  else if(lectura3==0){
    x=40;
  }
  else if(lectura4==0){
    x=110;
  }
  display.drawBitmap(x,y,poum,18,15,WHITE);
}

bool Gloton::colision(int ob_x){
  if((ob_x>=x+1) && (ob_x<=14+x)){
    return 1;
  }
  return 0;
}

void Gloton::colision_ene(int ob_x){
  if((ob_x>=x+2) && (ob_x<=14+x)){
    fallos=8;
  }
}

void Gloton::set_x(int _x){
  x=_x;
}

void Gloton::set_y(int _y){
  y=_y;
}


class Comida{
  float x;
  float y;
  float velocidad;
  //int ancho=7;
  //int largo=7;
  bool toque=false;
  public:
    Comida(int,int,float);
    void dibujar();
    int get_x();
    int get_y();
    void set_toque(bool);
};

Comida::Comida(int _x,int _y,float _velocidad){
  x=_x;
  y=_y;
  velocidad=_velocidad;
}

void Comida::dibujar(){
  y+=velocidad;
  if(y>=32 || toque==true){
    if(y>=32) fallos++;
    y=-4;
    x=random(78)+44;  
    toque=false;
  }
  display.drawBitmap(x,y,helado,7,7,WHITE);
}

int Comida::get_x(){
  return x;
}

int Comida::get_y(){
  return y;
}
void Comida::set_toque(bool t){
  toque=t;
}


class Obstaculo{
  int x;
  float y;
  //int ancho=8;
  //int largo=8;
  public:
    Obstaculo(int,int);
    void dibujar();
    int get_x();
    int get_y();
};

Obstaculo::Obstaculo(int _x,int _y){
  x=_x;
  y=_y;
}

void Obstaculo::dibujar(){
  y+=0.8;
  if(y>=32){
    y=0;
    x=random(78)+44;  
  }
  display.drawBitmap(x,y,machete,7,7,WHITE);
}

int Obstaculo::get_x(){
  return x;
}

int Obstaculo::get_y(){
  return y;
}

void minijuego_gloton(){ 
  int puntaje=0;

  Gloton player(40,17);
  Comida helado1(45,0,1.2);
  Comida helado2(76,6,1.1);
  Obstaculo machete1(100,0);
  Obstaculo machete2(120,6);

  while(fallos<=7){ //Se colocara aca el bucle del minijuego gloton
    player.dibujar();
    helado1.dibujar();
    helado2.dibujar();
    machete1.dibujar();
    machete2.dibujar();

    /*COLISIONES CON COMIDA Y ENEMIGOS*/
    if(helado1.get_y()>=20){
      helado1.set_toque(player.colision(helado1.get_x()));
      puntaje+=player.colision(helado1.get_x());
    } 
    if(helado2.get_y()>=20){
      helado2.set_toque(player.colision(helado2.get_x()));
      puntaje+=player.colision(helado2.get_x());
    }

    if(machete1.get_y()>=20 && machete1.get_y()<=23) player.colision_ene(machete1.get_x());
    if(machete2.get_y()>=20 && machete2.get_y()<=23) player.colision_ene(machete2.get_x());
    
    //A la derecha del minijuego
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("score");
    display.setCursor(0,8);
    display.println(puntaje);
    display.setCursor(0,16);
    display.println("fail:");
    display.setCursor(0,24);
    display.println(fallos);
    display.display();
    delay(30);

    display.clearDisplay();
  }
  fallos=0;
  display.clearDisplay();
  display.setCursor(30,10);
  display.println("game over");
  display.display();
  monedas+=puntaje/4;
  delay(1000);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("puntaje: ");
  display.setCursor(0,8);
  display.println(puntaje);
  display.setCursor(0,16);
  display.println("moneda: ");
  display.setCursor(50,16);
  display.println(monedas);
  display.display();
  delay(1000);
  display.clearDisplay();
  if(puntaje>puntaje_max_gloton){
    display.setCursor(0,0);
    display.println("nuevo mayor");
    display.setCursor(0,8);
    display.println("puntaje");
    display.setCursor(0,16);
    display.println("anterior: ");
    display.setCursor(55,16);
    display.print(puntaje_max_gloton);
    puntaje_max_gloton=puntaje;
  }
  else{
    display.setCursor(0,0);
    display.println("mayor puntaje");
    display.setCursor(0,8);
    display.println(puntaje_max_gloton);
  }
  display.display();
  delay(2000);
  Yo.saciedad+=2;
  Yo.energia-=3;
  Yo.salud-=1;
  Yo.alegria+=11;
}

class Tubos{
  float x;
  float y;
  uint8_t evitados=0;
  //ancho=8
  //largo=4
  public:
    Tubos(int,int);
    void pintar();
    void colision(int);
    int get_evitados();
    int get_x();
    void modo_juerga();
};

Tubos::Tubos(int _x,int _y){
  x=_x;
  y=_y;
}

void Tubos::pintar(){
  x-=2.5;
  display.drawBitmap(x,y,tubo,8,4,WHITE);
  display.drawLine(x+1,y-1,x+1,0,WHITE);
  display.drawLine(x+6,y-1,x+6,0,WHITE);
  display.drawBitmap(x,y+20,tubo,8,4,WHITE);
  display.drawLine(x+1,y+24,x+1,32,WHITE);
  display.drawLine(x+6,y+24,x+6,32,WHITE);

  if(x<-7){
    x=128;
    y=random(8)+2;
    evitados++;
  } 
}

void Tubos::colision(int ob_y){
  if (y+4>ob_y || ob_y>y+12) fallos++;
}

int Tubos::get_x(){
  return x;
}

int Tubos::get_evitados(){
  return evitados;
}

void minijuego_flappypou(){
  int puntaje;

  float player_x=0;
  float player_y=10;
  Tubos tubo1(128,random(8)+2);
  Tubos tubo2(128,random(8)+2);
  Tubos tubo3(128,random(8)+2);
  uint8_t clock=0;
  int i=0;
  while(fallos==0 && tubo1.get_evitados()+tubo2.get_evitados()+tubo3.get_evitados()<1000){
    player_y+=0.1*(i);//movimiento

    int lectura1=digitalRead(A);
    if(lectura1==0){//Cuando me impulse
      player_y-=2.8;
      i=0;
    }
    i++;

    display.drawBitmap(player_x,player_y,cohete_pou,8,7,WHITE);
    if(player_y-8>=32) fallos++; //Si me choco con el piso, salgo del juego

    //Aparicion de tubos
    tubo1.pintar();
    clock++;
    if(clock>=72) tubo2.pintar();
    if(clock>=145){
      tubo3.pintar();
      clock=160;
    }

    if(player_x+8>tubo1.get_x() && player_x<tubo1.get_x()+8) tubo1.colision(player_y);
    if(player_x+8>tubo2.get_x() && player_x<tubo2.get_x()+8) tubo2.colision(player_y);
    if(player_x+8>tubo3.get_x() && player_x<tubo3.get_x()+8) tubo3.colision(player_y);

    display.display();
    delay(30);
    display.clearDisplay();
  }
  fallos=0;
  puntaje=tubo1.get_evitados()+tubo2.get_evitados()+tubo3.get_evitados();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(30,10);
  display.println("game over");
  display.display();
  monedas+=puntaje/2;
  delay(1000);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("puntaje: ");
  display.setCursor(0,8);
  display.println(puntaje);
  display.setCursor(0,16);
  display.println("moneda: ");
  display.setCursor(50,16);
  display.println(monedas);
  display.display();
  delay(1500);
  display.clearDisplay();
  Yo.nivel+=puntaje/100;

  if(puntaje>puntaje_max_flappypou){
    display.setCursor(0,0);
    display.println("nuevo mayor");
    display.setCursor(0,8);
    display.println("puntaje");
    display.setCursor(0,16);
    display.println("anterior: ");
    display.setCursor(55,16);
    display.print(puntaje_max_flappypou);
    puntaje_max_flappypou=puntaje;
  }
  else{
    display.setCursor(0,0);
    display.println("mayor puntaje");
    display.setCursor(0,8);
    display.println(puntaje_max_flappypou);
  }
  display.display();
  delay(2000);
  Yo.energia-=3;
  Yo.salud-=1;
  Yo.saciedad-=4;
  Yo.alegria+=10;
}

void Menu::sala_de_juegos(){
  display.setCursor(20,0);
  display.print("Juegos");
  if(digitalRead(A)==0){
    lista_de_juegos();
  }
}


void Menu::lista_de_juegos(){
  uint8_t i=0;
  delay(1000);
  while(digitalRead(B)==1){
    bool lectura1;
    bool lectura2;
    lectura1=digitalRead(IZQUIERDA);
    lectura2=digitalRead(DERECHA);

    if(lectura1==false && i!=0){
      i--;
    }
    if(lectura2==false && i!=1){
      i++;
    }
    //Lista de juegos
    display.setCursor(10,0);
    display.print("Gloton");
    display.setCursor(10,8);
    display.print("flappy_pou");
    //Cursor
    display.setCursor(0,i*8);
    display.print(">");
    if(digitalRead(A)==0){
      switch(i){
        case 0: minijuego_gloton(); break;
        case 1: minijuego_flappypou(); break;
      }
    }
    reduccion_valores();
    display.display();
    delay(30);
    display.clearDisplay();
  }
}


/*PROCESO*/
void setup() 
{
  randomSeed(analogRead(A0));//Para resultados aleatorios en ciertos minijuegos
  
  //teclas
  pinMode(IZQUIERDA,INPUT_PULLUP);
  pinMode(DERECHA,INPUT_PULLUP);
  pinMode(B,INPUT_PULLUP);
  pinMode(A,INPUT_PULLUP);
  pinMode(START,INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // here the 0x3c is the I2C address, check your i2c address if u have multiple devices.
  display.clearDisplay();
  delay(2000);
}

void transicion_de(char word1[],uint8_t largo1,char word2[],int y){
  for(int i=20;i>0-largo1;i-=16){
    display.setCursor(i,y);
    display.print(word1);
    display.display();
    delay(30);
    display.clearDisplay();
  }
  for(int i=128;i>20;i-=16){
    display.setCursor(i,y);
    display.print(word2);
    display.display();
    delay(30);
    display.clearDisplay();
  }
}

void transicion_iz(char word1[],uint8_t largo1,char word2[],int y){
  for(int i=20;i<128+largo1;i+=16){
    display.setCursor(i,y);
    display.print(word1);
    display.display();
    delay(30);
    display.clearDisplay();
  }
  for(int i=-20;i<16;i+=20){
    display.setCursor(i,y);
    display.print(word2);
    display.display();
    delay(30);
    display.clearDisplay(); 
  }
}

void loop() 
{
  Menu M(1);
  display.setTextSize(1);
  display.setTextColor(WHITE);

  bool vida=true;
  while(vida){
    M.eleccion();

    if(Yo.salud<40){
      display.drawBitmap(40,10,pou_enfermoa,27,19,WHITE);
    }
    else if(Yo.saciedad<40){
      display.drawBitmap(40,10,pou_hambrientoa,27,19,WHITE);
    }
    else if(Yo.alegria<30){
      display.drawBitmap(40,10,pou_tristea,27,19,WHITE);
    }
    else if(Yo.alegria<40 && Yo.alegria>=30){
      display.drawBitmap(40,10,pou_molestoa,27,19,WHITE);
    }
    else{
      display.drawBitmap(40,10,pou_feliz,27,19,WHITE);
    }
    

    //cambiar de sala
    if(digitalRead(IZQUIERDA)==0 && M.get_habitacion()>0){
      transicion_iz(salas[M.get_habitacion()],largos[M.get_habitacion()],salas[M.get_habitacion()-1],0);
      M.pasar_habitacion(0);
    }
    else if(digitalRead(IZQUIERDA)==0 && M.get_habitacion()==0){
      transicion_iz(salas[0],largos[0],salas[4],0);
      M.set_habitacion(4);
    }
    if(digitalRead(DERECHA)==0 && M.get_habitacion()<4){
      transicion_de(salas[M.get_habitacion()],largos[M.get_habitacion()],salas[M.get_habitacion()+1],0);
      M.pasar_habitacion(1);
    }
    else if(digitalRead(DERECHA)==0 && M.get_habitacion()==4){
      transicion_de(salas[4],largos[4],salas[0],0);
      M.set_habitacion(0);
    }

    if(digitalRead(START)==0){
      estadisticas();
      if(Yo.limpieza){    
        display.setCursor(0,0);
        display.print("Necesita aseo");
        display.display();
        delay(500);
      }
      
    }
    display.display();

    //Timer y reduccion de estadisticas
    reduccion_valores();

    //Verificacion de sobrepaso de valores:
    if(Yo.alegria>100) Yo.alegria=100;
    if(Yo.salud>100)   Yo.salud=100;
    if(Yo.saciedad>100) Yo.saciedad=100;
    if(Yo.energia>100)  Yo.energia=100;


    if(Yo.salud==0 || Yo.saciedad==0 || Yo.energia==0 || Yo.alegria==0 || Yo.nivel==280){
      vida=false;   
    }
    
    delay(30);
    display.clearDisplay();
  }

  //Pou ha muerto
  if(Yo.nivel<1300){
    display.setCursor(0,0);
    display.print("Pou ha muerto...");
  }
  else{
    display.setCursor(0,0);
    display.print("Pou ha muerto");
    display.setCursor(0,8);
    display.print("de vejez...");
  }
  display.display();
  delay(1000);
  estadisticas();
  display.clearDisplay();
  display.display();
  
  while(1);
}
