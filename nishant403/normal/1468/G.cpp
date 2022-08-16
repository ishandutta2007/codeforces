#include <bits/stdc++.h>
using namespace std;
 
#define ftype  double

const double EPS = 1e-9;

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

ftype dot(point a, point b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

ftype norm(point a) {
    return dot(a, a);
}

double abs(point a) {
    return sqrt(norm(a));
}

//clockwise : right turn
bool cw(point a, point b, point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0;
}

//counter-clockwise : left turn
bool ccw(point a, point b, point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

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
    }
};

double det(double a, double b, double c, double d) {
    return a*d - b*c;
}

//for line in 2-D
bool intersect(line m, line n, point & res) 
{   
    double zn = det(m.a, m.b, n.a, n.b);
    
    if (abs(zn) < EPS)
        return false;
    
    res.x = det(m.c, m.b, n.c, n.b) / zn;
    res.y = det(m.a, m.c, n.a, n.c) / zn;
    
    return true;
}

#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define precise(x) fixed << setprecision(x) 

signed main()
{
   int n,h;
    scanf("%d %d",&n,&h);
    
  point a[n];
  int v1,v2;
  
  f(i,n)
  {
      scanf("%d %d",&v1,&v2);
      a[i].x = v1;
      a[i].y = v2;
  }
    
   point sun = a[n-1];
   sun.y += h ;
    
   double tot = 0.00000000;
   point saver = a[n-1]; 
    
   for(int i=n-2;i>=0;i--)
   {
       point res = a[i];
       
       //case 1 : does not cover
       if(ccw(sun,saver,a[i])) res = a[i];
       
       //case 2 : complete cover
       else if(cw(sun,saver,a[i+1])) res = a[i+1];
       
       //case 3 : partial cover : find intersection
       else intersect(line(sun,saver),line(a[i],a[i+1]),res);
       
       tot += abs(a[i] - res);
       
       if(cw(sun,saver,a[i])) saver = a[i];
   }
    
    cout << precise(7) << tot;
}