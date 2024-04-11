#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

namespace GEOMETRY {

using Double = long double;
const Double EPS = 1e-8;
const Double INF = 1e20;
const Double PI = acos((Double)(-1));

int sgn(Double x) {
    return x < -EPS? -1: x > EPS? 1: 0;
}

int cmp(Double x, Double y) {
    return sgn(x-y);
}

Double sq(Double x) { return x*x; }

//////////////////////////////////////////////////
// Point
//////////////////////////////////////////////////
struct Point {
    Double x, y;

    Point(): x(), y() { }
    Point(const Double x_, const Double y_): x(x_), y(y_) { }

    double fx() const { return (double)x; }
    double fy() const { return (double)y; }
    Double& real() { return x; }
    Double& imag() { return y; }
    const Double& real() const { return x; }
    const Double& imag() const { return y; }

    Point& operator+=(const Point &o) { x += o.x; y += o.y; return *this; }

    Point& operator-=(const Point &o) { x -= o.x; y -= o.y; return *this; }

    Point& operator*=(const Point &o) {
	const Double tmp = x * o.x - y * o.y;
	y = x * o.y + y * o.x;
	x = tmp;
	return *this;
    }

    Point& operator/=(const Point &o) {
	const Double tmp = x * o.x + y * o.y;
	const Double n = sq(o.x) + sq(o.y);
	y = (y * o.x - x * o.y) / n;
	x = tmp / n;
	return *this;
    }

    Point& operator*=(Double o) { x *= o; y *= o; return *this; }

    Point& operator/=(Double o) { x /= o; y /= o; return *this; }
    
    Point operator+(const Point &b) const { return Point(*this) += b; }
    Point operator-(const Point &b) const { return Point(*this) -= b; }
    Point operator-() const { return Point(-x, -y); }
    Point operator*(const Point &b) const { return Point(*this) *= b; }
    Point operator/(const Point &b) const { return Point(*this) /= b; }

    Point operator*(Double b) const { return Point(*this) *= b; }
    friend Point operator*(Double a, const Point &b) { return Point(a * b.x, a * b.y); }
    Point operator/(Double b) const { return Point(*this) /= b; }

    // Strict comparison operators;
    bool operator==(const Point &b) const { return x == b.x && y == b.y; }
    bool operator!=(const Point &b) const { return !(*this == b); }

    bool operator<(const Point &b) const { return x < b.x || (x == b.x && y < b.y); }
    bool operator>(const Point &b) const { return b < (*this); }
    bool operator<=(const Point &b) const { return !(b < (*this)); }
    bool operator>=(const Point &b) const { return !((*this) < b); }

    string to_string() const {
	return string(1, '(') + ::to_string(x) + "," + ::to_string(y) + ")";
    }
}; // struct Point;

const Point ZERO(0.0, 0.0);
const Point REAL(1.0, 0.0);
const Point IMAG(0.0, 1.0);
const Point INF_INF(INF, INF);

string to_string(const Point &a) {
    return a.to_string();
}

Double norm(const Point &a) {
    return sq(a.x) + sq(a.y);
}

Double abs(const Point &a) {
    // std::hypot may slow;
    return sqrt(sq(a.x) + sq(a.y));
}

Point polar(Double rho, Double theta) {
    return Point(rho * cos(theta), rho * sin(theta));
}

Point conj(const Point &a) {
    return Point(a.x, -a.y);
}

Point rot(const Point &a, Double theta) {
    return a * Point(cos(theta), sin(theta));
}

Point rot90(const Point &a) {
    return Point(-a.y, a.x);
}

Point rot270(const Point &a) {
    return Point(a.y, -a.x);
}

Double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

Double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

// +1: CCW;
// -1: CW;
// 0: line;
int ccw_zero(const Point &b, const Point &c) {
    return sgn(cross(b, c));
}

int ccw(const Point &a, const Point &b, const Point &c) {
    return sgn(cross(b-a, c-a));
}

int ccw2(const Point &a, Point b, Point c) {
    b -= a; c -= a;
    int t = sgn(cross(b, c));
    if (t == 1) return 1; // CCW;
    if (t == -1) return -1; // CW;
    if (sgn(dot(b, c)) < 0) return 2; // ONLINE c--a--b;
    if (cmp(norm(b), norm(c)) < 0) return -2; // ONLINE a--b--c;
    return 0; // ONLINE a--c--b;
}

// return [0 .. PI];
Double angle(const Point &a, const Point &b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}

// arg(complex<double>);
// return [-PI .. PI];
Double angle2(const Point &a) {
    return atan2(a.y, a.x);
}

// from a to b;
Double angle2(const Point &a, const Point &b) {
    Double s = angle2(b) - angle2(a);
    if (s > PI) return s - 2.0 * PI;
    if (s < -PI) return s + 2.0 * PI;
    return s;
}

template<class Iter> void sort_by_angle(Iter ps, Iter ps_end) {
    int n = ps_end - ps;
    vector<pair<Double, Point> > h;
    h.reserve(n);
    REP (i, n) h.emplace_back(angle2(ps[i]), ps[i]);
    sort(h.begin(), h.end());
    REP (i, n) ps[i] = h[i].second;
}

template<class Iter> VI sort_index_by_angle(Iter ps, Iter ps_end) {
    int n = ps_end - ps;
    vector<pair<Double, Point> > h;
    h.reserve(n);
    REP (i, n) h.emplace_back(angle2(ps[i]), i);
    sort(h.begin(), h.end());
    VI ret(n);
    REP (i, n) ret[i] = h[i].second;
    return ret;
}

}; // namespace GEOMETRY;
namespace GEOMETRY {

//////////////////////////////////////////////////
// Line
//////////////////////////////////////////////////
struct Line {
    Point a, b;
    Line() {}
    Line(const Point &a_, const Point &b_): a(a_), b(b_) {}
    Point& operator[](int i) { return i==0? a: b; }
    Point vec() const { return b - a; }
    Point unitvec() const { return (b - a) / abs(b - a); }
};

string to_string(const Line &l) {
    return "Line(" + to_string(l.a) + "," + to_string(l.b) + ")";
}

// Projection p onto v;
Double projection_length(const Point &v, const Point &p) {
    return dot(p, v) / abs(v);
}

Point projection(const Point &v, const Point &p) {
    return dot(p, v) / norm(v) * v;
}

Point projection(const Line &l, const Point &p) {
    return l.a + projection(l.b - l.a, p - l.a);
}

bool is_parallel(const Line &l, const Line &m) {
    return sgn(cross(l.vec(), m.vec())) == 0;
}

bool is_orthogonal(const Line &l, const Line &m) {
    return sgn(dot(l.vec(), m.vec())) == 0;
}

bool equivalent_lines(const Line &l, const Line &m) {
    return is_parallel(l, m) && ccw(l.a, l.b, m.a) == 0;
}

// Has at least one point;
bool intersect_ll(const Line &l, const Line &m) {
    return !is_parallel(l, m) || ccw(l.a, l.b, m.a) == 0;
}

bool intersect_ls(const Line &l, const Line &s) {
    return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) != 1;
}

