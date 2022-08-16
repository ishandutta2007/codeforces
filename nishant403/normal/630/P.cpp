#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ftype double

const double EPS = 1e-9;
const double pi = acos(-1);
//make sure to define ftype as int / float / double as required
//It can be used as 2D as well

struct point {
    ftype x, y, z=0;
    point() {}
    point(ftype x, ftype y, ftype z=0): x(x), y(y), z(z) {}
    
    point& operator=( pair<ftype,ftype> P)
    {
     x=P.first;
     y=P.second;
        return *this;
    }

    bool operator==(const point &t)
    {
      return (x==t.x && y==t.y && z==t.z);  
    }
    
    point& operator+=(const point &t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    
    
    point& operator-=(const point &t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    
     point& operator/=(const point &t) {
        
        return *this;
    }
    
    point& operator*=(ftype t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point& operator/=(ftype t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    
    point operator+(const point &t) const {
        return point(*this) += t;
    }
    point operator-(const point &t) const {
        return point(*this) -= t;
    }
    point operator*(ftype t) const {
        return point(*this) *= t;
    }
  
    point operator/(ftype t) const {
        return point(*this) /= t;
    }
    
    point operator/(const point &t) const {
        return point(*this) /= t;
    }
    
    
    bool operator<(const point& p) const
    {
        return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
    }
    
};

//ax + by = c
struct line
{
 ftype a,b,c;
    
    line() {}
    
    //passing through p and q
    line(point p,point q)
    {
     a=p.y-q.y;
     b=q.x-p.x;
     c=(a*p.x)+(b*p.y);
        
    norm();
    }
    
    line(ftype a1,ftype b1,ftype c1)
    {
    a = a1;
    b = b1;
    c = c1;
        
        norm();
    }
    
    void norm()
    {
        double z = sqrt(a * a + b * b);
        if (abs(z) > EPS)
            a /= z, b /= z, c /= z;
        
        if(a<0 || (a==0 && b<0) ) 
            a=-a,b=-b,c=-c;
    }
    
    double distance(point p)
    {
      norm();
      return abs(a*p.x + b*p.y - c); 
    }
    
};

double det(double a, double b, double c, double d) {
    return a*d - b*c;
}

//for line in 2-D
bool intersect(line m, line n, point & res) {
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
        return false;
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

//Area of polygon
double area(const vector<point>& fig) {
    double res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        point p = i ? fig[i - 1] : fig.back();
        point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}

signed main()
{
    int n,r;
    cin >> n >> r;
    
    point A(0,0);
    point B(r,0); 
    
    int skip = (n+1)/2;
    
    double angle_G = (2.00*pi/(double)n)*skip;
    double angle_D = (2.00*pi/(double)n)*(-1);
    
    point G(r*cos(angle_G),r*sin(angle_G));
    point D(r*cos(angle_D),r*sin(angle_D));
    point M = (B + D)/2;
   
    line L1(B,G);
    line L2(A,M);
    
    point C;
    assert(intersect(L1,L2,C));
    
    vector<point> tri = {A,B,C};
   cout << fixed << setprecision(10) << (2*n*area(tri));
}