#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
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
#define SUM(v) accumulate(all(v), 0LL)
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
// template <class T> pair<T, T> &operator+=(pair<T, T> x, const pair<T, T> &y) {
//     x = x + y;
//     return &x;
// }
// template <class T> pair<T, T> &operator-=(pair<T, T> x, const pair<T, T> &y) {
//     x = x - y;
//     return &x;
// }

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
void add(Graph &G, int x, int y) { G[x].eb(y), G[y].eb(x); }
template <class S> void add(Wgraph<S> &G, int x, int y, S c) { G[x].eb(y, c), G[y].eb(x, c); }

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
string to_string(char c) { return string(1, c); }

#ifdef _LOCAL
void dump() { cerr << endl; }
template <class Head, class... Tail> void dump(Head head, Tail... tail) {
    cerr << to_string(head) << " ";
    dump(tail...);
}
#define endl '\n'
#undef endl
#define debug(x)                                                                                                                                               \
    cout << #x << ": ";                                                                                                                                        \
    dump(x)
#else
void dump() {}
template <class Head, class... Tail> void dump(Head head, Tail... tail) {}
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

#pragma endregion

#include <utility>

namespace atcoder {

namespace internal {

// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if(x < 0) x += m;
    return x;
}

// Fast moduler by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
// NOTE: reconsider after Ice Lake
struct barrett {
    unsigned int _m;
    unsigned long long im;

    // @param m `1 <= m`
    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    // @return m
    unsigned int umod() const { return _m; }

