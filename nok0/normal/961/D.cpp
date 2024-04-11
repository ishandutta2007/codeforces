/**
 *	author: nok0
 *	created: 2021.03.09 21:11:10
**/
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

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
#if __has_include(<atcoder/all>)
std::istream &operator>>(std::istream &is, atcoder::modint998244353 &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
std::istream &operator>>(std::istream &is, atcoder::modint1000000007 &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &operator>>(std::istream &is, atcoder::static_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &operator>>(std::istream &is, atcoder::dynamic_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
#endif
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
#if __has_include(<atcoder/all>)
std::ostream &operator<<(std::ostream &os, const atcoder::modint998244353 &a) { return os << a.val(); }
std::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007 &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::static_modint<m> &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::dynamic_modint<m> &a) { return os << a.val(); }
#endif
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
void ADD(std::vector<T> &a, const T x) {
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

#pragma region Math Geometry
using Real = long double;
using Point = std::complex<Real>;
const Real EPS = 1e-8, PI = acos(-1);

inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }

Point operator*(const Point &p, const Real &d) {
	return Point(real(p) * d, imag(p) * d);
}

std::istream &operator>>(std::istream &is, Point &p) {
	Real a, b;
	is >> a >> b;
	p = Point(a, b);
	return is;
}

std::ostream &operator<<(std::ostream &os, Point &p) {
	return os << std::fixed << std::setprecision(10) << p.real() << " " << p.imag();
}

//  p  theta 
Point rotate(Real theta, const Point &p) {
	return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag());
}

Real radian_to_degree(Real r) {
	return (r * 180.0 / PI);
}

Real degree_to_radian(Real d) {
	return (d * PI / 180.0);
}

// a-b-c 
Real get_angle(const Point &a, const Point &b, const Point &c) {
	const Point v(a - b), w(c - b);
	Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());
	if(alpha > beta) std::swap(alpha, beta);
	Real theta = (beta - alpha);
	return std::min(theta, 2 * acos(-1) - theta);
}

namespace std {
bool operator<(const Point &a, const Point &b) {
	return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
}
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

	friend std::ostream &operator<<(std::ostream &os, Line &p) {
		return os << p.a << " to " << p.b;
	}

	friend std::istream &operator>>(std::istream &is, Line &a) {
		return is >> a.a >> a.b;
	}
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

Real cross(const Point &a, const Point &b) {
	return real(a) * imag(b) - imag(a) * real(b);
}

Real dot(const Point &a, const Point &b) {
	return real(a) * real(b) + imag(a) * imag(b);
}

// 
int ccw(const Point &a, Point b, Point c) {
	b = b - a, c = c - a;
	if(cross(b, c) > EPS) return +1;            // "COUNTER_CLOCKWISE"
	if(cross(b, c) < -EPS) return -1;           // "CLOCKWISE"
	if(dot(b, c) < 0) return +2;                // "ONLINE_BACK"
	if(std::norm(b) < std::norm(c)) return -2;  // "ONLINE_FRONT"
	return 0;                                   // "ON_SEGMENT"
}

// 
bool parallel(const Line &a, const Line &b) {
	return eq(cross(a.b - a.a, b.b - b.a), 0.0);
}

// 
bool orthogonal(const Line &a, const Line &b) {
	return eq(dot(a.a - a.b, b.a - b.b), 0.0);
}

// 
//  l  p 
Point projection(const Line &l, const Point &p) {
	double t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);
	return l.a + (l.a - l.b) * t;
}

Point projection(const Segment &l, const Point &p) {
	double t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);
	return l.a + (l.a - l.b) * t;
}

// 
//  l  p  
Point reflection(const Line &l, const Point &p) {
	return p + (projection(l, p) - p) * 2.0;
}

bool intersect(const Line &l, const Point &p) {
	return std::abs(ccw(l.a, l.b, p)) != 1;
}

bool intersect(const Line &l, const Line &m) {
	return std::abs(cross(l.b - l.a, m.b - m.a)) > EPS or std::abs(cross(l.b - l.a, m.b - l.a)) < EPS;
}

bool intersect(const Segment &s, const Point &p) {
	return ccw(s.a, s.b, p) == 0;
}

bool intersect(const Line &l, const Segment &s) {
	return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}

Real distance(const Line &l, const Point &p);

bool intersect(const Circle &c, const Line &l) {
	return distance(l, c.p) <= c.r + EPS;
}

bool intersect(const Circle &c, const Point &p) {
	return std::abs(std::abs(p - c.p) - c.r) < EPS;
}

