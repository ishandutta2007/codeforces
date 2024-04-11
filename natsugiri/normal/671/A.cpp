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

//struct Point : complex<Double> {
//    typedef complex<Double> S;
//    int id;
//    Point() : S(), id(-1) {}
//    Point(Double x, Double y) : S(x, y), id(-1) {}
//    Point(Double x, Double y, int id_) : S(x, y), id(id_) {}
//    Point(const S &s) : S(s), id(-1) {}
//    Point(const Point &p) : S(p), id(p.id) {}
//};

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
int N;
Point A, B, S, P[100111];
Point readP() {
    int x, y;
    scanf("%d%d", &x, &y);
    return Point(x, y);
}

int main() {
    A = readP();
    B = readP();
    S = readP();
    A -= S;
    B -= S;
    scanf("%d", &N);
    REP (i, N) P[i] = readP() - S;

    vector<pair<double, int> > Ak, Bk;
    Ak.push_back(make_pair(0.0, -1));
    Bk.push_back(make_pair(0.0, -2));

    REP (i, N) {
	Ak.push_back(make_pair(abs(P[i] - A) - abs(P[i]), i));
	Bk.push_back(make_pair(abs(P[i] - B) - abs(P[i]), i));

	if (Ak.size() > 2u) {
	    sort(Ak.begin(), Ak.end()); Ak.pop_back();
	    sort(Bk.begin(), Bk.end()); Bk.pop_back();
	}
    }

    double sum = 0;
    REP (i, N) sum += 2.0 * abs(P[i]);

    double ans = 1e100;
    EACH (e, Ak) EACH (f, Bk)  {
	if (e->second != f->second && (e->second >= 0 || f->second >= 0)) {
	    double tmp = sum + e->first + f->first;
//	    eprintf("%d %d %f %f %f\n", e->second, f->second, e->first, f->first, tmp);
	    amin(ans, tmp);
	}
    }

    printf("%.9f\n", ans);


    return 0;
}