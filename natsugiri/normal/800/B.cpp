#include<complex>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

typedef double Double;
const Double EPS = 1e-8; // 0 ~~ [-EPS, EPS]
// const LL EPS = 0;
const Double INF = 1e12;
const Double PI = acos((Double)-1);

typedef complex<Double> Point;

// abs(P a) ::= sqrt(a.x^2 + a.y^2);
// norm(P a) ::= a.x^2 + a.y^2;
// Point polar(rho, theta=0)

const Point I(0, 1);

inline Double sq(Double x) { return x * x; }

inline int sgn(Double x) {
    if (x < -EPS) return -1;
    if (EPS < x) return 1;
    return 0;
}

namespace std {
    bool operator<(const Point &x, const Point &y) {
	return x.real() != y.real()? x.real() < y.real(): x.imag() < y.imag();
    }
};

inline int cmp(Double x, Double y) {
    return sgn(x - y);
}

Double cross(const Point &x, const Point &y) {
    return (conj(x)*y).imag();
}

Double dot(const Point &x, const Point &y) {
    return (conj(x)*y).real();
}

Point unitVector(const Point &a) { return a / abs(a); }


struct Line {
    Point p[2];

    Line() {}
    Line(const Line &l) {
	p[0] = l[0]; p[1] = l[1];
    }
    Line(const Point &a, const Point &b) {
	p[0] = a; p[1] = b;
    }

    Point& operator[](int i) { return p[i]; }

    const Point& operator[](int i) const { return p[i]; }
};

Point unitVectorL(const Line &l) { return unitVector(l[1] - l[0]); }
Point projection(const Line &l, const Point &p) {
    Double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
    return l[0]+t*(l[0]-l[1]);
}

Double distanceLP(const Line &l, const Point &p) {
    return abs(projection(l, p) - p);
}


int N;

Point P[1011];

void MAIN() {
    scanf("%d", &N);
    REP (i_, N) {
	int i = N-1-i_; // CCW;
	int x, y;
	scanf("%d%d", &x, &y);
	P[i] = Point(x, y);
    }

    P[N] = P[0];
    P[N+1] = P[1];
    double ans = abs(P[0] - P[1]) / 2;
    for (int v=1; v<=N; v++) {
	int l = v-1, r = v+1;
	amin(ans, abs(P[v] - P[l]) / 2);
	amin(ans, distanceLP(Line(P[l], P[r]), P[v]) / 2);
    }

    printf("%.9f\n", ans);

}




int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}