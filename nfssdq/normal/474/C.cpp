/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(LL I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

const double eps=1e-7;
const double pi=acos(-1.0);
int dblcmp(double d)
{
    if (fabs(d)<eps)return 0;
    return d>eps?1:-1;
}
inline double sqr(double x){return x*x;}
/*
point()						- Empty constructor
point(double x, double y)	- constructor
input()						- double input
output()					- .2lf output
operator ==					- compares x and y
operator <					- compares first by x, then by y
len()						- gives length from origin
len2()						- gives square of length from origin
distance(point p)			- gives distance from p
add(point p)				- returns new point after adding curresponging x and y
sub(point p)				- returns new point after subtracting curresponging x and y
mul(double b)				- returns new point after multiplieing x and y by b
div(double b)				- returns new point after divideing x and y by b
dot(point p)				- dot product
det(point p)				- cross product of 2d points
rad(point a, point b)		- Probably radius of circumcircle of the triangle
trunc(double r)				- return point that is truncated the distance from center to r
rotleft()					- returns 90 degree ccw rotated point
rotright()					- returns 90 degree cw rotated point
rotate(point p, double angle) - returns point after rotateing the point centering at p by angle radian ccw
*/
struct point
{
    double x,y;
    point()             {                                    }
    point(double _x,double _y){    x = _x; y = _y;           }
    void input()        {   scanf("%lf%lf",&x,&y);           }
    void output()       {   printf("%.2f %.2f\n",x,y);       }
    bool operator==(point a)const{
        return dblcmp(a.x - x) == 0 && dblcmp(a.y - y) == 0;
    }
    bool operator<(point a)const{
        return dblcmp(a.x - x) == 0 ? dblcmp(y - a.y) < 0 : x < a.x;
    }
    point operator-(point a)const{
		return point(x-a.x, y-a.y);
	}
    double len()        {   return hypot(x, y);              }
    double len2()       {   return x * x + y * y;            }
    double distance(point p){return hypot(x - p.x, y - p.y); }
    point add(point p)  {   return point(x + p.x, y + p.y);  }
    point sub(point p)  {   return point(x - p.x, y - p.y);  }
    point mul(double b) {   return point(x * b, y * b);      }
    point div(double b) {   return point(x / b, y / b);      }
    double dot(point p) {   return x*p.x+y*p.y;              }
    double det(point p) {   return x*p.y-y*p.x;              }
    double rad(point a,point b){
        point p=*this;
        return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    point trunc(double r){
        double l=len();
        if (!dblcmp(l))return *this;
        r/=l;
        return point(x*r,y*r);
    }
    point rotleft()     {   return point(-y,x);              }
    point rotright()    {   return point(y,-x);              }
    point rotate(point p,double angle){
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
};
point ar[4][2];
int ok(double a, double b, double c, double d){
    if(abs(a - b) > eps || abs(a - c) > eps || abs(a - d) > eps) return 0;
    if(abs(b - c) > eps || abs(b - d) > eps || abs(c - d) > eps) return 0;
    return 1;
}
double degtorad(double p){
    return (pi * p) / 180.0;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d,e = 0,f,g,h = 1,x = 0,y,z;
    cin >> a;
    REP(ts, a){
        REP(i, 4){
            cin >> b >> c;
            ar[i][0] = point(b, c);
            cin >> b >> c;
            ar[i][1] = point(b, c);
        }
        f = 200;
        REP(i, 4){
            REP(j, 4){
                REP(k, 4){
                    REP(l, 4){
                        point p1 = ar[0][0].rotate(ar[0][1], degtorad(90.0 * (double)i));
                        point p2 = ar[1][0].rotate(ar[1][1], degtorad(90.0 * (double)j));
                        point p3 = ar[2][0].rotate(ar[2][1], degtorad(90.0 * (double)k));
                        point p4 = ar[3][0].rotate(ar[3][1], degtorad(90.0 * (double)l));
                        g = i+j+k+l;
                        double d1,d2,d3,d4,d5,d6;
                        // p1 p2 p3 p4
                        d1 = p1.distance(p2);
                        d2 = p2.distance(p4);
                        d3 = p1.distance(p3);
                        d4 = p3.distance(p4);
                        d5 = p1.distance(p4);
                        d6 = p3.distance(p2);
                        if(ok(d1,d2,d3,d4) && abs(d5-d6) < eps && d1 > eps && d5 > d1){
                            f = min(f, g);
                        }
                        // p1 p2 p4 p3
                        d1 = p1.distance(p2);
                        d2 = p2.distance(p3);
                        d3 = p1.distance(p4);
                        d4 = p3.distance(p4);
                        d5 = p1.distance(p3);
                        d6 = p4.distance(p2);
                        if(ok(d1,d2,d3,d4) && abs(d5-d6) < eps && d1 > eps && d5 > d1){
                            f = min(f, g);
                        }
                        // p1 p3 p4 p2
                        d1 = p1.distance(p3);
                        d2 = p3.distance(p2);
                        d3 = p1.distance(p4);
                        d4 = p2.distance(p4);
                        d5 = p1.distance(p2);
                        d6 = p3.distance(p4);
                        if(ok(d1,d2,d3,d4) && abs(d5-d6) < eps && d1 > eps && d5 > d1){
                            f = min(f, g);
                        }
                    }
                }
            }
        }
        if(f > 150) cout << -1 << endl;
        else cout << f << endl;
    }
}