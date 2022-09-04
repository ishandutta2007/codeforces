#pragma region Macros
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define overload2(_1, _2, name, ...) name
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define mt make_tuple

#define fi first
#define se second
#define all(c) begin(c), end(c)
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
using namespace std;
constexpr pii dx4[4] = {pii{1, 0}, pii{0, 1}, pii{-1, 0}, pii{0, -1}};
constexpr pii dx8[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void yes(bool t = 1) { cout << yesno[t] << endl; }
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define si(c) (int)(c).size()
#define INT(...)                                                                                                                                               \
    int __VA_ARGS__;                                                                                                                                           \
    IN(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
    ll __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
#define STR(...)                                                                                                                                               \
    string __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define CHR(...)                                                                                                                                               \
    char __VA_ARGS__;                                                                                                                                          \
    IN(__VA_ARGS__)
#define DBL(...)                                                                                                                                               \
    double __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) {
    scan(head);
    IN(tail...);
}
template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
vi iota(int n) {
    vi a(n);
    iota(all(a), 0);
    return a;
}
template <typename T> vi iota(vector<T> &a, bool greater = false) {
    vi res(a.size());
    iota(all(res), 0);
    sort(all(res), [&](int i, int j) {
        if(greater) return a[i] > a[j];
        return a[i] < a[j];
    });
    return res;
}
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
template <class T> T POW(T x, int n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}
vector<pll> factor(ll x) {
    vector<pll> ans;
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0) {
            ans.push_back({i, 1});
            while((x /= i) % i == 0) ans.back().second++;
        }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
template <class T> vector<T> divisor(T x) {
    vector<T> ans;
    for(T i = 1; i * i <= x; i++)
        if(x % i == 0) {
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    return ans;
}
template <typename T> void zip(vector<T> &x) {
    vector<T> y = x;
    sort(all(y));
    for(int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); }
}
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
// int allbit(int n) { return (1 << n) - 1; }
ll allbit(ll n) { return (1LL << n) - 1; }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }

int in() {
    int x;
    cin >> x;
    return x;
}
ll lin() {
    unsigned long long x;
    cin >> x;
    return x;
}

template <class T> pair<T, T> operator-(const pair<T, T> &x, const pair<T, T> &y) { return pair<T, T>(x.fi - y.fi, x.se - y.se); }
template <class T> pair<T, T> operator+(const pair<T, T> &x, const pair<T, T> &y) { return pair<T, T>(x.fi + y.fi, x.se + y.se); }
template <class T> ll operator*(const pair<T, T> &x, const pair<T, T> &y) { return (ll)x.fi * y.fi + (ll)x.se * y.se; }

template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};
template <typename T> using Edges = vector<edge<T>>;

using Tree = vector<vector<int>>;
using Graph = vector<vector<int>>;
template <class T> using Wgraph = vector<vector<edge<T>>>;
Graph getG(int n, int m = -1, bool directed = false, int margin = 1) {
    Tree res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        cin >> a >> b;
        a -= margin, b -= margin;
        res[a].emplace_back(b);
        if(!directed) res[b].emplace_back(a);
    }
    return move(res);
}
template <class T> Wgraph<T> getWg(int n, int m = -1, bool directed = false, int margin = 1) {
    Wgraph<T> res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        T c;
        cin >> a >> b >> c;
        a -= margin, b -= margin;
        res[a].emplace_back(b, c);
        if(!directed) res[b].emplace_back(a, c);
    }
    return move(res);
}

#define i128 __int128_t
#define ull unsigned long long int
#define TEST                                                                                                                                                   \
    INT(testcases);                                                                                                                                            \
    while(testcases--)
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for(auto it = begin(v); it != end(v); ++it) {
        if(it == begin(v))
            os << *it;
        else
            os << " " << *it;
    }
    return os;
}
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) {
    os << p.first << " " << p.second;
    return os;
}
template <class S, class T> string to_string(pair<S, T> p) { return "(" + to_string(p.first) + "," + to_string(p.second) + ")"; }
template <class A> string to_string(A v) {
    if(v.empty()) return "{}";
    string ret = "{";
    for(auto &x : v) ret += to_string(x) + ",";
    ret.back() = '}';
    return ret;
}
string to_string(string s) { return "\"" + s + "\""; }

