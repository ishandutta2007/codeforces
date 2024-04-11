#include<complex>
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

typedef double Double;
const Double EPS = 1e-8; // 0 ~~ [-EPS, EPS]
// const LL EPS = 0;
const Double INF = 1e12;
const Double PI = acos((Double)-1);

typedef complex<Double> Point;
const Point I(0, 1);

// abs(P a) ::= sqrt(a.x^2 + a.y^2);
// norm(P a) ::= a.x^2 + a.y^2;
// Point polar(rho, theta=0)

int sign(Double x) {
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

void show(const Point &p) {
    printf("%.9f %.9f\n", p.real(), p.imag());
}

int main() {
    double px, py, vx, vy, a, b, c, d;
    scanf("%lf%lf %lf%lf %lf%lf%lf%lf", &px, &py, &vx, &vy, &a, &b, &c, &d);
    Point p(px, py);
    Point v(vx, vy);
    v = normal(v);

    show(p + v*b);
    show(p + v*polar(0.5, PI/2.0)*a);
    show(p + v*polar(0.5, PI/2.0)*c);
    show(p + v*polar(0.5, PI/2.0)*c - v*d);
    show(p - v*polar(0.5, PI/2.0)*c - v*d);
    show(p - v*polar(0.5, PI/2.0)*c);
    show(p - v*polar(0.5, PI/2.0)*a);
    
    return 0;
}