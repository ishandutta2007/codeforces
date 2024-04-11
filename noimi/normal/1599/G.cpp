#pragma region Macros
#pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")
// #pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
using ld = long double;
#define rep2(i, a, b) for(ll i = (a); i <= (b); i++)
#define rep3(i, a, b) for(ll i = (a); i >= (b); --i)
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define each(i, a) for(auto &&i : a)
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
#define VEC2(type, name1, name2, size)                                                                                                                         \
    vector<type> name1(size), name2(size);                                                                                                                     \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i])
#define VEC3(type, name1, name2, name3, size)                                                                                                                  \
    vector<type> name1(size), name2(size), name3(size);                                                                                                        \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i])
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
#define rall(c) rbegin(c), rend(c)
#define SORT(v) sort(all(v))
#define REV(v) reverse(all(v))
template <class T = ll, class S> T SUM(const S &v) { return accumulate(all(v), T(0)); }
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
using namespace std;
constexpr pii dx4[4] = {pii{1, 0}, pii{0, 1}, pii{-1, 0}, pii{0, -1}};
constexpr pii dx8[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
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
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
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

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x + y - 1) / y);
}
template <class T> T POW(T x, int n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}
template <class T, class S> T POW(T x, S n, const ll &mod) {
    T res = 1;
    for(; n; n >>= 1, x = x * x % mod)
        if(n & 1) res = res * x % mod;
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
    UNIQUE(y);
    for(int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); }
}
template <class S> void fold_in(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void fold_in(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto e : a) v.emplace_back(e);
    fold_in(v, tail...);
}
template <class S> void renumber(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void renumber(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto &&e : a) e = lb(v, e);
    renumber(v, tail...);
}
template <class S, class... Args> vector<S> zip(vector<S> &head, Args &&...args) {
    vector<S> v;
    fold_in(v, head, args...);
    sort(all(v)), v.erase(unique(all(v)), v.end());
    renumber(v, head, args...);
    return v;
}

// x in [l, r)
template <class T, class S> bool inc(const T &x, const S &l, const S &r) { return l <= x and x < r; }
// (a, b) in [lx, rx) * [ly, ry)
template <class T, class S> bool inc(const pair<T, T> &x, const S &lx, const S &ly, const S &rx, const S &ry) { return inc(x.fi, lx, rx) && inc(x.se, ly, ry); }

constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }
// bit 
ll pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
// int allbit(int n) { return (1 << n) - 1; }
ll allbit(ll n) { return (1LL << n) - 1; }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }

ll rnd(ll l, ll r) { //[l, r)
#ifdef _LOCAL
    static mt19937_64 gen;
#else
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
#endif
    return uniform_int_distribution<ll>(l, r - 1)(gen);
}
ll rnd(ll n) { return rnd(0, n); }

template <class t> void random_shuffle(vc<t> &a) { rep(i, si(a)) swap(a[i], a[rnd(0, i + 1)]); }

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

template <class T, class S> pair<T, S> operator-(const pair<T, S> &x, const pair<T, S> &y) { return pair<T, S>(x.fi - y.fi, x.se - y.se); }
template <class T, class S> pair<T, S> operator+(const pair<T, S> &x, const pair<T, S> &y) { return pair<T, S>(x.fi + y.fi, x.se + y.se); }
template <class T> pair<T, T> operator&(const pair<T, T> &l, const pair<T, T> &r) { return pair<T, T>(max(l.fi, r.fi), min(l.se, r.se)); }
template <class T, class S> pair<T, S> operator+=(pair<T, S> &l, const pair<T, S> &r) { return l = l + r; }
template <class T, class S> pair<T, S> operator-=(pair<T, S> &l, const pair<T, S> &r) { return l = l - r; }
template <class T> bool intersect(const pair<T, T> &l, const pair<T, T> &r) { return (l.se < r.se ? r.fi < l.se : l.fi < r.se); }

template <class T> ll operator*(const pair<T, T> &x, const pair<T, T> &y) { return (ll)x.fi * y.fi + (ll)x.se * y.se; }

