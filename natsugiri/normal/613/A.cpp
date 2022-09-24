#include<cassert>
#include<complex>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

double sq(double x) { return x*x; }
const double EPS = 1e-8; // 0 ~~ [-EPS, EPS]
// const LL EPS = 0;
const double INF = 1e12;
const double PI = acos(-1);

typedef double Double;
typedef complex<Double> Point;
const Point I(0, 1);

// abs(P a) ::= sqrt(a.x^2 + a.y^2);
// norm(P a) ::= a.x^2 + a.y^2;
// Point polar(rho, theta=0)

int sign(double x) {
    if (x < -EPS) return -1;
    if (EPS < x) return 1;
    return 0;
}

namespace std {
    bool operator<(const Point &x, const Point &y) {
	return real(x) != real(y)? real(x) < real(y): imag(x) < imag(y);
    }
}

Double cross(const Point &x, const Point &y) {
    return imag(conj(x)*y);
}
Double dot(const Point &x, const Point &y) {
    return real(conj(x)*y);
}
Point normal(const Point &a) { return a / abs(a); }
struct Line : public vector<Point> {
    Line(const Point &a, const Point &b) {
	push_back(a); push_back(b);
    }
    Point vector() const {
	return back() - front();
    }
};

typedef vector<Point> Polygon;
Double area2(const vector<Point> &g) {
    Double r = 0;
    for (int i=0; i<(int)g.size(); i++)
	r += cross(g[i], g[(i+1)%g.size()]);
    return abs(r);
}

int ccw(Point a, Point b, Point c) {
    b-=a; c-=a;
    if (cross(b, c) > EPS) return 1; // counter clockwise
    if (cross(b, c) < -EPS) return -1; // clockwise
    if (dot(b, c) < -EPS) return 2; // c--a--b on line
    if (norm(b) < norm(c)) return -2; // a--b--c on line
    return 0;
}

bool paralell(const Line &l, const Line &m) {
    return sign(cross(l.vector(), m.vector())) == 0;
}
bool orthogonal(const Line &l, const Line &m) {
    return sign(dot(l.vector(), m.vector())) == 0;
}
bool intersectLS(const Line &l, const Line &s) {
    return sign(cross(l.vector(), s[0]-l[0]) * cross(l.vector(), s[1]-l[0])) <= 0;
}
bool intersectSS(const Line &s, const Line &t) {
    return ccw(s[0],s[1],t[0]) * ccw(s[0],s[1],t[1]) <= 0
	&& ccw(t[0],t[1],s[0]) * ccw(t[0],t[1],s[1]) <= 0;
}
bool intersectSP(const Line &s, const Point &p) {
    return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}
bool intersectLP(const Line &l, const Point &p) {
    return abs(ccw(l[0], l[1], p)) != 1;
}
Point crossPoint(const Line &l, const Line &m) {
    double A = cross(l.vector(), m.vector());
    double B = cross(l.vector(), l[1]-m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0];
    if (abs(A) < EPS) assert(false);
    return m[0] + B / A * m.vector();
}

Point projection(const Line &l, const Point &p) {
    double t=dot(p-l[0], l[0]-l[1])/norm(l[0]-l[1]);
    return l[0]+t*(l[0]-l[1]);
}
Point reflection(const Line &l, const Point &p) {
    return p + 2.0 * (projection(l, p) - p);
}
double distanceLP(const Line &l, const Point &p) {
    return abs(projection(l, p) - p);
}
double distanceSP(const Line &s, const Point &p) {
    Point r=projection(s, p);
    if (intersectSP(s, r)) return abs(r-p);
    return min(abs(s[0]-p), abs(s[1]-p));
}
double distanceSS(const Line &s, const Line &t) {
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])), min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}


int N;
int x, y;
int main() {
    scanf("%d%d%d", &N, &x, &y);
    double mi = 1e12, ma = 0;
    Polygon P;
    REP (i, N) {
	int a, b;
	scanf("%d%d", &a, &b);
	P.push_back(Point(a-x, b-y));
	double d = abs(P.back());
	amax(ma, d);
	amin(mi, d);
    }
    if (N > 1) {
	REP (i, N) {
	    double d = distanceSP(Line(P[i], P[(i+1)%N]), Point(0, 0));
	    amax(ma, d);
	    amin(mi, d);
	}
    }

    printf("%.20f\n", (ma+mi)*(ma-mi)*PI);


    
    return 0;
}