    // @param a `0 <= a < m`
    // @param b `0 <= b < m`
    // @return `a * b % m`
    unsigned int mul(unsigned int a, unsigned int b) const {
        // [1] m = 1
        // a = b = im = 0, so okay

        // [2] m >= 2
        // im = ceil(2^64 / m)
        // -> im * m = 2^64 + r (0 <= r < m)
        // let z = a*b = c*m + d (0 <= c, d < m)
        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im
        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2
        // ((ab * im) >> 64) == c or c + 1
        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x = (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if(_m <= v) v += _m;
        return v;
    }
};

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if(m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while(n) {
        if(n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing for Integers That Fit into a Machine Word
// @param n `0 <= n`
constexpr bool is_prime_constexpr(int n) {
    if(n <= 1) return false;
    if(n == 2 || n == 7 || n == 61) return true;
    if(n % 2 == 0) return false;
    long long d = n - 1;
    while(d % 2 == 0) d /= 2;
    for(long long a : {2, 7, 61}) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while(t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if(y != n - 1 && t % 2 == 0) { return false; }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if(a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while(t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u; // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if(m0 < 0) m0 += b / s;
    return {s, m0};
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
constexpr int primitive_root_constexpr(int m) {
    if(m == 2) return 1;
    if(m == 167772161) return 3;
    if(m == 469762049) return 3;
    if(m == 754974721) return 11;
    if(m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while(x % 2 == 0) x /= 2;
    for(int i = 3; (long long)(i)*i <= x; i += 2) {
        if(x % i == 0) {
            divs[cnt++] = i;
            while(x % i == 0) { x /= i; }
        }
    }
    if(x > 1) { divs[cnt++] = x; }
    for(int g = 2;; g++) {
        bool ok = true;
        for(int i = 0; i < cnt; i++) {
            if(pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if(ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

} // namespace internal

} // namespace atcoder

#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value || std::is_same<T, __int128>::value, std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value || std::is_same<T, unsigned __int128>::value, std::true_type, std::false_type>::type;

template <class T> using make_unsigned_int128 = typename std::conditional<std::is_same<T, __int128_t>::value, __uint128_t, unsigned __int128>;

template <class T>
using is_integral =
    typename std::conditional<std::is_integral<T>::value || is_signed_int128<T>::value || is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;

template <class T>
using is_signed_int =
    typename std::conditional<(is_integral<T>::value && std::is_signed<T>::value) || is_signed_int128<T>::value, std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value) || is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int128<T>::value, make_unsigned_int128<T>,
                                              typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>, std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T> using is_signed_int = typename std::conditional<is_integral<T>::value && std::is_signed<T>::value, std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int = typename std::conditional<is_integral<T>::value && std::is_unsigned<T>::value, std::true_type, std::false_type>::type;

template <class T> using to_unsigned = typename std::conditional<is_signed_int<T>::value, std::make_unsigned<T>, std::common_type<T>>::type;

#endif

template <class T> using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

} // namespace internal

} // namespace atcoder

#include <cassert>
#include <numeric>
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

} // namespace internal

template <int m, std::enable_if_t<(1 <= m)> * = nullptr> struct static_modint : internal::static_modint_base {
    using mint = static_modint;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T> * = nullptr> static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if(x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T> * = nullptr> static_modint(T v) { _v = (unsigned int)(v % umod()); }
    static_modint(bool v) { _v = ((unsigned int)(v) % umod()); }

    unsigned int val() const { return _v; }

    mint &operator++() {
        _v++;
        if(_v == umod()) _v = 0;
        return *this;
    }
    mint &operator--() {
        if(_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint &operator+=(const mint &rhs) {
        _v += rhs._v;
        if(_v >= umod()) _v -= umod();
        return *this;
    }
    mint &operator-=(const mint &rhs) {
        _v -= rhs._v;
        if(_v >= umod()) _v += umod();
        return *this;
    }
    mint &operator*=(const mint &rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while(n) {
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if(prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct dynamic_modint : internal::modint_base {
    using mint = dynamic_modint;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    dynamic_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T> * = nullptr> dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if(x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T> * = nullptr> dynamic_modint(T v) { _v = (unsigned int)(v % mod()); }
    dynamic_modint(bool v) { _v = ((unsigned int)(v) % mod()); }

    unsigned int val() const { return _v; }

    mint &operator++() {
        _v++;
        if(_v == umod()) _v = 0;
        return *this;
    }
    mint &operator--() {
        if(_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint &operator+=(const mint &rhs) {
        _v += rhs._v;
        if(_v >= umod()) _v -= umod();
        return *this;
    }
    mint &operator-=(const mint &rhs) {
        _v += mod() - rhs._v;
        if(_v >= umod()) _v -= umod();
        return *this;
    }
    mint &operator*=(const mint &rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while(n) {
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt = 998244353;

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T> using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T> using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id> struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T> using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

} // namespace internal

} // namespace atcoder

ll modpow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n) {
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
namespace FastFourierTransform {
using real = double;

struct C {
    real x, y;

    C() : x(0), y(0) {}

    C(real x, real y) : x(x), y(y) {}

    inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }

    inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }

    inline C operator*(const C &c) const { return C(x * c.x - y * c.y, x * c.y + y * c.x); }

    inline C conj() const { return C(x, -y); }
};

const real PI = acosl(-1);
int base = 1;
vector<C> rts = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

void ensure_base(int nbase) {
    if(nbase <= base) return;
    rev.resize(1 << nbase);
    rts.resize(1 << nbase);
    for(int i = 0; i < (1 << nbase); i++) { rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1)); }
    while(base < nbase) {
        real angle = PI * 2.0 / (1 << (base + 1));
        for(int i = 1 << (base - 1); i < (1 << base); i++) {
            rts[i << 1] = rts[i];
            real angle_i = angle * (2 * i + 1 - (1 << base));
            rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
        }
        ++base;
    }
}

void fft(vector<C> &a, int n) {
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for(int i = 0; i < n; i++) {
        if(i < (rev[i] >> shift)) { swap(a[i], a[rev[i] >> shift]); }
    }
    for(int k = 1; k < n; k <<= 1) {
        for(int i = 0; i < n; i += 2 * k) {
            for(int j = 0; j < k; j++) {
                C z = a[i + j + k] * rts[j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] = a[i + j] + z;
            }
        }
    }
}

vector<int64_t> multiply(const vector<ll> &a, const vector<ll> &b) {
    int need = (int)a.size() + (int)b.size() - 1;
    int nbase = 1;
    while((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    vector<C> fa(sz);
    for(int i = 0; i < sz; i++) {
        int x = (i < (int)a.size() ? a[i] : 0);
        int y = (i < (int)b.size() ? b[i] : 0);
        fa[i] = C(x, y);
    }
    fft(fa, sz);
    C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
    for(int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
        fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
        fa[i] = z;
    }
    for(int i = 0; i < (sz >> 1); i++) {
        C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
        C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
        fa[i] = A0 + A1 * s;
    }
    fft(fa, sz >> 1);
    vector<int64_t> ret(need);
    for(int i = 0; i < need; i++) { ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x); }
    return ret;
}
}; // namespace FastFourierTransform
template <typename T> struct ArbitraryModConvolution {
    using real = FastFourierTransform::real;
    using C = FastFourierTransform::C;

    ArbitraryModConvolution() = default;

    vector<T> multiply(const vector<T> &a, const vector<T> &b, ll m, int need = -1) {
        if(need == -1) need = a.size() + b.size() - 1;
        int nbase = 0;
        while((1 << nbase) < need) nbase++;
        FastFourierTransform::ensure_base(nbase);
        int sz = 1 << nbase;
        vector<C> fa(sz);
        for(int i = 0; i < a.size(); i++) { fa[i] = C((a[i] % m) & ((1 << 15) - 1), (a[i] % m) >> 15); }
        fft(fa, sz);
        vector<C> fb(sz);
        if(a == b) {
            fb = fa;
        } else {
            for(int i = 0; i < b.size(); i++) { fb[i] = C((b[i] % m) & ((1 << 15) - 1), (b[i] % m) >> 15); }
            fft(fb, sz);
        }
        real ratio = 0.25 / sz;
        C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
        for(int i = 0; i <= (sz >> 1); i++) {
            int j = (sz - i) & (sz - 1);
            C a1 = (fa[i] + fa[j].conj());
            C a2 = (fa[i] - fa[j].conj()) * r2;
            C b1 = (fb[i] + fb[j].conj()) * r3;
            C b2 = (fb[i] - fb[j].conj()) * r4;
            if(i != j) {
                C c1 = (fa[j] + fa[i].conj());
                C c2 = (fa[j] - fa[i].conj()) * r2;
                C d1 = (fb[j] + fb[i].conj()) * r3;
                C d2 = (fb[j] - fb[i].conj()) * r4;
                fa[i] = c1 * d1 + c2 * d2 * r5;
                fb[i] = c1 * d2 + c2 * d1;
            }
            fa[j] = a1 * b1 + a2 * b2 * r5;
            fb[j] = a1 * b2 + a2 * b1;
        }
        fft(fa, sz);
        fft(fb, sz);
        vector<T> ret(need);
        for(int i = 0; i < need; i++) {
            int64_t aa = llround(fa[i].x);
            int64_t bb = llround(fb[i].x);
            int64_t cc = llround(fa[i].y);
            ret[i] = (aa + ((bb % m) << 15) + ((cc % m) << 30)) % m;
        }
        return ret;
    }
};

int main() {
    using mint = atcoder::modint;
    INT(n, m);
    mint::set_mod(m);

    vector<mint> fact(n + 1), ifact(n + 1);
    fact[0] = 1;
    rep2(i, 1, n) fact[i] = fact[i - 1] * i;
    ifact[0] = 1;
    rep2(i, 1, n) ifact[i] = ifact[i - 1] / i;
    auto C = [&](int x, int y) -> mint {
        if(x < 0 or y < 0 or x < y) return 0;
        return fact[x] * ifact[y] * ifact[x - y];
    };

    vv(mint, dp, n + 1, n + 1);
    vector<mint> s(n + 1);
    rep2(i, 1, n) rep2(j, 0, i - 1) s[i] += C(i - 1, j);

    rep2(i, 1, n - 2) dp[i][i] += s[i];

    rep2(i, 3, n - 2) {
        rep2(j, 1, i - 2) { rep2(k, 0, j) dp[i][(i - j - 1) + k] += dp[j][k] * C((i - j - 1) + k, k) * s[i - j - 1]; }
    }

    mint ans;
    rep2(i, 1, n - 2) { rep2(j, 0, n - i - 1) ans += dp[n - i - 1][j] * C(j + i, j) * s[i]; }

    // rep2(i, 1, n) {
    //     rep2(j, 1, n) { cout << dp[i][j].val() << " "; }
    //     cout << endl;
    // }

    ans += s[n];
    cout << ans.val() << endl;
}