template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    constexpr bool operator<(const edge<T> &rhs) const noexcept { return cost < rhs.cost; }
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
    return res;
}
Graph getTreeFromPar(int n, int margin = 1) {
    Graph res(n);
    for(int i = 1; i < n; i++) {
        int a;
        cin >> a;
        res[a - margin].emplace_back(i);
    }
    return res;
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
    return res;
}
void add(Graph &G, int x, int y) { G[x].eb(y), G[y].eb(x); }
template <class S, class T> void add(Wgraph<S> &G, int x, int y, T c) { G[x].eb(y, c), G[y].eb(x, c); }

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
string to_string(string s) { return "\"" + s + "\""; }
string to_string(char c) { return string(1, c); }
template <class T> string to_string(vector<T> s) {
    string res = "{";
    for(auto it = s.begin(); it != s.end(); it++) res += to_string(*it) + (next(it) == s.end() ? "" : ", ");
    return res + "}";
}
template <class T> string to_string(set<T> s) {
    string res = "{";
    for(auto it = s.begin(); it != s.end(); it++) res += to_string(*it), res += (next(it) == end(s) ? "" : ", ");
    return res + "}";
}

#define endl '\n'

#ifdef _LOCAL
void dump() { cerr << endl; }
template <class Head, class... Tail> void dump(Head head, Tail... tail) {
    cerr << to_string(head) << " ";
    dump(tail...);
}
#undef endl
#define debug(x)                                                                                                                                               \
    cout << #x << ": ";                                                                                                                                        \
    dump(x)
#else
void dump() {}
template <class Head, class... Tail> void dump(Head head, Tail... tail) {}
#define debug(x)
#endif
template <class T> void print(const T &a) { cout << a; }
void OUT() { cout << endl; }
template <class Head, class... Tail> void OUT(const Head &head, const Tail &...tail) {
    print(head);
    if(sizeof...(tail)) cout << ' ';
    OUT(tail...);
}

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
#define drop(s) cout << #s << endl, exit(0)

template <int N> struct ndFORarray {
    std::array<int, N> v;
    ndFORarray(std::array<int, N> v_) : v(v_) {}
    struct ndFORitr {
        const std::array<int, N> &v;
        std::array<int, N> tmp;
        bool is_end;
        ndFORitr(const std::array<int, N> &v_) : v(v_), tmp(), is_end(false) {}
        bool operator!=(const ndFORitr &) const { return !is_end; }
        void operator++() {
            int pos = N - 1;
            while(pos != -1) {
                tmp[pos] += 1;
                if(tmp[pos] == v[pos]) {
                    tmp[pos] = 0;
                    pos -= 1;
                } else {
                    break;
                }
            }
            if(pos == -1) { is_end = true; }
        }
        const std::array<int, N> &operator*() const { return tmp; }
    };
    ndFORitr begin() const { return ndFORitr(v); }
    ndFORitr end() const { return ndFORitr(v); }
};

struct ndFORvector {
    std::vector<int> v;
    ndFORvector(std::vector<int> v_) : v(v_) {}
    struct ndFORitr {
        const std::vector<int> &v;
        std::vector<int> tmp;
        bool is_end;
        ndFORitr(const std::vector<int> &v_) : v(v_), tmp(v.size(), 0), is_end(false) {}
        bool operator!=(const ndFORitr &) const { return !is_end; }
        void operator++() {
            int pos = v.size() - 1;
            while(pos != -1) {
                tmp[pos] += 1;
                if(tmp[pos] == v[pos]) {
                    tmp[pos] = 0;
                    pos -= 1;
                } else {
                    break;
                }
            }
            if(pos == -1) { is_end = true; }
        }
        const std::vector<int> &operator*() const { return tmp; }
    };
    ndFORitr begin() const { return ndFORitr(v); }
    ndFORitr end() const { return ndFORitr(v); }
};

auto ndFOR(std::vector<int> v) { return ndFORvector(v); }
template <class... Ts> auto ndFOR(Ts... v) { return ndFORarray<std::tuple_size<std::tuple<Ts...>>::value>({v...}); }
template <class F> struct REC {
    F f;
    REC(F &&f_) : f(std::forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, std::forward<Args>(args)...); }
};

template <class S> vector<pair<S, int>> runLength(const vector<S> &v) {
    vector<pair<S, int>> res;
    for(auto &e : v) {
        if(res.empty() or res.back().fi != e)
            res.eb(e, 1);
        else
            res.back().se++;
    }
    return res;
}
vector<pair<char, int>> runLength(const string &v) {
    vector<pair<char, int>> res;
    for(auto &e : v) {
        if(res.empty() or res.back().fi != e)
            res.eb(e, 1);
        else
            res.back().se++;
    }
    return res;
}

template <class T = int> struct Imos {
    int n;
    vector<T> a;
    Imos(int _n) : n(_n), a(_n + 1) {}
    void add(int l, int r, T val = 1) {
        if(l >= r) return;
        l = clamp(l, 0, n);
        r = clamp(r, 0, n + 1);
        a[l] += val;
        if(r <= n) a[r] -= val;
    }
    void build() {
        for(int i = 0; i < n; i++) a[i + 1] += a[i];
    }
    const T &operator[](int k) { return a[k]; }
};