bool intersect(const Segment &s, const Segment &t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 and ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

int intersect(const Circle &c, const Segment &l) {
	if(std::norm(projection(l, c.p) - c.p) - c.r * c.r > EPS) return 0;
	auto d1 = std::abs(c.p - l.a), d2 = std::abs(c.p - l.b);
	if(d1 < c.r + EPS and d2 < c.r + EPS) return 0;
	if(d1 < c.r - EPS and d2 > c.r + EPS or d1 > c.r + EPS and d2 < c.r - EPS) return 1;
	const Point h = projection(l, c.p);
	if(dot(l.a - h, l.b - h) < 0) return 2;
	return 0;
}

int intersect(Circle c1, Circle c2) {
	if(c1.r < c2.r) std::swap(c1, c2);
	Real d = std::abs(c1.p - c2.p);
	if(c1.r + c2.r < d) return 4;
	if(eq(c1.r + c2.r, d)) return 3;
	if(c1.r - c2.r < d) return 2;
	if(eq(c1.r - c2.r, d)) return 1;
	return 0;
}

Real distance(const Point &a, const Point &b) {
	return std::abs(a - b);
}

Real distance(const Line &l, const Point &p) {
	return std::abs(p - projection(l, p));
}

Real distance(const Line &l, const Line &m) {
	return intersect(l, m) ? 0 : distance(l, m.a);
}

Real distance(const Segment &s, const Point &p) {
	Point r = projection(s, p);
	if(intersect(s, r)) return std::abs(r - p);
	return std::min(std::abs(s.a - p), std::abs(s.b - p));
}

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
	if(eq(std::abs(A), 0.0) and eq(std::abs(B), 0.0)) return m.a;
	return m.a + (m.b - m.a) * B / A;
}

Point crosspoint(const Segment &l, const Segment &m) {
	return crosspoint(Line(l), Line(m));
}

std::pair<Point, Point> crosspoint(const Circle &c, const Line l) {
	Point pr = projection(l, c.p);
	Point e = (l.b - l.a) / std::abs(l.b - l.a);
	if(eq(distance(l, c.p), c.r)) return {pr, pr};
	double base = sqrt(c.r * c.r - std::norm(pr - c.p));
	return {pr - e * base, pr + e * base};
}

std::pair<Point, Point> crosspoint(const Circle &c, const Segment &l) {
	Line aa = Line(l.a, l.b);
	if(intersect(c, l) == 2) return crosspoint(c, aa);
	auto ret = crosspoint(c, aa);
	if(dot(l.a - ret.first, l.b - ret.first) < 0)
		ret.second = ret.first;
	else
		ret.first = ret.second;
	return ret;
}

std::pair<Point, Point> crosspoint(const Circle &c1, const Circle &c2) {
	Real d = std::abs(c1.p - c2.p);
	Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
	Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
	Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
	Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
	return {p1, p2};
}

//  p  c 
std::pair<Point, Point> tangent(const Circle &c1, const Point &p2) {
	return crosspoint(c1, Circle(p2, sqrt(std::norm(c1.p - p2) - c1.r * c1.r)));
}

//  c1, c2 
Lines tangent(Circle c1, Circle c2) {
	Lines ret;
	if(c1.r < c2.r) std::swap(c1, c2);
	Real g = std::norm(c1.p - c2.p);
	if(eq(g, 0)) return ret;
	Point u = (c2.p - c1.p) / sqrt(g);
	Point v = rotate(PI * 0.5, u);
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

// 
bool is_convex(const Polygon &p) {
	int n = (int)p.size();
	for(int i = 0; i < n; i++) {
		if(ccw(p[(i + n - 1) % n], p[i], p[(i + 1) % n]) == -1) return false;
	}
	return true;
}

// 
Polygon convex_hull(Polygon &p) {
	int n = (int)p.size(), k = 0;
	if(n <= 2) return p;
	std::sort(p.begin(), p.end());
	std::vector<Point> ch(2 * n);
	for(int i = 0; i < n; ch[k++] = p[i++]) {
		while(k >= 2 and cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS) --k;
	}
	for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
		while(k >= t and cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS) --k;
	}
	ch.resize(k - 1);
	return ch;
}

// 
enum {
	OUT,
	ON,
	IN
};

int contains(const Polygon &Q, const Point &p) {
	bool in = false;
	for(int i = 0; i < Q.size(); i++) {
		Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;
		if(a.imag() > b.imag()) swap(a, b);
		if(a.imag() <= 0 and 0 < b.imag() and cross(a, b) < 0) in = !in;
		if(cross(a, b) == 0 and dot(a, b) <= 0) return ON;
	}
	return in ? IN : OUT;
}

// 
void merge_segments(std::vector<Segment> &segs) {
	auto merge_if_able = [](Segment &s1, const Segment &s2) {
		if(std::abs(cross(s1.b - s1.a, s2.b - s2.a)) > EPS) return false;
		if(ccw(s1.a, s2.a, s1.b) == 1 or ccw(s1.a, s2.a, s1.b) == -1) return false;
		if(ccw(s1.a, s1.b, s2.a) == -2 or ccw(s2.a, s2.b, s1.a) == -2) return false;
		s1 = Segment(std::min(s1.a, s2.a), std::max(s1.b, s2.b));
		return true;
	};

	for(int i = 0; i < segs.size(); i++) {
		if(segs[i].b < segs[i].a) std::swap(segs[i].a, segs[i].b);
	}
	for(int i = 0; i < segs.size(); i++) {
		for(int j = i + 1; j < segs.size(); j++) {
			if(merge_if_able(segs[i], segs[j])) {
				segs[j--] = segs.back(), segs.pop_back();
			}
		}
	}
}

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
			if(cross(p1, p2) == 0) continue;
			if(intersect(segs[i], segs[j])) {
				ps.emplace_back(crosspoint(segs[i], segs[j]));
			}
		}
	}
	std::sort(begin(ps), end(ps));
	ps.erase(std::unique(begin(ps), end(ps)), end(ps));

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

