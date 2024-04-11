#include "bits/stdc++.h"
using namespace std;
struct point{
    long double x;
    long double y;
    point(long double _x = 0.0 , long double _y = 0.0){
        x = _x;
        y = _y;
    }
    long double mag(){
        return sqrt(x * x + y * y);
    }
    point operator + (point b){
        return point(x + b.x , y + b.y);
    }
    point operator * (long double a){
        return point(x * a , y * a);
    }
    point operator / (long double a){
        return point(x / a , y / a);
    }
    point ccw(){
        return point(-y , x);
    }
    point cw(){
        return point(y , -x);
    }
    void print(){
        cout << fixed << setprecision(9) << x << " " << y << endl;
    }
};
long double px , py , vx , vy , a , b , c , d;
int main(){
    cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
    point dir = point(vx , vy) / point(vx , vy).mag();
    point p1 = point(px , py) + dir * b;
    point p2 = point(px , py) + dir.ccw() * (a / 2.0);
    point p3 = point(px , py) + dir.ccw() * (c / 2.0);
    point p4 = p3 + dir.ccw().ccw() * d;
    point p5 = p4 + dir.cw() * c;
    point p6 = p5 + dir * d;
    point p7 = point(px , py) + dir.cw() * (a / 2.0);
    p1.print();
    p2.print();
    p3.print();
    p4.print();
    p5.print();
    p6.print();
    p7.print();
}