#line 1 "c.cpp"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <vector>

#line 1 "/Users/nok0/Documents/Programming/nok0/atcoder/dsu.hpp"



#line 7 "/Users/nok0/Documents/Programming/nok0/atcoder/dsu.hpp"

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder


#line 1 "/Users/nok0/Documents/Programming/nok0/cftemp.hpp"
#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
// rep macro
#define foa(v, a) for(auto &v : a)
#define REPname(a, b, c, d, e, ...) e
#define REP(...) REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define REP0(x) for(int i = 0; i < (x); ++i)
#define REP1(i, x) for(int i = 0; i < (x); ++i)
#define REP2(i, l, r) for(int i = (l); i < (r); ++i)
#define REP3(i, l, r, c) for(int i = (l); i < (r); i += (c))
#define REPSname(a, b, c, ...) c
#define REPS(...) REPSname(__VA_ARGS__, REPS1, REPS0)(__VA_ARGS__)
#define REPS0(x) for(int i = 1; i <= (x); ++i)
#define REPS1(i, x) for(int i = 1; i <= (x); ++i)
#define RREPname(a, b, c, d, e, ...) e
#define RREP(...) RREPname(__VA_ARGS__, RREP3, RREP2, RREP1, RREP0)(__VA_ARGS__)
#define RREP0(x) for(int i = (x)-1; i >= 0; --i)
#define RREP1(i, x) for(int i = (x)-1; i >= 0; --i)
#define RREP2(i, r, l) for(int i = (r)-1; i >= (l); --i)
#define RREP3(i, r, l, c) for(int i = (r)-1; i >= (l); i -= (c))
#define RREPSname(a, b, c, ...) c
#define RREPS(...) RREPSname(__VA_ARGS__, RREPS1, RREPS0)(__VA_ARGS__)
#define RREPS0(x) for(int i = (x); i >= 1; --i)
#define RREPS1(i, x) for(int i = (x); i >= 1; --i)

// name macro
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;

// input macro
template <class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
	for(T &i : v) is >> i;
	return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
	std::string s;
	is >> s;
	__int128_t ret = 0;
	for(int i = 0; i < s.length(); i++)
		if('0' <= s[i] and s[i] <= '9')
			ret = 10 * ret + s[i] - '0';
	a = ret * (s[0] == '-' ? -1 : 1);
	return is;
}
namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template <class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template <class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
}  // namespace scanner
#define VEC(type, name, size)     \
	std::vector<type> name(size); \
	scanner::INPUT(name)
#define VVEC(type, name, h, w)                                    \
	std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
	scanner::INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define STR(...)             \
	std::string __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
	double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)