void dump() { cerr << endl; }
template <class Head, class... Tail> void dump(Head head, Tail... tail) {
    cerr << to_string(head) << " ";
    dump(tail...);
}
#define endl '\n'
#ifdef _LOCAL
#undef endl
#define debug(x)                                                                                                                                               \
    cout << #x << ": ";                                                                                                                                        \
    dump(x)
#else
#define debug(x)
#endif

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
#define drop(s) cout << #s << endl, exit(0)
#pragma endregion

using Real = double;
using Point = complex<Real>;
const Real EPS = 1e-8, PI = acos(-1);

inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }

Point operator*(const Point &p, const Real &d) { return Point(real(p) * d, imag(p) * d); }

istream &operator>>(istream &is, Point &p) {
    Real a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
}

ostream &operator<<(ostream &os, Point &p) { return os << fixed << setprecision(10) << p.real() << " " << p.imag(); }

//  p  theta 
Point rotate(Real theta, const Point &p) { return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag()); }

Real radian_to_degree(Real r) { return (r * 180.0 / PI); }

Real degree_to_radian(Real d) { return (d * PI / 180.0); }

// a-b-c 
Real get_angle(const Point &a, const Point &b, const Point &c) {
    const Point v(b - a), w(c - b);
    Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());
    if(alpha > beta) swap(alpha, beta);
    Real theta = (beta - alpha);
    return min(theta, 2 * acos(-1) - theta);
}

namespace std {
bool operator<(const Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }
} // namespace std

struct Line {
    Point a, b;

    Line() = default;

    Line(Point a, Point b) : a(a), b(b) {}

    Line(Real A, Real B, Real C) // Ax + By = C
    {
        if(eq(A, 0))
            a = Point(0, C / B), b = Point(1, C / B);
        else if(eq(B, 0))
            b = Point(C / A, 0), b = Point(C / A, 1);
        else
            a = Point(0, C / B), b = Point(C / A, 0);
    }

    friend ostream &operator<<(ostream &os, Line &p) { return os << p.a << " to " << p.b; }