bool intersect_ss(const Line &s, const Line &t) {
    if (is_parallel(s, t)) {
	int c0 = ccw2(s.a, s.b, t.a);
	int c1 = ccw2(s.a, s.b, t.b);
	if (c0 == 0 || c1 == 0) return true;
	if (std::abs(c0) == 1 || std::abs(c1) == 1) return false;
	return c0 * c1 == -4;
    } else {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) != 1
	    && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) != 1;
    }
}

Point cross_point(const Line &l, const Line &m) {
    Double a = cross(l.vec(), m.vec());
    assert("l m must not parallel" && sgn(a) != 0);
    Double b = cross(l.vec(), l.b - m.a);
    return m.a + b / a * m.vec();
}

bool has_cross_point_ll(const Line &l, const Line &m) {
    return !is_parallel(l, m);
}

bool has_cross_point_ls(const Line &l, const Line &s) {
    return !is_parallel(l, s) && intersect_ls(l, s);
}

bool has_cross_point_ss(const Line &s, const Line &t, bool ensure_not_parallel=false) {
    return (ensure_not_parallel || !is_parallel(s, t)) && intersect_ss(s, t);
}

Double distance_lp(const Line &l, const Point &p) {
    return abs(projection(l, p) - p);
}

Double distance_sp(const Line &s, const Point &p) {
    Double t = projection_length(s.vec(), p - s.a);
    if (cmp(0.0, t) <= 0 && cmp(t, abs(s.vec())) <= 0) {
	return abs(s.unitvec() * t + s.a - p);
    } else {
	return min(abs(s.a - p), abs(s.b - p));
    }
}

Double distance_ls(const Line &l, const Line &s) {
    if (intersect_ls(l, s)) return 0.0;
    return min(distance_lp(l, s.a), distance_lp(l, s.b));
}

Double distance_ss(const Line &s, const Line &t) {
    if (intersect_ss(s, t)) return 0.0;
    return min({
	    distance_sp(s, t.a),
	    distance_sp(s, t.b),
	    distance_sp(t, s.a),
	    distance_sp(t, s.b),
	    });
}

}; // namespace GEOMETRY;

using namespace GEOMETRY;
int ccw(LL x1, LL y1, LL x2, LL y2) {
    LL tmp = x1 * y2 - x2 * y1;
    if (tmp > 0) return 1;
    if (tmp < 0) return -1;
    return 0;
}

LL sq(LL x) {
    return x * x;
}

int N;
LL X[200011], Y[200011];
LL H;
LL XH, YH;
LL XK, YK;


void MAIN() {
    scanf("%d%lld", &N, &H);
    REP (i, N) scanf("%lld%lld", X+i, Y+i);
    XH = X[N-1];
    YH = H + Y[N-1];
    REP (i, N) {
	X[i] -= XH;
	Y[i] -= YH;
    }

    XK = X[N-1];
    YK = Y[N-1];

    double ans = 0;
    for (int i=N-2; i>=0; i--) {
	int c1 = ccw(XK, YK, X[i], Y[i]);
	if (c1 == 1) {
	    // zero;
	} else {
	    int c2 = ccw(XK, YK, X[i+1], Y[i+1]);
	    if (c2 == 1) {
		Point p = cross_point(
			Line(Point(X[i], Y[i]), Point(X[i+1], Y[i+1])),
			Line(Point(0, 0), Point(XK, YK)));
		ans += abs(p - Point(X[i], Y[i]));

	    } else {
		// all;
		ans += sqrt(sq(X[i] - X[i+1]) + sq(Y[i] - Y[i+1]));
	    }
	}
	if (c1 == -1) {
	    XK = X[i];
	    YK = Y[i];
	}
    }
    printf("%.12f\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}