template <class T> struct RUI {
    vector<T> a;
    RUI(const vector<T> &v) : a(v.size() + 1) {
        for(int i = 0; i < v.size(); i++) a[i + 1] = a[i] + v[i];
    }
    T get(int l, int r) { return a[r] - a[l]; }
};

template <class T, class F> T bin_search(T ok, T ng, const F &f) {
    while(abs(ok - ng) > 1) {
        T mid = ok + ng >> 1;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
#pragma endregion

namespace std {
bool operator<(const complex<double> &a, const complex<double> &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }
} // namespace std

namespace Geometry {
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

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
//  p  c 
pair<Point, Point> tangent(const Circle &c1, const Point &p2) { return crosspoint(c1, Circle(p2, sqrt(norm(c1.p - p2) - c1.r * c1.r))); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G
//  c1, c2 
Lines tangent(Circle c1, Circle c2) {
    Lines ret;
    if(c1.r < c2.r) swap(c1, c2);
    Real g = norm(c1.p - c2.p);
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

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
// 
bool is_convex(const Polygon &p) {
    int n = (int)p.size();
    for(int i = 0; i < n; i++) {
        if(ccw(p[(i + n - 1) % n], p[i], p[(i + 1) % n]) == -1) return false;
    }
    return true;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
// 
Polygon convex_hull(Polygon &p) {
    int n = (int)p.size(), k = 0;
    if(n <= 2) return p;
    sort(p.begin(), p.end());
    vector<Point> ch(2 * n);
    for(int i = 0; i < n; ch[k++] = p[i++]) {
        while(k >= 2 && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS) --k;
    }
    for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
        while(k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS) --k;
    }
    ch.resize(k - 1);
    return ch;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
// 
enum { OUTTT, ONNN, INNN };

int contains(const Polygon &Q, const Point &p) {
    bool in = false;
    for(int i = 0; i < Q.size(); i++) {
        Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;
        if(a.imag() > b.imag()) swap(a, b);
        if(a.imag() <= 0 && 0 < b.imag() && cross(a, b) < 0) in = !in;
        if(cross(a, b) == 0 && dot(a, b) <= 0) return ONNN;
    }
    return in ? INNN : OUTTT;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1033
// 
void merge_segments(vector<Segment> &segs) {

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
            if(merge_if_able(segs[i], segs[j])) { segs[j--] = segs.back(), segs.pop_back(); }
        }
    }
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1033
// 
// 2
vector<vector<int>> segment_arrangement(vector<Segment> &segs, vector<Point> &ps) {
    vector<vector<int>> g;
    int N = (int)segs.size();
    for(int i = 0; i < N; i++) {
        ps.emplace_back(segs[i].a);
        ps.emplace_back(segs[i].b);
        for(int j = i + 1; j < N; j++) {
            const Point p1 = segs[i].b - segs[i].a;
            const Point p2 = segs[j].b - segs[j].a;
            if(cross(p1, p2) == 0) continue;
            if(intersect(segs[i], segs[j])) { ps.emplace_back(crosspoint(segs[i], segs[j])); }
        }
    }
    sort(begin(ps), end(ps));
    ps.erase(unique(begin(ps), end(ps)), end(ps));

    int M = (int)ps.size();
    g.resize(M);
    for(int i = 0; i < N; i++) {
        vector<int> vec;
        for(int j = 0; j < M; j++) {
            if(intersect(segs[i], ps[j])) { vec.emplace_back(j); }
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
        if(ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) < 0) { ret.push_back(crosspoint(Line(now, nxt), l)); }
    }
    return (ret);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
// 
Real area(const Polygon &p) {
    Real A = 0;
    for(int i = 0; i < p.size(); ++i) { A += cross(p[i], p[(i + 1) % p.size()]); }
    return A * 0.5;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H
// 
Real area(const Polygon &p, const Circle &c) {
    if(p.size() < 3) return 0.0;
    function<Real(Circle, Point, Point)> cross_area = [&](const Circle &c, const Point &a, const Point &b) {
        Point va = c.p - a, vb = c.p - b;
        Real f = cross(va, vb), ret = 0.0;
        if(eq(f, 0.0)) return ret;
        if(max(abs(va), abs(vb)) < c.r + EPS) return f;
        if(distance(Segment(a, b), c.p) > c.r - EPS) return c.r * c.r * arg(vb * conj(va));
        auto u = crosspoint(c, Segment(a, b));
        vector<Point> tot{a, u.first, u.second, b};
        for(int i = 0; i + 1 < tot.size(); i++) { ret += cross_area(c, tot[i], tot[i + 1]); }
        return ret;
    };
    Real A = 0;
    for(int i = 0; i < p.size(); i++) { A += cross_area(c, p[i], p[(i + 1) % p.size()]); }
    return A;
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
    vector<Point> beet(ps.size());
    const Real INF = 1e18;

    function<Real(int, int)> rec = [&](int left, int right) {
        if(right - left <= 1) return INF;
        int mid = (left + right) >> 1;
        auto x = real(ps[mid]);
        auto ret = min(rec(left, mid), rec(mid, right));
        inplace_merge(begin(ps) + left, begin(ps) + mid, begin(ps) + right, compare_y);
        int ptr = 0;
        for(int i = left; i < right; i++) {
            if(abs(real(ps[i]) - x) >= ret) continue;
            for(int j = 0; j < ptr; j++) {
                auto luz = ps[i] - beet[ptr - j - 1];
                if(imag(luz) >= ret) break;
                ret = min(ret, abs(luz));
            }
            beet[ptr++] = ps[i];
        }
        return ret;
    };
    return rec(0, (int)ps.size());
}
} // namespace Geometry

using namespace Geometry;
int main() {
    INT(n, k);
    k--;
    VEC2(int, x, y, n);
    int A = x[k], B = y[k];
    {
        vpi v;
        rep(i, n) v.eb(x[i], y[i]);
        UNIQUE(v);
        n = si(v);
        rep(i, n) x[i] = v[i].fi, y[i] = v[i].se;
        x.resize(n), y.resize(n);
        rep(i, n) {
            if(A == x[i] and B == y[i]) k = i;
        }
    }
    Points P(n);
    rep(i, n) P[i] = Point(x[i], y[i]);
    if(n <= 16) {
        // if(false) {
        vv(double, dp, 1 << n, n, 1e12);
        dp[1 << k][k] = 0;
        rep(i, 1 << n) {
            rep(j, n) {
                if(~i & 1 << j or dp[i][j] > 1e10) continue;
                rep(s, n) {
                    if(~i & 1 << s) chmin(dp[i | 1 << s][s], dp[i][j] + hypot<double>(x[j] - x[s], y[j] - y[s]));
                }
            }
        }
        OUT(MIN(dp.back()));
    } else {
        int p, q;
        while(1) {
            int x = rnd(n), y = rnd(n), z = rnd(n);
            if(x == y or y == z or x == z) continue;
            if(abs(cross(Point(P[x] - P[y]), Point(P[x] - P[z]))) < EPS) {
                tie(p, q) = tie(x, y);
                break;
            }
        }

        vi d;
        int t = -1;
        rep(i, n) {
            if(i == p or i == q)
                d.eb(i);
            else if(abs(cross(P[p] - P[q], P[p] - P[i])) < EPS)
                d.eb(i);
            else {
                if(t != -1) exit(1);
                t = i;
            }
        }

        assert(t != -1);
        sort(all(d), [&](int xx, int yy) {
            if(x[xx] == x[yy]) return y[xx] < y[yy];
            return x[xx] < x[yy];
        });

        auto f = [&](int i, int j) { return abs(P[i] - P[j]); };

        if(t == k) {
            OUT(min(f(k, d[0]), f(k, d.back())) + f(d[0], d.back()));
        } else {
            int idx = -1;
            rep(i, si(d)) if(d[i] == k) idx = i;
            if(idx == -1) exit(1);

            double mi = f(d[0], k) + f(d[0], d.back()) + f(d.back(), t);
            chmin(mi, f(d.back(), k) + f(d.back(), d[0]) + f(d[0], t));

            double s = f(d[0], d.back());
            chmin(mi, f(k, t) + min(f(t, d[0]), f(t, d.back())) + s);

            rep(i, si(d) - 1) {
                // [0, i + 1)  [i + 1, si(d))
                double L;
                if(idx <= i) {
                    L = min(f(d[0], t) + f(k, d[i]) + f(d[i], d[0]), f(d[i], t) + f(k, d[0]) + f(d[0], d[i]));
                } else {
                    L = min(f(d[0], t), f(d[i], t)) + f(d[0], d[i]);
                }

                double R;
                if(idx > i) {
                    R = min(f(d[i + 1], t) + f(k, d.back()) + f(d[i + 1], d.back()), f(d.back(), t) + f(k, d[i + 1]) + f(d[i + 1], d.back()));
                } else {
                    R = min(f(d[i + 1], t), f(d.back(), t)) + f(d[i + 1], d.back());
                }

                chmin(mi, L + R);
            }
            OUT(mi);
        }
    }
}