// 
//  l.a-l.b 
Polygon convex_cut(const Polygon &U, Line l) {
	Polygon ret;
	for(int i = 0; i < U.size(); i++) {
		Point now = U[i], nxt = U[(i + 1) % U.size()];
		if(ccw(l.a, l.b, now) != -1) ret.push_back(now);
		if(ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) < 0) {
			ret.push_back(crosspoint(Line(now, nxt), l));
		}
	}
	return (ret);
}

// 
Real area(const Polygon &p) {
	Real A = 0;
	for(int i = 0; i < p.size(); ++i) {
		A += cross(p[i], p[(i + 1) % p.size()]);
	}
	return A * 0.5;
}

// 
Real area(const Polygon &p, const Circle &c) {
	if(p.size() < 3) return 0.0;
	std::function<Real(Circle, Point, Point)> cross_area = [&](const Circle &c, const Point &a, const Point &b) {
		Point va = c.p - a, vb = c.p - b;
		Real f = cross(va, vb), ret = 0.0;
		if(eq(f, 0.0)) return ret;
		if(std::max(std::abs(va), std::abs(vb)) < c.r + EPS) return f;
		if(distance(Segment(a, b), c.p) > c.r - EPS) return c.r * c.r * arg(vb * conj(va));
		auto u = crosspoint(c, Segment(a, b));
		std::vector<Point> tot{a, u.first, u.second, b};
		for(int i = 0; i + 1 < tot.size(); i++) {
			ret += cross_area(c, tot[i], tot[i + 1]);
		}
		return ret;
	};
	Real A = 0;
	for(int i = 0; i < p.size(); i++) {
		A += cross_area(c, p[i], p[(i + 1) % p.size()]);
	}
	return A;
}

// ()
Real convex_diameter(const Polygon &p) {
	int N = (int)p.size();
	int is = 0, js = 0;
	for(int i = 1; i < N; i++) {
		if(p[i].imag() > p[is].imag()) is = i;
		if(p[i].imag() < p[js].imag()) js = i;
	}
	Real maxdis = std::norm(p[is] - p[js]);

	int maxi, maxj, i, j;
	i = maxi = is;
	j = maxj = js;
	do {
		if(cross(p[(i + 1) % N] - p[i], p[(j + 1) % N] - p[j]) >= 0) {
			j = (j + 1) % N;
		} else {
			i = (i + 1) % N;
		}
		if(std::norm(p[i] - p[j]) > maxdis) {
			maxdis = std::norm(p[i] - p[j]);
			maxi = i;
			maxj = j;
		}
	} while(i != is or j != js);
	return sqrt(maxdis);
}

// 
Real closest_pair(Points ps) {
	if(ps.size() <= 1) throw(0);
	std::sort(begin(ps), end(ps));

	auto compare_y = [&](const Point &a, const Point &b) {
		return imag(a) < imag(b);
	};
	std::vector<Point> beet(ps.size());
	const Real INF = 1e18;

	std::function<Real(int, int)> rec = [&](int left, int right) {
		if(right - left <= 1) return INF;
		int mid = (left + right) >> 1;
		auto x = real(ps[mid]);
		auto ret = std::min(rec(left, mid), rec(mid, right));
		inplace_merge(begin(ps) + left, begin(ps) + mid, begin(ps) + right, compare_y);
		int ptr = 0;
		for(int i = left; i < right; i++) {
			if(std::abs(real(ps[i]) - x) >= ret) continue;
			for(int j = 0; j < ptr; j++) {
				auto luz = ps[i] - beet[ptr - j - 1];
				if(imag(luz) >= ret) break;
				ret = std::min(ret, std::abs(luz));
			}
			beet[ptr++] = ps[i];
		}
		return ret;
	};
	return rec(0, (int)ps.size());
}
#pragma endregion

void main_() {
	INT(n);
	Points p(n);
	REP(i, n) { cin >> p[i]; }
	if(n <= 3) {
		YES();
		return;
	}
	bool ok = 0;
	REP(_, 3) {
		Line l;
		Point z, w;
		if(_ == 0) z = p[0], w = p[1];
		if(_ == 1) z = p[1], w = p[2];
		if(_ == 2) z = p[0], w = p[2];
		Points q;
		REP(i, n) {
			if(abs(ccw(z, w, p[i])) == 1)
				q.push_back(p[i]);
		}
		if(SZ(q) <= 2)
			ok = 1;
		else {
			auto x = q[0], y = q[1];
			bool f = 1;
			for(auto &v : q)
				if(abs(ccw(x, y, v)) == 1)
					f = 0;
			ok |= f;
		}
	}
	YES(ok);
}

int main() {
	int t = 1;
	//cin >> t;
	while(t--) main_();
	return 0;
}