// output-macro
template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
	for(int i = 0; i < int(a.size()); ++i) {
		if(i) os << " ";
		os << a[i];
	}
	return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
	std::ostream::sentry s(dest);
	if(s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while(tmp != 0);
		if(value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if(dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}
template <class T>
void print(const T a) { std::cout << a << '\n'; }
template <class Head, class... Tail>
void print(Head H, Tail... T) {
	std::cout << H << ' ';
	print(T...);
}
template <class T>
void printel(const T a) { std::cout << a << '\n'; }
template <class T>
void printel(const std::vector<T> &a) {
	for(const auto &v : a)
		std::cout << v << '\n';
}
template <class Head, class... Tail>
void printel(Head H, Tail... T) {
	std::cout << H << '\n';
	printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "NO\n"; }
void err(const bool b = true) {
	if(b) {
		std::cout << "-1\n", exit(0);
	}
}

//debug macro
namespace debugger {
template <class T>
void view(const std::vector<T> &a) {
	std::cerr << "{ ";
	for(const auto &v : a) {
		std::cerr << v << ", ";
	}
	std::cerr << "\b\b }";
}
template <class T>
void view(const std::vector<std::vector<T>> &a) {
	std::cerr << "{\n";
	for(const auto &v : a) {
		std::cerr << "\t";
		view(v);
		std::cerr << "\n";
	}
	std::cerr << "}";
}
template <class T, class U>
void view(const std::vector<std::pair<T, U>> &a) {
	std::cerr << "{\n";
	for(const auto &p : a) std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &p : m) std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::pair<T, U> &p) { std::cerr << "(" << p.first << ", " << p.second << ")"; }
template <class T>
void view(const std::set<T> &s) {
	std::cerr << "{ ";
	for(auto &v : s) {
		view(v);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <class T>
void view(const T &e) { std::cerr << e; }
}  // namespace debugger
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	debugger::view(H);
	std::cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                                \
	do {                                                          \
		std::cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(false)
#else
#define debug(...) (void(0))
#endif

// vector macro
template <class T>
int lb(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(), (x))); }
template <class T>
int ub(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(), (x))); }
template <class T>
void UNIQUE(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<T> press(std::vector<T> &a) {
	auto res = a;
	UNIQUE(res);
	for(auto &v : a)
		v = lb(res, v);
	return res;
}
#define SORTname(a, b, c, ...) c
#define SORT(...) SORTname(__VA_ARGS__, SORT1, SORT0, ...)(__VA_ARGS__)
#define SORT0(a) std::sort((a).begin(), (a).end())
#define SORT1(a, c) std::sort((a).begin(), (a).end(), [](const auto x, const auto y) { return x c y; })
template <class T>
void ADD(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v += x;
}
template <class T>
void SUB(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v -= x;
}
template <class T>
void MUL(std::vector<T> &a, const T x) {
	for(auto &v : a) v *= x;
}
template <class T>
void DIV(std::vector<T> &a, const T x) {
	for(auto &v : a) v /= x;
}
std::vector<std::pair<char, int>> rle(const string &s) {
	int n = s.size();
	std::vector<std::pair<char, int>> ret;
	for(int l = 0; l < n;) {
		int r = l + 1;
		for(; r < n and s[l] == s[r]; r++) {}
		ret.emplace_back(s[l], r - l);
		l = r;
	}
	return ret;
}
template <class T>
std::vector<std::pair<T, int>> rle(const std::vector<T> &v) {
	int n = v.size();
	std::vector<std::pair<T, int>> ret;
	for(int l = 0; l < n;) {
		int r = l + 1;
		for(; r < n and v[l] == v[r]; r++) {}
		ret.emplace_back(v[l], r - l);
		l = r;
	}
	return ret;
}

// math macro
template <class T, class U>
inline bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <class T, class U>
inline bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <class T>
T divup(T x, T y) { return (x + y - 1) / y; }
template <class T>
T POW(T a, long long n) {
	T ret = 1;
	while(n) {
		if(n & 1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}
// modpow
long long POW(long long a, long long n, const int mod) {
	long long ret = 1;
	a = (a % mod + mod) % mod;
	while(n) {
		if(n & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ret;
}

// others
struct fast_io {
	fast_io() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} fast_io_;
const int inf = 1e9;
const ll INF = 1e18;
#pragma endregion

void main_();

int main() {
	main_();
	return 0;
}
#line 2 "/Users/nok0/Documents/Programming/nok0/random/xorshift.hpp"

struct xorshift {
	using u32 = uint32_t;
	u32 x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	xorshift(u32 seed = 0) { z ^= seed; }
	u32 operator()() {
		u32 t = x ^ (x << 11);
		x = y;
		y = z;
		z = w;
		return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
	}
};
#line 12 "c.cpp"

#pragma region geometry

using Real = long double;
using R = Real;
using Point = std::complex<Real>;
using Vec = Point;
const Real EPS = 1e-10, PI = acos(-1);

inline bool eq(const Real &a, const Real &b) { return fabs(b - a) < EPS; }
inline bool eq(const Point &a, const Point &b) { return fabs(b - a) < EPS; }
/*
	-1: a < b
	0 : a == b
	1 : a > b
*/
inline int compare(const Real &a, const Real &b) { return eq(a, b) ? 0 : a < b ? -1 : 1; }

namespace std {
const Point operator*(const Point &p, const Real &d) { return Point(real(p) * d, imag(p) * d); }
}  // namespace std

std::istream &operator>>(std::istream &is, Point &p) {
	Real a, b;
	is >> a >> b;
	p = Point(a, b);
	return is;
}
std::ostream &operator<<(std::ostream &os, Point &p) { return os << std::fixed << std::setprecision(10) << p.real() << " " << p.imag(); }

// rotate point 'p' for counter clockwise direction
const Point rotate(const Real &theta, const Point &p) {
	return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag());
}

const Real radian_to_degree(const Real &r) { return (r * 180.0 / PI); }

const Real degree_to_radian(const Real &d) { return (d * PI / 180.0); }

// get angle a-b-c (<pi)
const Real get_angle(const Point &a, const Point &b, const Point &c) {
	const Point v(a - b), w(c - b);
	Real theta = fabs(atan2(w.imag(), w.real()) - atan2(v.imag(), v.real()));
	return std::min(theta, 2 * PI - theta);
}

namespace std {
bool operator<(const Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }
}  // namespace std

struct Line {
	Point a, b;

	Line() = default;

	Line(Point a, Point b) : a(a), b(b) {}

	Line(Real A, Real B, Real C)  // Ax + By = C
	{
		if(eq(A, 0))
			a = Point(0, C / B), b = Point(1, C / B);
		else if(eq(B, 0))
			b = Point(C / A, 0), b = Point(C / A, 1);
		else
			a = Point(0, C / B), b = Point(C / A, 0);
	}

	friend std::ostream &operator<<(std::ostream &os, Line &p) { return os << p.a << " -- " << p.b; }

	friend std::istream &operator>>(std::istream &is, Line &a) { return is >> a.a >> a.b; }
};

struct Segment : Line {
	Segment() = default;

	Segment(Point a, Point b) : Line(a, b) {}
};

struct Circle {
	Point p;
	Real r;

	Circle() = default;

	Circle(Point p, Real r) : p(p), r(r) {}
};

using Points = std::vector<Point>;
using Polygon = std::vector<Point>;
using Segments = std::vector<Segment>;
using Lines = std::vector<Line>;
using Circles = std::vector<Circle>;

const Real cross(const Point &a, const Point &b) { return real(a) * imag(b) - imag(a) * real(b); }
const Real dot(const Point &a, const Point &b) { return real(a) * real(b) + imag(a) * imag(b); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
const int ccw(const Point &a, Point b, Point c) {
	b = b - a, c = c - a;
	if(cross(b, c) > EPS) return +1;        // "COUNTER_CLOCKWISE"
	if(cross(b, c) < -EPS) return -1;       // "CLOCKWISE"
	if(dot(b, c) < -EPS) return +2;         // "ONLINE_BACK"
	if(norm(b) + EPS < norm(c)) return -2;  // "ONLINE_FRONT"
	return 0;                               // "ON_SEGMENT"
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
bool parallel(const Line &a, const Line &b) { return eq(cross(a.b - a.a, b.b - b.a), 0.0); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
bool orthogonal(const Line &a, const Line &b) { return eq(dot(a.a - a.b, b.a - b.b), 0.0); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
Point projection(const Line &l, const Point &p) {
	double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + (l.a - l.b) * t;
}

Point projection(const Segment &l, const Point &p) {
	double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + (l.a - l.b) * t;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
Point reflection(const Line &l, const Point &p) { return projection(l, p) * 2.0 - p; }

int intersect(const Line &l, const Point &p) { return int(abs(ccw(l.a, l.b, p)) != 1); }

int intersect(const Line &l, const Line &m) {
	if(intersect(l, m.a) && intersect(l, m.b)) return -1;
	return int(abs(cross(l.b - l.a, m.b - m.a)) > EPS);
}

int intersect(const Segment &s, const Point &p) { return int(ccw(s.a, s.b, p) == 0); }

int intersect(const Line &l, const Segment &s) {
	if(intersect(l, s.a) && intersect(l, s.b)) return -1;
	return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}

Real distance(const Line &l, const Point &p);

int intersect(const Circle &c, const Line &l) {
	Real d = c.r - distance(l, c.p);
	return fabs(d) < EPS ? 1 : d > 0. ? 2 : 0;
}

int intersect(const Circle &c, const Point &p) { return int(abs(abs(p - c.p) - c.r) < EPS); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
int intersect(const Segment &s, const Segment &t) {
	if(eq(s.a, s.b)) return intersect(t, s.a);
	if(intersect(Line(s), t.a) && intersect(Line(s), t.b) &&
	   std::max(std::min(s.a, s.b), std::min(t.a, t.b)) < std::min(std::max(s.a, s.b), std::max(t.a, t.b)))
		return -1;
	return int(ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0);
}

int intersect(const Circle &c, const Segment &l) {
	const Point h = projection(l, c.p);
	if(norm(h - c.p) - c.r * c.r > EPS) return 0;
	auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);
	if(compare(d1, c.r) == -1 && compare(d2, c.r) == -1) return 0;
	if(d1 < c.r - EPS && d2 > c.r - EPS || d1 > c.r - EPS && d2 < c.r - EPS) return 1;
	return dot(l.a - h, l.b - h) < 0 ? 2 : 0;
}

Real distance(const Point &a, const Point &b);

int number_of_common_tangents(const Circle &c1, const Circle &c2) {
	Real r1 = std::min(c1.r, c2.r), r2 = std::max(c1.r, c2.r), d = distance(c1.p, c2.p);
	int com = compare(r1 + r2, d);
	return com == 1 ? compare(d + r1, r2) + 1 : 3 - com;
	// if(c1.r < c2.r) swap(c1, c2);
	// Real d = abs(c1.p - c2.p);
	// if(compare(c1.r + c2.r, d) == -1) return 4;
	// if(eq(c1.r + c2.r, d)) return 3;
	// if(compare(c1.r - c2.r, d) == -1) return 2;
	// return int(eq(c1.r - c2.r, d));
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A&lang=jp
int intersect(const Circle &c1, const Circle &c2) { return 2 - abs(2 - number_of_common_tangents(c1, c2)); }

Real distance(const Point &a, const Point &b) { return abs(a - b); }

Real distance(const Line &l, const Point &p) { return abs(p - projection(l, p)); }

Real distance(const Line &l, const Line &m) { return intersect(l, m) ? 0 : distance(l, m.a); }

Real distance(const Segment &s, const Point &p) {
	Point r = projection(s, p);
	return intersect(s, r) ? distance(r, p) : std::min(abs(s.a - p), abs(s.b - p));
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
Real distance(const Segment &a, const Segment &b) {
	if(intersect(a, b)) return 0;
	return std::min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}

Real distance(const Line &l, const Segment &s) {
	if(intersect(l, s)) return 0;
	return std::min(distance(l, s.a), distance(l, s.b));
}

Point crosspoint(const Line &l, const Line &m) {
	Real A = cross(l.b - l.a, m.b - m.a);
	Real B = cross(l.b - l.a, l.b - m.a);
	if(eq(abs(A), 0.0) && eq(abs(B), 0.0)) return m.a;
	return m.a + (m.b - m.a) * B / A;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
Point crosspoint(const Segment &l, const Segment &m) { return crosspoint(Line(l), Line(m)); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
std::pair<Point, Point> crosspoint(const Circle &c, const Line l) {
	Point pr = projection(l, c.p);
	if(eq(distance(l, c.p), c.r)) return {pr, pr};
	Vec v = (l.b - l.a) / abs(l.b - l.a) * sqrt(c.r * c.r - norm(pr - c.p));
	return make_pair(pr - v, pr + v);
	// Vec e = (l.b - l.a) / abs(l.b - l.a);
	// double base = sqrt(c.r * c.r - norm(pr - c.p));
	// return {pr - e * base, pr + e * base};
}

std::pair<Point, Point> crosspoint(const Circle &c, const Segment &l) {
	if(intersect(c, l) == 2) return crosspoint(c, Line(l.a, l.b));
	auto ret = crosspoint(c, Line(l.a, l.b));
	if(dot(l.a - ret.first, l.b - ret.first) < EPS)
		ret.second = ret.first;
	else
		ret.first = ret.second;
	return ret;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
std::pair<Point, Point> crosspoint(const Circle &c1, const Circle &c2) {
	Real d = abs(c1.p - c2.p);
	Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));  // cosine theorem
	Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
	Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
	Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
	return make_pair(p1, p2);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
// " p  c "2
std::pair<Point, Point> tangent(const Circle &c1, const Point &p2) {
	return crosspoint(c1, Circle(p2, sqrt(norm(c1.p - p2) - c1.r * c1.r)));
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G
//  c1, c2 
Lines tangent(Circle c1, Circle c2) {
	Lines ret;
	if(c1.r < c2.r) std::swap(c1, c2);
	Real g = norm(c1.p - c2.p);
	if(eq(g, 0)) return ret;
	Vec u = (c2.p - c1.p) / Real(sqrt(g));
	Vec v = rotate(PI * 0.5, u);
	for(int s : {-1, 1}) {
		Real h = (c1.r + s * c2.r) / sqrt(g);
		if(eq(1 - h * h, 0)) {
			ret.emplace_back(c1.p + u * c1.r, c1.p + (u + v) * c1.r);
		} else if(1 - h * h > 0) {
			Point uu = u * h, vv = v * sqrt(1 - h * h);
			ret.emplace_back(c1.p + (uu + vv) * c1.r, c2.p - (uu + vv) * c2.r * s);
			ret.emplace_back(c1.p + (uu - vv) * c1.r, c2.p - (uu - vv) * c2.r * s);
		}
	}
	return ret;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
bool is_convex(const Polygon &p, bool pi_is_ok = false) {
	int n = p.size();
	if(pi_is_ok) {
		for(int i = 0; i < n; i++)
			if(ccw(p[i], p[(i + 1) % n], p[(i + 2) % n]) == -1) return false;
	} else {
		for(int i = 0; i < n; i++)
			if(ccw(p[i], p[(i + 1) % n], p[(i + 2) % n]) != 1) return false;
	}
	return true;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
Polygon convex_hull(Polygon &p, bool pi_is_ok = false) {
	int n = (int)p.size(), k = 0;
	if(n <= 2) return p;
	sort(p.begin(), p.end());
	Points ch(2 * n);
	if(pi_is_ok) {
		for(int i = 0; i < n; ch[k++] = p[i++])
			while(k >= 2 && ccw(ch[k - 2], ch[k - 1], p[i]) == -1) --k;
		for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--])
			while(k >= t && ccw(ch[k - 2], ch[k - 1], p[i]) == -1) --k;
	} else {
		for(int i = 0; i < n; ch[k++] = p[i++])
			while(k >= 2 && ccw(ch[k - 2], ch[k - 1], p[i]) != 1) --k;
		for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--])
			while(k >= t && ccw(ch[k - 2], ch[k - 1], p[i]) != 1) --k;
	}
	ch.resize(k - 1);
	return ch;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
enum { OUT,
	   ON,
	   IN };
int contains(const Polygon &Q, const Point &p) {
	bool in = false;
	const Real p_y = p.imag();
	for(int i = 0; i < Q.size(); i++) {
		Point a = Q[i], b = Q[(i + 1) % Q.size()];
		if(ccw(a, b, p) == 0) return ON;
		if(a.imag() > b.imag()) swap(a, b);
		if(a.imag() <= p_y && p_y < b.imag() && cross(a - p, b - p) < 0) in = !in;
	}
	return in ? IN : OUT;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1033
// 
void merge_segments(std::vector<Segment> &segs) {
	auto merge_if_able = [](Segment &s1, const Segment &s2) {
		if(abs(cross(s1.b - s1.a, s2.b - s2.a)) > EPS) return false;
		if(ccw(s1.a, s2.a, s1.b) == 1 || ccw(s1.a, s2.a, s1.b) == -1) return false;
		if(ccw(s1.a, s1.b, s2.a) == -2 || ccw(s2.a, s2.b, s1.a) == -2) return false;
		s1 = Segment(min(s1.a, s2.a), max(s1.b, s2.b));
		return true;
	};

	for(int i = 0; i < segs.size(); i++) {
		if(segs[i].b < segs[i].a) swap(segs[i].a, segs[i].b);
	}
	for(int i = 0; i < segs.size(); i++) {
		for(int j = i + 1; j < segs.size(); j++) {
			if(merge_if_able(segs[i], segs[j])) {
				segs[j--] = segs.back(), segs.pop_back();
			}
		}
	}
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1033
// 
// 2
std::vector<std::vector<int>> segment_arrangement(std::vector<Segment> &segs, std::vector<Point> &ps) {
	std::vector<std::vector<int>> g;
	int N = (int)segs.size();
	for(int i = 0; i < N; i++) {
		ps.emplace_back(segs[i].a);
		ps.emplace_back(segs[i].b);
		for(int j = i + 1; j < N; j++) {
			const Point p1 = segs[i].b - segs[i].a;
			const Point p2 = segs[j].b - segs[j].a;
			if(eq(cross(p1, p2), 0)) continue;  // " == 0" 
			if(intersect(segs[i], segs[j])) {
				ps.emplace_back(crosspoint(segs[i], segs[j]));
			}
		}
	}
	sort(begin(ps), end(ps));
	ps.erase(unique(begin(ps), end(ps)), end(ps));  // ?

	int M = (int)ps.size();
	g.resize(M);
	for(int i = 0; i < N; i++) {
		std::vector<int> vec;
		for(int j = 0; j < M; j++) {
			if(intersect(segs[i], ps[j])) {
				vec.emplace_back(j);
			}
		}
		for(int j = 1; j < vec.size(); j++) {
			g[vec[j - 1]].push_back(vec[j]);
			g[vec[j]].push_back(vec[j - 1]);
		}
	}
	return (g);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
// 
//  l.a-l.b 
Polygon convex_cut(const Polygon &U, Line l) {
	Polygon ret;
	for(int i = 0; i < U.size(); i++) {
		Point now = U[i], nxt = U[(i + 1) % U.size()];
		if(ccw(l.a, l.b, now) != -1) ret.push_back(now);
		if(ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) == -1) ret.push_back(crosspoint(Line(now, nxt), l));
	}
	return ret;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
// 
Real area(const Polygon &p) {
	Real A = 0;
	for(int i = 0; i < p.size(); ++i) {
		A += cross(p[i], p[(i + 1) % p.size()]);
	}
	return A * 0.5;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H
// 
Real area(const Polygon &p, const Circle &c) {
	if(p.size() < 3) return 0.0;
	auto cross_area = [&c](auto cross_area, const Point &a, const Point &b) -> Real {
		Point va = c.p - a, vb = c.p - b;
		Real f = cross(va, vb), ret = 0.0;
		if(eq(f, 0.0)) return ret;
		if(std::max(abs(va), abs(vb)) < c.r + EPS) return f;
		if(distance(Segment(a, b), c.p) > c.r - EPS) return c.r * c.r * arg(vb * conj(va));
		auto u = crosspoint(c, Segment(a, b));
		std::vector<Point> tot{a, u.first, u.second, b};
		for(int i = 0; i + 1 < tot.size(); i++) ret += cross_area(cross_area, tot[i], tot[i + 1]);
		return ret;
	};
	Real A = 0;
	for(int i = 0; i < p.size(); i++) {
		A += cross_area(cross_area, p[i], p[(i + 1) % p.size()]);
	}
	return A * 0.5;
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_I
Real area(const Circle &c1, const Circle &c2) {
	Real d = abs(c1.p - c2.p);
	if(c1.r + c2.r <= d + EPS) return 0.;
	if(abs(c1.r - c2.r) + EPS >= d) return pow(std::min(c1.r, c2.r), 2.) * PI;
	Real radius_diff = c1.r * c1.r - c2.r * c2.r;
	Real cosine_alpha = (d * d + radius_diff) / (2 * d * c1.r);
	Real cosine_beta = (d * d - radius_diff) / (2 * d * c2.r);
	return c1.r * c1.r * (acos(cosine_alpha) - cosine_alpha * sqrt(1 - cosine_alpha * cosine_alpha)) +
	       c2.r * c2.r * (acos(cosine_beta) - cosine_beta * sqrt(1 - cosine_beta * cosine_beta));
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
// ()
Real convex_diameter(const Polygon &p) {
	int N = (int)p.size();
	int is = 0, js = 0;
	for(int i = 1; i < N; i++) {
		if(p[i].imag() > p[is].imag()) is = i;
		if(p[i].imag() < p[js].imag()) js = i;
	}
	Real maxdis = norm(p[is] - p[js]);

	int maxi, maxj, i, j;
	i = maxi = is;
	j = maxj = js;
	do {
		if(cross(p[(i + 1) % N] - p[i], p[(j + 1) % N] - p[j]) >= 0) {
			j = (j + 1) % N;
		} else {
			i = (i + 1) % N;
		}
		if(norm(p[i] - p[j]) > maxdis) {
			maxdis = norm(p[i] - p[j]);
			maxi = i;
			maxj = j;
		}
	} while(i != is || j != js);
	return sqrt(maxdis);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
// 
Real closest_pair(Points ps) {
	if(ps.size() <= 1) throw(0);
	sort(begin(ps), end(ps));
	auto compare_y = [&](const Point &a, const Point &b) { return imag(a) < imag(b); };
	std::vector<Point> beet(ps.size());
	const Real INF = 1e18;
	auto rec = [&](auto rec, int left, int right) -> Real {
		if(right - left <= 1) return INF;
		int mid = (left + right) >> 1;
		auto x = real(ps[mid]);
		auto ret = std::min(rec(rec, left, mid), rec(rec, mid, right));
		inplace_merge(begin(ps) + left, begin(ps) + mid, begin(ps) + right, compare_y);
		int ptr = 0;
		for(int i = left; i < right; i++) {
			if(abs(real(ps[i]) - x) >= ret) continue;
			for(int j = 0; j < ptr; j++) {
				auto luz = ps[i] - beet[ptr - j - 1];
				if(imag(luz) >= ret) break;
				ret = std::min(ret, abs(luz));
			}
			beet[ptr++] = ps[i];
		}
		return ret;
	};
	return rec(rec, 0, (int)ps.size());
}

// (a):(b) = dist_a : dist_b ()
Circle Apollonius_Circle(Point a, Point b, Real dist_a, Real dist_b) {
	assert(!eq(dist_a, dist_b));  // bisection
	Real asq = dist_a * dist_a, bsq = dist_b * dist_b;
	Point p = (a * bsq - b * asq) * (1 / (bsq - asq));
	Real r = abs(a - b) * dist_a * dist_b / abs(asq - bsq);
	return Circle(p, r);
}

// bisection of angle A-B-C
// https://onlinejudge.u-aizu.ac.jp/status/users/Kite_kuma/submissions/1/CGL_7_B/judge/5763316/C++17
Line bisection_of_angle(const Point &a, const Point &b, const Point &c) {
	Real da = distance(a, b);
	Real dc = distance(b, c);
	return Line(b, (a * dc + c * da) / (da + dc));
}

// https://onlinejudge.u-aizu.ac.jp/status/users/Kite_kuma/submissions/1/CGL_7_B/judge/5763316/C++17
Circle incircle_of_triangle(const Point &a, const Point &b, const Point &c) {
	Point center = crosspoint(bisection_of_angle(a, b, c), bisection_of_angle(b, c, a));
	return Circle(center, distance(Line(a, b), center));
}
Circle incircle_of_triangle(const Polygon &p) { return incircle_of_triangle(p[0], p[1], p[2]); }

// https://onlinejudge.u-aizu.ac.jp/status/users/Kite_kuma/submissions/1/CGL_7_C/judge/5763330/C++17
Line bisection_of_points(const Point &a, const Point &b) {
	Point c = (a + b) * 0.5;
	return Line(c, c + rotate(PI / 2, b - a));
}

// https://onlinejudge.u-aizu.ac.jp/status/users/Kite_kuma/submissions/1/CGL_7_C/judge/5763330/C++17
Circle circumscribed_circle_of_triangle(const Point &a, const Point &b, const Point &c) {
	Point center = crosspoint(bisection_of_points(a, b), bisection_of_points(b, c));
	return Circle(center, distance(a, center));
}
Circle circumscribed_circle_of_triangle(const Polygon &p) { return circumscribed_circle_of_triangle(p[0], p[1], p[2]); }

#pragma endregion

xorshift rnd;
void main_() {
	INT(n);
	atcoder::dsu uf(n);
	V<Circle> c(n);
	Points center(3);
	V<Real> r(3);
	REP(i, n) {
		cin >> center[i] >> r[i];
		c[i] = Circle(center[i], r[i]);
	}
	V<Point> ps;
	REP(i, n) {
		REP(j, i + 1, n) {
			auto [u, v] = crosspoint(c[i], c[j]);
			int sz = intersect(c[i], c[j]);
			if(sz) uf.merge(i, j);
			if(sz) ps.pb(u);
			if(sz == 2) ps.pb(v);
		}
	}
	set<Point> st;
	REP(i, SZ(ps)) {
		bool ok = 1;
		REP(j, i + 1, SZ(ps)) {
			if(eq(ps[i], ps[j])) ok = 0;
		}
		if(ok) st.insert(ps[i]);
	}
	int V = SZ(st), E = 0;
	REP(i, n) {
		int cnt = 0;
		foa(v, st) {
			if(eq(distance(v, center[i]), r[i])) {
				cnt++;
			}
		}
		E += cnt;
	}
	debug(E, V);

	print(E - V + 1 + SZ(uf.groups()));
}