    friend istream &operator>>(istream &is, Line &a) { return is >> a.a >> a.b; }
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

using Points = vector<Point>;
using Polygon = vector<Point>;
using Segments = vector<Segment>;
using Lines = vector<Line>;
using Circles = vector<Circle>;

Real cross(const Point &a, const Point &b) { return real(a) * imag(b) - imag(a) * real(b); }

Real dot(const Point &a, const Point &b) { return real(a) * real(b) + imag(a) * imag(b); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
// 
int ccw(const Point &a, Point b, Point c) {
    b = b - a, c = c - a;
    if(cross(b, c) > EPS) return +1;  // "COUNTER_CLOCKWISE"
    if(cross(b, c) < -EPS) return -1; // "CLOCKWISE"
    if(dot(b, c) < 0) return +2;      // "ONLINE_BACK"
    if(norm(b) < norm(c)) return -2;  // "ONLINE_FRONT"
    return 0;                         // "ON_SEGMENT"
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
// 
bool parallel(const Line &a, const Line &b) { return eq(cross(a.b - a.a, b.b - b.a), 0.0); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
// 
bool orthogonal(const Line &a, const Line &b) { return eq(dot(a.a - a.b, b.a - b.b), 0.0); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
// 
//  l  p 
Point projection(const Line &l, const Point &p) {
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}

Point projection(const Segment &l, const Point &p) {
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
// 
//  l  p  
Point reflection(const Line &l, const Point &p) { return p + (projection(l, p) - p) * 2.0; }

bool intersect(const Line &l, const Point &p) { return abs(ccw(l.a, l.b, p)) != 1; }

bool intersect(const Line &l, const Line &m) { return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS; }

bool intersect(const Segment &s, const Point &p) { return ccw(s.a, s.b, p) == 0; }

bool intersect(const Line &l, const Segment &s) { return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS; }

Real distance(const Line &l, const Point &p);

bool intersect(const Circle &c, const Line &l) { return distance(l, c.p) <= c.r + EPS; }

bool intersect(const Circle &c, const Point &p) { return abs(abs(p - c.p) - c.r) < EPS; }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
bool intersect(const Segment &s, const Segment &t) { return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0; }

int intersect(const Circle &c, const Segment &l) {
    if(norm(projection(l, c.p) - c.p) - c.r * c.r > EPS) return 0;
    auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);
    if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
    if(d1 < c.r - EPS && d2 > c.r + EPS || d1 > c.r + EPS && d2 < c.r - EPS) return 1;
    const Point h = projection(l, c.p);
    if(dot(l.a - h, l.b - h) < 0) return 2;
    return 0;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A&lang=jp
int intersect(Circle c1, Circle c2) {
    if(c1.r < c2.r) swap(c1, c2);
    Real d = abs(c1.p - c2.p);
    if(c1.r + c2.r < d) return 4;
    if(eq(c1.r + c2.r, d)) return 3;
    if(c1.r - c2.r < d) return 2;
    if(eq(c1.r - c2.r, d)) return 1;
    return 0;
}

Real distance(const Point &a, const Point &b) { return abs(a - b); }

Real distance(const Line &l, const Point &p) { return abs(p - projection(l, p)); }

Real distance(const Line &l, const Line &m) { return intersect(l, m) ? 0 : distance(l, m.a); }

Real distance(const Segment &s, const Point &p) {
    Point r = projection(s, p);
    if(intersect(s, r)) return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
Real distance(const Segment &a, const Segment &b) {
    if(intersect(a, b)) return 0;
    return min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}

Real distance(const Line &l, const Segment &s) {
    if(intersect(l, s)) return 0;
    return min(distance(l, s.a), distance(l, s.b));
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
pair<Point, Point> crosspoint(const Circle &c, const Line l) {
    Point pr = projection(l, c.p);
    Point e = (l.b - l.a) / abs(l.b - l.a);
    if(eq(distance(l, c.p), c.r)) return {pr, pr};
    double base = sqrt(c.r * c.r - norm(pr - c.p));
    return {pr - e * base, pr + e * base};
}

pair<Point, Point> crosspoint(const Circle &c, const Segment &l) {
    Line aa = Line(l.a, l.b);
    if(intersect(c, l) == 2) return crosspoint(c, aa);
    auto ret = crosspoint(c, aa);
    if(dot(l.a - ret.first, l.b - ret.first) < 0)
        ret.second = ret.first;
    else
        ret.first = ret.second;
    return ret;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
pair<Point, Point> crosspoint(const Circle &c1, const Circle &c2) {
    Real d = abs(c1.p - c2.p);
    Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
    Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
    Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
    return {p1, p2};
}
Real area(const Polygon &p) {
    Real A = 0;
    for(int i = 0; i < p.size(); ++i) { A += cross(p[i], p[(i + 1) % p.size()]); }
    return A * 0.5;
}
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
//  p  c 
pair<Point, Point> tangent(const Circle &c1, const Point &p2) { return crosspoint(c1, Circle(p2, sqrt(norm(c1.p - p2) - c1.r * c1.r))); }

namespace modular {
constexpr ll MOD = 1000000007;
const int MAXN = 1100000;
template <ll Modulus> class modint;
#define mint modint<MOD>
#define vmint vector<mint>
vector<mint> Inv;
mint inv(int x);
template <ll Modulus> class modint {

  public:
    static constexpr int mod() { return Modulus; }
    ll a;

    constexpr modint(const ll x = 0) noexcept : a(((x % Modulus) + Modulus) % Modulus) {}
    constexpr ll &value() noexcept { return a; }
    constexpr const ll &value() const noexcept { return a; }
    constexpr modint operator-() const noexcept { return modint() - *this; }
    constexpr modint operator+() const noexcept { return *this; }
    constexpr modint &operator++() noexcept {
        if(++a == MOD) a = 0;
        return *this;
    }
    constexpr modint &operator--() noexcept {
        if(!a) a = MOD;
        a--;
        return *this;
    }
    constexpr modint operator++(int) {
        modint res = *this;
        ++*this;
        return res;
    }
    constexpr modint operator--(int) {
        mint res = *this;
        --*this;
        return res;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if(a >= Modulus) { a -= Modulus; }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if(a < rhs.a) { a += Modulus; }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(const modint rhs) noexcept {
        a = a * (modular::inv(rhs.a)).a % Modulus;
        return *this;
    }
    constexpr modint pow(long long n) const noexcept {
        if(n < 0) {
            n %= Modulus - 1;
            n = (Modulus - 1) + n;
        }
        modint x = *this, r = 1;
        while(n) {
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    constexpr modint inv() const noexcept { return pow(Modulus - 2); }
    constexpr friend modint operator+(const modint &lhs, const modint &rhs) { return modint(lhs) += modint(rhs); }
    constexpr friend modint operator-(const modint &lhs, const modint &rhs) { return modint(lhs) -= modint(rhs); }
    constexpr friend modint operator*(const modint &lhs, const modint &rhs) { return modint(lhs) *= modint(rhs); }
    constexpr friend modint operator/(const modint &lhs, const modint &rhs) { return modint(lhs) /= modint(rhs); }
    constexpr friend modint operator==(const modint &lhs, const modint &rhs) { return lhs.a == rhs.a; }
    constexpr friend modint operator!=(const modint &lhs, const modint &rhs) { return lhs.a != rhs.a; }
    // constexpr friend modint operator^=(const modint &lhs, const modint &rhs) { return modint(lhs) ^= modint(rhs); }
};
vmint Fact{1, 1}, Ifact{1, 1};
mint inv(int n) {
    if(n > MAXN) return (mint(n)).pow(MOD - 2);
    if(Inv.empty()) Inv.emplace_back(0), Inv.emplace_back(1);
    if(Inv.size() > n)
        return Inv[n];
    else {
        for(int i = Inv.size(); i <= n; ++i) Inv.emplace_back(Inv[MOD % i] * (-MOD / i));
        return Inv[n];
    }
}
mint fact(int n) {
    if(Fact.size() > n)
        return Fact[n];
    else
        for(int i = Fact.size(); i <= n; ++i) Fact.emplace_back(Fact[i - 1] * i);
    return Fact[n];
}
mint ifact(int n) {
    if(Ifact.size() > n)
        return Ifact[n];
    else
        for(int i = Ifact.size(); i <= n; ++i) Ifact.emplace_back(Ifact[i - 1] * inv(i));
    return Ifact[n];
}
mint modpow(ll a, ll n) { return mint(a).pow(n); }
mint inv(mint a) { return inv(a.a); }
mint ifact(mint a) { return ifact(a.a); }
mint fact(mint a) { return fact(a.a); }
mint modpow(mint a, ll n) { return modpow(a.a, n); }
mint C(int a, int b) {
    if(a < 0 || b < 0) return 0;
    if(a < b) return 0;
    return fact(a) * ifact(b) * ifact(a - b);
}
mint P(int a, int b) {
    if(a < 0 || b < 0) return 0;
    if(a < b) return 0;
    return fact(a) * ifact(a - b);
}
ostream &operator<<(ostream &os, mint a) {
    os << a.a;
    return os;
}
istream &operator>>(istream &is, mint &a) {
    ll x;
    is >> x;
    a = x;
    return is;
}
struct modinfo {
    int mod, root;
};
constexpr modinfo base0{1045430273, 3};
constexpr modinfo base1{1051721729, 6};
constexpr modinfo base2{1053818881, 7};
using mint0 = modint<base0.mod>;
using mint1 = modint<base1.mod>;
using mint2 = modint<base2.mod>;
using Poly = vmint;
template <int mod> void FMT(vector<modint<mod>> &f, bool inv = false) {
    using V = vector<modint<mod>>;
    static V g(30), ig(30);
    if(g.front().a == 0) {
        modint<mod> root = 2;
        while((root.pow((mod - 1) / 2)).a == 1) root += 1;
        rep(i, 30) g[i] = -(root.pow((mod - 1) >> (i + 2))), ig[i] = g[i].inv();
    }
    int n = size(f);
    if(!inv) {
        for(int m = n; m >>= 1;) {
            modint<mod> w = 1;
            for(int s = 0, k = 0; s < n; s += 2 * m) {
                for(int i = s, j = s + m; i < s + m; ++i, ++j) {
                    auto x = f[i], y = f[j] * w;
                    if(x.a >= mod) x.a -= mod;
                    f[i].a = x.a + y.a, f[j].a = x.a + (mod - y.a);
                }
                w *= g[__builtin_ctz(++k)];
            }
        }
    } else {
        for(int m = 1; m < n; m *= 2) {
            modint<mod> w = 1;
            for(int s = 0, k = 0; s < n; s += 2 * m) {
                for(int i = s, j = s + m; i < s + m; ++i, ++j) {
                    auto x = f[i], y = f[j];
                    f[i] = x + y, f[j].a = x.a + (mod - y.a), f[j] *= w;
                }
                w *= ig[__builtin_ctz(++k)];
            }
        }
    }
    modint<mod> c;
    if(inv)
        c = modint<mod>(n).inv();
    else
        c = 1;
    for(auto &&e : f) e *= c;
}
Poly operator-(Poly f) {
    for(auto &&e : f) e = -e;
    return f;
}
Poly &operator+=(Poly &l, const Poly &r) {
    l.resize(max(l.size(), r.size()));
    rep(i, r.size()) l[i] += r[i];
    return l;
}
Poly operator+(Poly l, const Poly &r) { return l += r; }
Poly &operator-=(Poly &l, const Poly &r) {
    l.resize(max(l.size(), r.size()));
    rep(i, r.size()) l[i] -= r[i];
    return l;
}
Poly operator-(Poly l, const Poly &r) { return l -= r; }
Poly &operator<<=(Poly &f, size_t n) { return f.insert(f.begin(), n, 0), f; }
Poly operator<<(Poly f, size_t n) { return f <<= n; }
Poly &operator>>=(Poly &f, size_t n) { return f.erase(f.begin(), f.begin() + min(f.size(), n)), f; }
Poly operator>>(Poly f, size_t n) { return f >>= n; }

constexpr int mod0 = 998244353, mod1 = 1300234241, mod2 = 1484783617;
using M0 = modint<mod0>;
using M1 = modint<mod1>;
using M2 = modint<mod2>;

template <int mod> void mul(vector<modint<mod>> &l, vector<modint<mod>> &r) {
    int n = size(l), m = size(r), sz = 1 << __lg(2 * (n + m - 1) - 1);
    l.resize(sz), FMT<mod>(l);
    r.resize(sz), FMT<mod>(r);
    rep(i, sz) l[i] *= r[i];
    FMT<mod>(l, true);
    l.resize(n + m - 1);
}
Poly operator*(const Poly &l, const Poly &r) {
    if(l.empty() or r.empty()) return Poly();
    int n = size(l), m = size(r), sz = 1 << __lg(2 * (n + m - 1) - 1);
    vector<M0> l0(n), r0(m);
    vector<M1> l1(n), r1(m);
    vector<M2> l2(n), r2(m);
    rep(i, n) l0[i] = l[i].a, l1[i] = l[i].a, l2[i] = l[i].a;
    rep(i, m) r0[i] = r[i].a, r1[i] = r[i].a, r2[i] = r[i].a;
    mul<mod0>(l0, r0), mul<mod1>(l1, r1), mul<mod2>(l2, r2);
    Poly res(n + m - 1);
    // garner
    static constexpr M1 inv0 = 613999507;
    static constexpr M2 inv1 = 1147332803, inv0m1 = 45381342;
    static constexpr mint m0 = mod0, m0m1 = m0 * mod1;
    rep(i, n + m - 1) {
        int y0 = l0[i].a;
        int y1 = (inv0 * (l1[i] - y0)).a;
        int y2 = (inv0m1 * (l2[i] - y0) - inv1 * y1).a;
        res[i] = m0 * y1 + m0m1 * y2 + y0;
    }
    return res;
}
Poly &operator*=(Poly &l, const Poly &r) { return l = l * r; }
Poly integ(const Poly &f) {
    Poly res(f.size() + 1);
    for(int i = 1; i < (int)res.size(); ++i) res[i] = f[i - 1] / i;
    return res;
}
struct Prd {
    deque<Poly> deq;
    Prd() = default;
    void emplace(const Poly &f) { deq.emplace_back(f); }
    Poly calc() {
        if(deq.empty()) return {1};
        sort(all(deq), [&](const Poly &f, const Poly &g) { return si(f) < si(g); });
        while(deq.size() > 1) {
            deq.emplace_back(deq[0] * deq[1]);
            for(int i = 0; i < 2; ++i) deq.pop_front();
        }
        return deq.front();
    }
};
Poly prd(vector<Poly> &v) {
    Prd p;
    for(auto &e : v) p.emplace(e);
    return p.calc();
}
// Poly deriv(const Poly &f) {
//     if(f.size() == 0) return Poly();
//     Poly res(f.size() - 1);
//     rep(i, res.size()) res[i] = f[i + 1] * (i + 1);
//     return res;
// }
ostream &operator<<(ostream &os, const Poly &a) {
    for(auto e : a) cout << e.a << " ";
    return os;
}
} // namespace modular
using namespace modular;

pll operator-(pll x, pll y) { return pll(x.fi - y.fi, x.se - y.se); }
ll operator*(pll x, pll y) { return x.fi * y.se - x.se * y.fi; }
int main() {
    INT(n);
    Polygon P(n);
    vpll x(n);
    rep(i, n) {
        cin >> x[i].fi >> x[i].se;
        P[i] = Point(x[i].fi, x[i].se);
    }
    ll A = 0;
    rep(i, n) A += x[i] * x[(i + 1) % n];
    if(A < 0) { reverse(all(x)); }
    vvv(bool, vis, n + 1, n + 1, n + 1);
    vvv(mint, dp, n + 1, n + 1, n + 1);
    // dump(x);
    vv(ll, mem, n, n);
    rep(i, n) rep2(j, i + 1, n - 1) { rep2(k, i + 1, j) mem[i][j] += x[k - 1] * x[k]; }
    auto rec = [&](auto &&f, int st, int l, int r) -> mint {
        if(l == r) return 1;
        if(vis[st][l][r]) return dp[st][l][r];
        vis[st][l][r] = 1;
        mint &res = dp[st][l][r];
        ll A = 0;
        A += x[st] * x[l];
        A += mem[l][r];
        A += x[r] * x[st];
        // dump(st, l, r, A);
        if(A <= 0) return res = 0;
        rep2(i, l + 1, r - 1) {
            A = 0;
            A += x[st] * x[l] + x[l] * x[i] + x[i] * x[st];
            if(A > 0) res += f(f, l, l + 1, i) * f(f, st, i, r);
        }
        A = 0;
        A += x[st] * x[l] + x[l] * x[r] + x[r] * x[st];
        if(A > 0) res += f(f, l, l + 1, r);
        return res;
    };
    cout << rec(rec, 0, 1, n - 1) << endl;
}