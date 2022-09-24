#include<cassert>
#include<map>
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

// normal line
Point normal(const Line &l) { return unitVector((l[1] - l[0]) * I); }

Double area2(const vector<Point> &g) {
    Double r = 0;
    for (int len=g.size(), i=0, j=len-1; i<len; j=i, i++)
	r += cross(g[j], g[i]);
    return abs(r); // When clockwise symple polygon, r < 0;
}

// Iter = Point*; or vector<Point>::iterator;
template<class Iter> void sortByArg(Iter begin, Iter end) {
    int n = end - begin;
    vector<pair<Double, Point> > v; v.reserve(n);
    for (Iter it=begin; it!=end; it++) v.push_back(make_pair(arg(*it), *it));
    sort(v.begin(), v.end());
    for (int i=0; i<n; i++) *(begin + i) = v[i].second;
}

struct ByArgLL {
    static inline int sgn(LL x) {
	if (x < 0) return -1;
	else if (0 < x) return 1;
	else return 0;
    }

    static int getA(const complex<LL> &a) {
	if (a.imag() < 0) {
	    return sgn(a.real()) + 1; // 0 1 2
	} else if (a.imag() > 0) {
	    return 5 - sgn(a.real()); // 4 5 6
	} else {
	    return a.real() >= 0 ? 3 : 7;
	}
    }

    bool operator()(const complex<LL> &a, const complex<LL> &b) const {
	if (getA(a) != getA(b)) return getA(a) < getA(b);
	// return cross(a, b) > 0;
	return a.imag() * b.real() < b.imag() * a.real();
    }
} byArgLL;

string toStr(Double x) {
    static char buf[60];
    sprintf(buf, "%.6f", x);
    return buf;
}

string toStr(const Point &p) {
    return string("(") + toStr(p.real()) + ", " + toStr(p.imag()) + ")";
}

string toStr(const Line &l) {
    return string("(") + toStr(l[0]) + " -- " + toStr(l[1]) + ")";
}

bool paralell(const Line &l, const Line &m) {
    return cmp(cross(l[1] - l[0], m[1] - m[0]), 0) == 0;
}

bool orthogonal(const Line &l, const Line &m) {
    return cmp(dot(l[1] - l[0], m[1] - m[0]), 0) == 0;
}

bool intersectLS(const Line &l, const Line &s) {
    return cmp(cross(l[1] - l[0], s[0] - l[0]) * cross(l[1] - l[0], s[1]-l[0]), 0) <= 0;
}

//bool intersectSS(const Line &s, const Line &t) {
//    return ccw(s[0],s[1],t[0]) * ccw(s[0],s[1],t[1]) <= 0
//	&& ccw(t[0],t[1],s[0]) * ccw(t[0],t[1],s[1]) <= 0;
//}

bool intersectSP(const Line &s, const Point &p) {
    return cmp(abs(s[0]-p)+abs(s[1]-p), abs(s[1]-s[0])) <= 0; // triangle inequality
}

//bool intersectLP(const Line &l, const Point &p) {
//    return abs(ccw(l[0], l[1], p)) != 1;
//}

Point crossPointLL(const Line &l, const Line &m) {
    Double A = cross(l[1] - l[0], m[1] - m[0]);
    Double B = cross(l[1] - l[0], l[1] - m[0]);
    if (cmp(abs(A), 0) <= 0 && cmp(abs(B), 0) <= 0) return m[0]; // Same line
    if (abs(A) < EPS) assert(false); // parallel
    return m[0] + B / A * (m[1] - m[0]);
}

int ccw(Point a, Point b, Point c) {
    b-=a; c-=a;
    if (cmp(cross(b, c), 0) > 0) return 1; // counter clockwise
    if (cmp(cross(b, c), 0) < 0) return -1; // clockwise
    if (cmp(dot(b, c), 0) < 0) return 2; // c--a--b on line
    if (cmp(abs(b), abs(c)) < 0) return -2; // a--b--c on line
    return 0; // a--c--b or b == c
}
bool onLine(const Line &s, const Point &p) {
    return cmp(abs(s[0] - p), 0.0) == 0 || cmp(abs(s[1] - p), 0.0) == 0 || ccw(s[0], p, s[1]) == -2;
}


int gcd(int x, int y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}
int N;
Line L[1011];
map<pair<int, int>, int> mp;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	L[i] = Line(Point(a, b), Point(c, d));
    }

    REP (i, N) REP (j, i) {
	if (paralell(L[i], L[j])) continue;
	Point p = crossPointLL(L[i], L[j]);

	int x = round(p.real());
	int y = round(p.imag());
	Point q(x, y);
	if (onLine(L[i], q) && onLine(L[j], q)) {
	    mp[make_pair(x, y)]++;
	}
    }

    LL ans = 0;
    REP (i, N) {
	const Line l = L[i];
	int x = abs(l[0].real() - l[1].real()) + 0.5;
	int y = abs(l[0].imag() - l[1].imag()) + 0.5;
	int g = gcd(x, y);
	ans += g + 1;
    }

    EACH (e, mp) {
	REP (t, 1001) if (t * (t-1)  == e->second * 2) {
	    ans -= t - 1;
	    break;
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}