#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <cstring>  
#include <stack>  
using namespace std;  
  
const double PI = 3.1415926535;  
const double ERR = 0.01;  
  
bool feq (double a, double b) {  
    return fabs(a-b) < ERR;  
}  
  
double fgcd(double a, double b) {  
    if (feq(a, 0)) return b;  
    if (feq(b, 0)) return a;  
    return fgcd(b, fmod(a, b));  
}  
  
double dist(double x0, double x1, double y0, double y1) {  
    return sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0));  
}  
  
int main() {  
    double x[3];  
    double y[3];  
    for (int i = 0; i < 3; i++) scanf("%lf %lf", &x[i], &y[i]);  
      
    double l[3];  
    for (int i = 0; i < 3; i++) l[i] = dist(x[i], x[(i+1)%3], y[i], y[(i+1)%3]);  
  
    double p = (l[0] + l[1] + l[2]) / 2;  
  
    double s = sqrt(p * (p-l[0]) * (p-l[1]) * (p-l[2]));  
  
    double r = l[0] * l[1] * l[2] / (s * 4);  
  
    double ang[3];  
    for (int i = 0; i < 3; i++) ang[i] = acos(1 - l[i]*l[i] / (2 * r * r));  
    ang[2] = 2 * PI - ang[0] - ang[1];  
  
    double unita = 0;  
    for (int i = 0; i < 3; i++) unita = fgcd(unita, ang[i]);  
  
    printf("%.6lf\n", r * r * sin(unita) * PI / unita);  
    return 0;  
}