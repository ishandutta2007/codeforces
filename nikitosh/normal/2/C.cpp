#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef double dbl;

#define FNAME ""

const int MAX_N = 10;
const double EPS = 1e-6;

int x[MAX_N], y[MAX_N], r[MAX_N];

double sqr(double a) {
 	return a * a;
}

struct Pnt{
    dbl x,y;
    Pnt():x(0),y(0){}
    Pnt(dbl _x,dbl _y):x(_x),y(_y){}

    inline Pnt operator +(const Pnt &B) const{ return Pnt(x+B.x, y+B.y); }
    inline Pnt operator -(const Pnt &B) const{ return Pnt(x-B.x, y-B.y); }
    inline dbl operator *(const Pnt &B) const{ return x*B.x + y*B.y; } // LL
    inline dbl operator %(const Pnt &B) const{ return x*B.y - y*B.x; } // LL

    inline Pnt operator *(dbl k) const{ return Pnt(x*k, y*k); }
    inline Pnt operator /(dbl k) const{ return Pnt(x/k, y/k); }
    inline Pnt operator -() const{ return Pnt(-x, -y); }

    inline void operator +=(const Pnt &B){ x+=B.x, y+=B.y; }
    inline void operator -=(const Pnt &B){ x-=B.x, y-=B.y; }
    inline void operator *=(dbl k){ x*=k, y*=k; }

    inline bool operator ==(const Pnt &B){ return abs(x-B.x)<=EPS && abs(y-B.y)<=EPS; }
    inline bool operator !=(const Pnt &B){ return abs(x-B.x)>EPS || abs(y-B.y)>EPS; }
    inline bool operator <(const Pnt &B){ return abs(x-B.x)<=EPS ? y<B.y-EPS : x<B.x; }

    inline dbl angle() const{ return atan2(y, x); } // LD
    inline dbl len2() const{ return x*x+y*y; } // LL
    inline dbl len() const{ return sqrt(x*x+y*y); } // LL, LD
    inline Pnt getNorm() const{
        auto l = len();
        return Pnt(x/l, y/l);
    }
    inline void normalize(){
        auto l = len();
        x/=l, y/=l;
    }

    inline Pnt getRot90() const{ //counter-clockwise
        return Pnt(-y, x);
    }
    inline Pnt getRot(dbl a) const{ // LD
        dbl si = sin(a), co = cos(a);
        return Pnt(x*co - y*si, x*si + y*co);
    }

    inline void read(){
        int _x,_y;
        scanf("%d%d",&_x,&_y);
        x=_x, y=_y;
    }
};

vector<Pnt> v;

struct Line{
    dbl a, b, c;
    Line():a(0),b(0),c(0){}
    Line(Pnt p, dbl _c):a(p.x),b(p.y),c(_c){}
    Line(dbl _a, dbl _b, dbl _c):a(_a),b(_b),c(_c){}

    Line(const Pnt &A, const Pnt &B){ // it normalizes (a,b), important in d(), normalToP()
        Pnt n = (B-A).getRot90().getNorm();
        a = n.x, b = n.y, c = -(a*A.x + b*A.y);
    }

    inline dbl d(const Pnt &p) const{ return (a*p.x + b*p.y + c) / sqrt(a * a + b * b); }
    inline Pnt no() const {return Pnt(a, b);}
    inline Pnt normalToP(const Pnt &p) const{ return Pnt(a,b) * (a*p.x + b*p.y + c); }

};

struct Circle {
  	Pnt p;
  	double r;
  	Circle(): r(0) {}
  	Circle(double x, double y, double r): p(Pnt(x, y)), r(r) {}
};

Line line[2];
Circle circle[2];
int type[2];

// Intersection of two lines
int line_line(const Line &l, const Line &m){
    dbl z = m.a * l.b - l.a * m.b,
            x = m.c * l.b - l.c * m.b,
            y = m.c * l.a - l.c * m.a;
    if(fabs(z) > EPS){
        v.pb(Pnt(-x/z, y/z));
        return 1;
    }else if(fabs(x) > EPS || fabs(y) > EPS)
        return 0; // parallel lines
    else
        return 2; // same lines
}

// Intersection of Circle and line
void circle_line(const Circle &c, const Line &l){
	Line l2 = l;
	double q = sqrt(l.a * l.a + l.b * l.b);
	l2.a /= q, l2.b /= q, l2.c /= q;
    dbl d = l2.d(c.p);
    if(fabs(d) > c.r + EPS)
        return;
    if(fabs(fabs(d) / c.r - 1) < EPS)
        v.pb(c.p - l2.no() * d);
    else{
        dbl s = sqrt(fabs(sqr(c.r) - sqr(d)));
        v.pb(c.p - l2.no() * d + l2.no().getRot90() * s);
        v.pb(c.p - l2.no() * d - l2.no().getRot90() * s);
    }
}

// Intersection of two circles
void circle_circle(const Circle &a, const Circle &b){
    circle_line(a, Line((b.p - a.p) * 2, a.p.len2() - b.p.len2() + sqr(b.r) - sqr(a.r)));
}


void print() {
	double maxx = 0;
	Pnt ans;
 	for (auto &p : v) {
 	 	double d = r[0] / sqrt((p.x - x[0]) * (p.x - x[0]) + (p.y - y[0]) * (p.y - y[0]));
 	 	if (d > maxx) 
 	 		maxx = d, ans = p;
 	}
 	if (maxx > 0)
	 	printf("%.20f %.20f\n", ans.x, ans.y);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	forn (i, 3)
		scanf("%d%d%d", &x[i], &y[i], &r[i]);
	forab (i, 1, 3) {
		int k = sqr(r[i]) - sqr(r[0]);
		ll a = 2 * (sqr(r[0]) * x[i] - sqr(r[i]) * x[0]);
		ll b = 2 * (sqr(r[0]) * y[i] - sqr(r[i]) * y[0]);
		ll c = sqr(r[i]) * sqr(x[0]) + sqr(r[i]) * sqr(y[0]) - sqr(r[0]) * sqr(x[i]) - sqr(r[0]) * sqr(y[i]);
		if (k == 0) {
			type[i - 1] = 0;
			line[i - 1] = Line(a, b, c); 	
		} else {
		 	double a0 = a * 1. / k;
		 	double b0 = b * 1. / k;
		 	double c0 = c * 1. / k;
		 	double sqR = (a0 * a0 + b0 * b0) / 4 - c0;
		 	type[i - 1] = 1;
		 	assert(sqR > 0);
		 	circle[i - 1] = Circle(-a0 / 2, -b0 / 2, sqrt(sqR));
		}
	}
	if (type[0] == 0 && type[1] == 0) 
		line_line(line[0], line[1]);
	if (type[0] == 0 && type[1] == 1) 
		circle_line(circle[1], line[0]);
    if (type[0] == 1 && type[1] == 0) 
		circle_line(circle[0], line[1]);
    if (type[0] == 1 && type[1] == 1) 
		circle_circle(circle[0], circle[1]);
    print();
	return 0;
}