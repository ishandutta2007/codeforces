#pragma region Macros
#pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define rep(i, n) for(ll i = 0; i < n; ++i)
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
template <class T> T POW(T x, ll n, const ll &mod) {
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
template <class T> pair<T, T> operator&(const pair<T, T> &l, const pair<T, T> &r) { return pair<T, T>(max(l.fi, r.fi), min(l.se, r.se)); }

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

#define endl '\n'
template <class T> void print(const T &a) { cout << a; }
void OUT() { cout << endl; }
template <class Head, class... Tail> void OUT(const Head &head, const Tail &...tail) {
    print(head);
    if(sizeof...(tail)) cout << ' ';
    OUT(tail...);
}

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

template <class T, class F> T bin_search(T ok, T ng, const F &f) {
    while(abs(ok - ng) > 1) {
        T mid = ok + ng >> 1;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
#pragma endregion

namespace modular {
constexpr ll MOD = 998244353;
const int MAXN = 11000000;
template <ll Modulus> class modint;
using mint = modint<MOD>;
using vmint = vector<mint>;
vector<mint> Inv;
mint inv(int x);
template <ll Modulus> class modint {

  public:
    static constexpr int mod() { return Modulus; }
    ll a;

    constexpr modint(const ll x = 0) noexcept : a(((x % Modulus) + Modulus) % Modulus) {}
    constexpr ll &val() noexcept { return a; }
    constexpr const ll &val() const noexcept { return a; }
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
    constexpr friend bool operator==(const modint &lhs, const modint &rhs) { return lhs.a == rhs.a; }
    constexpr friend bool operator!=(const modint &lhs, const modint &rhs) { return lhs.a != rhs.a; }
    // constexpr friend modint operator^=(const modint &lhs, const modint &rhs) { return modint(lhs) ^= modint(rhs); }
};
vmint Fact{1, 1}, Ifact{1, 1};
mint inv(int n) {
    if(n > MAXN) return (mint(n)).pow(MOD - 2);
    if(Inv.empty()) Inv.emplace_back(0), Inv.emplace_back(1);
    if(Inv.size() > n)
        return Inv[n];
    else {
        for(int i = Inv.size(); i <= n; ++i) {
            auto [y, x] = div(int(MOD), i);
            Inv.emplace_back(Inv[x] * (-y));
        }
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
    if(a > MAXN) {
        mint res = 1;
        rep(i, b) res *= a - i, res /= i + 1;
        return res;
    }
    return fact(a) * ifact(b) * ifact(a - b);
}
mint P(int a, int b) {
    if(a < 0 || b < 0) return 0;
    if(a < b) return 0;
    if(a > MAXN) {
        mint res = 1;
        rep(i, b) res *= a - i;
        return res;
    }
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
ostream &operator<<(ostream &os, const vmint &a) {
    if(!a.empty()) {
        os << a[0];
        for(int i = 1; i < si(a); i++) os << " " << a[i];
    }
    return os;
}
#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace convolution {

namespace internal {
int ceil_pow2(int n) {
    int x = 0;
    while((1U << x) < (unsigned int)(n)) x++;
    return x;
}
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if(x < 0) x += m;
    return x;
}
struct barrett {
    unsigned int _m;
    unsigned long long im;
    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
    unsigned int umod() const { return _m; }
    unsigned int mul(unsigned int a, unsigned int b) const {
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

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if(a == 0) return {b, 0};
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while(t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u; // |m1 * u| <= |m1| * s <= b
        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
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

void butterfly(std::vector<mint> &a) {
    static constexpr int g = internal::primitive_root<mint::mod()>;
    int n = int(a.size());
    int h = internal::ceil_pow2(n);

    static bool first = true;
    static mint sum_e[30]; // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]
    if(first) {
        first = false;
        mint es[30], ies[30]; // es[i]^(2^(2+i)) == 1
        int cnt2 = bsf(mint::mod() - 1);
        mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
        for(int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for(int i = 0; i < cnt2 - 2; i++) {
            sum_e[i] = es[i] * now;
            now *= ies[i];
        }
    }
    for(int ph = 1; ph <= h; ph++) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint now = 1;
        for(int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for(int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p] * now;
                a[i + offset] = l + r;
                a[i + offset + p] = l - r;
            }
            now *= sum_e[bsf(~(unsigned int)(s))];
        }
    }
}

void butterfly_inv(std::vector<mint> &a) {
    static constexpr int g = internal::primitive_root<mint::mod()>;
    int n = int(a.size());
    int h = internal::ceil_pow2(n);

    static bool first = true;
    static mint sum_ie[30]; // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
    if(first) {
        first = false;
        mint es[30], ies[30]; // es[i]^(2^(2+i)) == 1
        int cnt2 = bsf(mint::mod() - 1);
        mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
        for(int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for(int i = 0; i < cnt2 - 2; i++) {
            sum_ie[i] = ies[i] * now;
            now *= es[i];
        }
    }

    for(int ph = h; ph >= 1; ph--) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint inow = 1;
        for(int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for(int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p];
                a[i + offset] = l + r;
                a[i + offset + p] = (unsigned long long)(mint::mod() + l.val() - r.val()) * inow.val();
            }
            inow *= sum_ie[bsf(~(unsigned int)(s))];
        }
    }
    mint z = mint(n).inv();
    for(int i = 0; i < n; i++) a[i] *= z;
}

} // namespace internal

std::vector<mint> convolution(std::vector<mint> a, std::vector<mint> b) {
    int n = int(a.size()), m = int(b.size());
    if(!n || !m) return {};
    if(std::min(n, m) <= 60) {
        if(n < m) {
            std::swap(n, m);
            std::swap(a, b);
        }
        std::vector<mint> ans(n + m - 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) { ans[i + j] += a[i] * b[j]; }
        }
        return ans;
    }
    int z = 1 << internal::ceil_pow2(n + m - 1);
    a.resize(z);
    internal::butterfly(a);
    b.resize(z);
    internal::butterfly(b);
    for(int i = 0; i < z; i++) { a[i] *= b[i]; }
    internal::butterfly_inv(a);
    a.resize(n + m - 1);
    // mint iz = mint(z).inv();
    // for(int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
}

} // namespace convolution

using Poly = vmint;
Poly low(const Poly &f, int s) { return Poly(f.begin(), f.begin() + min<int>(max(s, 1), f.size())); }
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
Poly operator*(const Poly &l, const Poly &r) { return convolution::convolution(l, r); }
Poly &operator*=(Poly &l, const Poly &r) { return l = l * r; }
Poly &operator*=(Poly &l, const mint &x) {
    for(auto &e : l) e *= x;
    return l;
}
Poly operator*(const Poly &l, const mint &x) {
    auto res = l;
    return res *= x;
}

Poly inv(const Poly &f, int s = -1) {
    if(s == -1) s = f.size();
    Poly r(s);
    r[0] = mint(1) / f[0];
    for(int n = 1; n < s; n *= 2) {
        auto F = low(f, 2 * n);
        F.resize(2 * n);
        convolution::internal::butterfly(F);
        auto g = low(r, 2 * n);
        g.resize(2 * n);
        convolution::internal::butterfly(g);
        rep(i, 2 * n) F[i] *= g[i];
        convolution::internal::butterfly_inv(F);
        rep(i, n) F[i] = 0;
        convolution::internal::butterfly(F);
        rep(i, 2 * n) F[i] *= g[i];
        convolution::internal::butterfly_inv(F);
        rep2(i, n, min(2 * n, s) - 1) r[i] -= F[i];
    }
    return r;
}
Poly integ(const Poly &f) {
    Poly res(f.size() + 1);
    for(int i = 1; i < (int)res.size(); ++i) res[i] = f[i - 1] / i;
    return res;
}
Poly deriv(const Poly &f) {
    if(f.size() == 0) return Poly();
    Poly res(f.size() - 1);
    rep(i, res.size()) res[i] = f[i + 1] * (i + 1);
    return res;
}
Poly log(const Poly &f) {
    Poly g = integ(inv(f) * deriv(f));
    return Poly{g.begin(), g.begin() + f.size()};
}
Poly exp(const Poly &f) {
    Poly g{1};
    while(g.size() < f.size()) {
        Poly x(f.begin(), f.begin() + min(f.size(), g.size() * 2));
        x[0] += 1;
        g.resize(2 * g.size());
        x -= log(g);
        x *= {g.begin(), g.begin() + g.size() / 2};
        rep2(i, g.size() / 2, min<int>(x.size(), g.size()) - 1) g[i] = x[i];
    }
    return {g.begin(), g.begin() + f.size()};
}
Poly pow(const Poly &f, ll k, int need = -1) {
    const int n = (int)f.size();
    if(need == -1) need = n;
    int z = 0;
    rep(i, n) {
        if(f[i].a) break;
        z++;
    }
    if(z * k >= need) return Poly(n);
    mint rev = f[z].inv();
    Poly res = exp(log((f >> z) * rev) * k) * f[z].pow(k);
    res.resize(need - z * k);
    return res << z * k;
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

} // namespace modular
using namespace modular;

class MaximumMatching {
    /*
     * Maximum Cardinality Matching in General Graphs.
     * - O(\sqrt{n} m \log_{\max\{2, 1 + m/n\}} n) time
     * - O(n + m) space
     *
     * Note: each vertex is 1-indexed.
     * Ref:
     * Harold N. Gabow,
     * "The Weighted Matching Approach to Maximum Cardinality Matching" (2017)
     * (https://arxiv.org/abs/1703.03998)
     */

  public:
    struct Edge {
        int from, to;
    };
    static constexpr int Inf = 1 << 30;

  private:
    enum Label {
        kInner = -1, // should be < 0
        kFree = 0    // should be 0
    };
    struct Link {
        int from, to;
    };
    struct Log {
        int v, par;
    };

    struct LinkedList {
        LinkedList() {}
        LinkedList(int N, int M) : N(N), next(M) { clear(); }
        void clear() { head.assign(N, -1); }
        void push(int h, int u) { next[u] = head[h], head[h] = u; }
        int N;
        vector<int> head, next;
    };

    template <typename T> struct Queue {
        Queue() {}
        Queue(int N) : qh(0), qt(0), data(N) {}
        T operator[](int i) const { return data[i]; }
        void enqueue(int u) { data[qt++] = u; }
        int dequeue() { return data[qh++]; }
        bool empty() const { return qh == qt; }
        void clear() { qh = qt = 0; }
        int size() const { return qt; }
        int qh, qt;
        vector<T> data;
    };

    struct DisjointSetUnion {
        DisjointSetUnion() {}
        DisjointSetUnion(int N) : par(N) {
            for(int i = 0; i < N; ++i) par[i] = i;
        }
        int find(int u) { return par[u] == u ? u : (par[u] = find(par[u])); }
        void unite(int u, int v) {
            u = find(u), v = find(v);
            if(u != v) par[v] = u;
        }
        vector<int> par;
    };

  public:
    MaximumMatching(int N, const vector<Edge> &in) : N(N), NH(N >> 1), ofs(N + 2, 0), edges(in.size() * 2) {
        for(auto &e : in) ofs[e.from + 1] += 1, ofs[e.to + 1] += 1;
        for(int i = 1; i <= N + 1; ++i) ofs[i] += ofs[i - 1];
        for(auto &e : in) {
            edges[ofs[e.from]++] = e;
            edges[ofs[e.to]++] = {e.to, e.from};
        }
        for(int i = N + 1; i > 0; --i) ofs[i] = ofs[i - 1];
        ofs[0] = 0;
    }

    int maximum_matching() {
        initialize();
        int match = 0;
        while(match * 2 + 1 < N) {
            reset_count();
            bool has_augmenting_path = do_edmonds_search();
            if(!has_augmenting_path) break;
            match += find_maximal();
            clear();
        }
        return match;
    }

    vector<Edge> get_edges() {
        vector<Edge> ans;
        for(int i = 1; i <= N; ++i)
            if(mate[i] > i) ans.push_back(Edge{i, mate[i]});
        return ans;
    }

  private:
    void reset_count() {
        time_current_ = 0;
        time_augment_ = Inf;
        contract_count_ = 0;
        outer_id_ = 1;
        dsu_changelog_size_ = dsu_changelog_last_ = 0;
    }

    void clear() {
        que.clear();
        for(int u = 1; u <= N; ++u) potential[u] = 1;
        for(int u = 1; u <= N; ++u) dsu.par[u] = u;
        for(int t = time_current_; t <= N / 2; ++t) list.head[t] = -1;
        for(int u = 1; u <= N; ++u) blossom.head[u] = -1;
    }

    // first phase

    inline void grow(int x, int y, int z) {
        label[y] = kInner;
        potential[y] = time_current_; // visited time
        link[z] = {x, y};
        label[z] = label[x];
        potential[z] = time_current_ + 1;
        que.enqueue(z);
    }

    void contract(int x, int y) {
        int bx = dsu.find(x), by = dsu.find(y);
        const int h = -(++contract_count_) + kInner;
        label[mate[bx]] = label[mate[by]] = h;
        int lca = -1;
        while(1) {
            if(mate[by] != 0) swap(bx, by);
            bx = lca = dsu.find(link[bx].from);
            if(label[mate[bx]] == h) break;
            label[mate[bx]] = h;
        }
        for(auto bv : {dsu.par[x], dsu.par[y]}) {
            for(; bv != lca; bv = dsu.par[link[bv].from]) {
                int mv = mate[bv];
                link[mv] = {x, y};
                label[mv] = label[x];
                potential[mv] = 1 + (time_current_ - potential[mv]) + time_current_;
                que.enqueue(mv);
                dsu.par[bv] = dsu.par[mv] = lca;
                dsu_changelog[dsu_changelog_last_++] = {bv, lca};
                dsu_changelog[dsu_changelog_last_++] = {mv, lca};
            }
        }
    }

    bool find_augmenting_path() {
        while(!que.empty()) {
            int x = que.dequeue(), lx = label[x], px = potential[x], bx = dsu.find(x);
            for(int eid = ofs[x]; eid < ofs[x + 1]; ++eid) {
                int y = edges[eid].to;
                if(label[y] > 0) { // outer blossom/vertex
                    int time_next = (px + potential[y]) >> 1;
                    if(lx != label[y]) {
                        if(time_next == time_current_) return true;
                        time_augment_ = min(time_next, time_augment_);
                    } else {
                        if(bx == dsu.find(y)) continue;
                        if(time_next == time_current_) {
                            contract(x, y);
                            bx = dsu.find(x);
                        } else if(time_next <= NH)
                            list.push(time_next, eid);
                    }
                } else if(label[y] == kFree) { // free vertex
                    int time_next = px + 1;
                    if(time_next == time_current_)
                        grow(x, y, mate[y]);
                    else if(time_next <= NH)
                        list.push(time_next, eid);
                }
            }
        }
        return false;
    }

    bool adjust_dual_variables() {
        // Return true if the current matching is maximum.
        const int time_lim = min(NH + 1, time_augment_);
        for(++time_current_; time_current_ <= time_lim; ++time_current_) {
            dsu_changelog_size_ = dsu_changelog_last_;
            if(time_current_ == time_lim) break;
            bool updated = false;
            for(int h = list.head[time_current_]; h >= 0; h = list.next[h]) {
                auto &e = edges[h];
                int x = e.from, y = e.to;
                if(label[y] > 0) {
                    // Case: outer -- (free => inner => outer)
                    if(potential[x] + potential[y] != (time_current_ << 1)) continue;
                    if(dsu.find(x) == dsu.find(y)) continue;
                    if(label[x] != label[y]) {
                        time_augment_ = time_current_;
                        return false;
                    }
                    contract(x, y);
                    updated = true;
                } else if(label[y] == kFree) {
                    grow(x, y, mate[y]);
                    updated = true;
                }
            }
            list.head[time_current_] = -1;
            if(updated) return false;
        }
        return time_current_ > NH;
    }

    bool do_edmonds_search() {
        label[0] = kFree;
        for(int u = 1; u <= N; ++u) {
            if(mate[u] == 0) {
                que.enqueue(u);
                label[u] = u; // component id
            } else
                label[u] = kFree;
        }
        while(1) {
            if(find_augmenting_path()) break;
            bool maximum = adjust_dual_variables();
            if(maximum) return false;
            if(time_current_ == time_augment_) break;
        }
        for(int u = 1; u <= N; ++u) {
            if(label[u] > 0)
                potential[u] -= time_current_;
            else if(label[u] < 0)
                potential[u] = 1 + (time_current_ - potential[u]);
        }
        return true;
    }

    // second phase

    void rematch(int v, int w) {
        int t = mate[v];
        mate[v] = w;
        if(mate[t] != v) return;
        if(link[v].to == dsu.find(link[v].to)) {
            mate[t] = link[v].from;
            rematch(mate[t], t);
        } else {
            int x = link[v].from, y = link[v].to;
            rematch(x, y);
            rematch(y, x);
        }
    }

    bool dfs_augment(int x, int bx) {
        int px = potential[x], lx = label[bx];
        for(int eid = ofs[x]; eid < ofs[x + 1]; ++eid) {
            int y = edges[eid].to;
            if(px + potential[y] != 0) continue;
            int by = dsu.find(y), ly = label[by];
            if(ly > 0) { // outer
                if(lx >= ly) continue;
                int stack_beg = stack_last_;
                for(int bv = by; bv != bx; bv = dsu.find(link[bv].from)) {
                    int bw = dsu.find(mate[bv]);
                    stack[stack_last_++] = bw;
                    link[bw] = {x, y};
                    dsu.par[bv] = dsu.par[bw] = bx;
                }
                while(stack_last_ > stack_beg) {
                    int bv = stack[--stack_last_];
                    for(int v = blossom.head[bv]; v >= 0; v = blossom.next[v]) {
                        if(!dfs_augment(v, bx)) continue;
                        stack_last_ = stack_beg;
                        return true;
                    }
                }
            } else if(ly == kFree) {
                label[by] = kInner;
                int z = mate[by];
                if(z == 0) {
                    rematch(x, y);
                    rematch(y, x);
                    return true;
                }
                int bz = dsu.find(z);
                link[bz] = {x, y};
                label[bz] = outer_id_++;
                for(int v = blossom.head[bz]; v >= 0; v = blossom.next[v]) {
                    if(dfs_augment(v, bz)) return true;
                }
            }
        }
        return false;
    }

    int find_maximal() {
        // discard blossoms whose potential is 0.
        for(int u = 1; u <= N; ++u) dsu.par[u] = u;
        for(int i = 0; i < dsu_changelog_size_; ++i) { dsu.par[dsu_changelog[i].v] = dsu_changelog[i].par; }
        for(int u = 1; u <= N; ++u) {
            label[u] = kFree;
            blossom.push(dsu.find(u), u);
        }
        int ret = 0;
        for(int u = 1; u <= N; ++u)
            if(!mate[u]) {
                int bu = dsu.par[u];
                if(label[bu] != kFree) continue;
                label[bu] = outer_id_++;
                for(int v = blossom.head[bu]; v >= 0; v = blossom.next[v]) {
                    if(!dfs_augment(v, bu)) continue;
                    ret += 1;
                    break;
                }
            }
        assert(ret >= 1);
        return ret;
    }

    // init

    void initialize() {
        que = Queue<int>(N);

        mate.assign(N + 1, 0);
        potential.assign(N + 1, 1);
        label.assign(N + 1, kFree);
        link.assign(N + 1, {0, 0});

        dsu_changelog.resize(N);

        dsu = DisjointSetUnion(N + 1);
        list = LinkedList(NH + 1, edges.size());

        blossom = LinkedList(N + 1, N + 1);
        stack.resize(N);
        stack_last_ = 0;
    }

  private:
    const int N, NH;
    vector<int> ofs;
    vector<Edge> edges;

    Queue<int> que;

    vector<int> mate, potential;
    vector<int> label;
    vector<Link> link;

    vector<Log> dsu_changelog;
    int dsu_changelog_last_, dsu_changelog_size_;

    DisjointSetUnion dsu;
    LinkedList list, blossom;
    vector<int> stack;
    int stack_last_;

    int time_current_, time_augment_;
    int contract_count_, outer_id_;
};

using E = MaximumMatching::Edge;

template <typename G = Graph> struct SCC {
    G g;
    Graph rg;
    vector<int> comp, ord;
    vector<bool> used;
    int num; // 

    SCC(G &g) : g(g), rg(g.size()), comp(g.size(), -1), used(g.size()) {
        rep(i, g.size()) for(auto &e : g[i]) rg[e].emplace_back(i);
        ord.reserve(g.size());
        build();
    };
    SCC(int n) : g(n), rg(n), comp(n, -1), used(n) { ord.reserve(n); };
    inline void add(int a, int b) {
        g[a].emplace_back(b);
        rg[b].emplace_back(a);
    }
    int operator[](int k) { return comp[k]; }
    void dfs(int x) {
        if(used[x]) return;
        used[x] = true;
        for(auto &e : g[x])
            if(!used[e]) dfs(e);
        ord.emplace_back(x);
    }
    void rdfs(int x, int cnt) {
        if(comp[x] != -1) return;
        comp[x] = cnt;
        for(int &e : rg[x])
            if(comp[e] == -1) rdfs(e, cnt);
    }
    void build() {
        rep(i, g.size()) dfs(i);
        reverse(all(ord));
        num = 0;
        for(int &i : ord)
            if(comp[i] == -1) { rdfs(i, num), num++; }
    }
    //  DAG 
    Graph getGraph() {
        Graph res(num);
        rep(i, g.size()) {
            for(auto &e : g[i]) {
                if(comp[e] == comp[i]) continue;
                res[comp[i]].emplace_back(comp[e]);
            }
        }
        rep(i, g.size()) UNIQUE(res[i]);
        return res;
    }
    // 
    vector<vector<int>> belong() {
        vector<vector<int>> res(num);
        rep(i, g.size()) res[comp[i]].emplace_back(i);
        return res;
    }
};

struct TwoSat : SCC<Graph> {
    int n;
    using SCC::SCC;
    TwoSat(int n) : n(n), SCC(n * 2) {}
    // not i = i + n
    inline int rev(int x) { return x >= n ? x - n : x + n; }
    inline int id(int x) { return x < 0 ? n - x - 1 : x - 1; }
    inline void IF(int x, int y) {
        // x => y
        add(x, y), add(rev(y), rev(x));
    }
    void OR(int x, int y) { IF(rev(id(x)), id(y)); }
    vector<int> solve() {
        build();
        vector<int> res(n);
        rep(i, n) {
            if(comp[i] == comp[rev(i)]) return vector<int>();
            res[i] = comp[i] > comp[rev(i)];
        }
        return res;
    }
    bool can() {
        build();
        rep(i, n) {
            if(comp[i] == comp[rev(i)]) return false;
        }
        return true;
    }
};

struct UnionFind {
    vector<int> data;
    int num;

    UnionFind(int n) : num(n) { data.assign(n, -1); }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        num--;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if(data[x] < 0) return x;
        return (data[x] = find(data[x]));
    }
    int size(int x) { return -data[find(x)]; }
    const int operator[](const int k) { return find(k); }
    vector<vi> belong() {
        vector<vi> res(data.size());
        rep(i, data.size()) res[find(i)].eb(i);
        return res;
    }
    void reset() {
        num = data.size();
        data.assign(num, -1);
    }
};

#ifdef _LOCAL
constexpr int N = 510;
#else
constexpr int N = 510;
#endif

const int MAX_ROW = N * N; // to be set appropriately
const int MAX_COL = N;     // to be set appropriately
struct BitMatrix {
    int H, W;
    vector<bitset<MAX_COL>> val;
    BitMatrix(int m = 1, int n = 1) : H(m), W(n), val(m) {}
    inline bitset<MAX_COL> &operator[](int i) { return val[i]; }
};

int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for(int col = 0; col < A.W; ++col) {
        if(is_extended && col == A.W - 1) break;
        int pivot = -1;
        for(int row = rank; row < A.H; ++row) {
            if(A[row][col]) {
                pivot = row;
                break;
            }
        }
        if(pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for(int row = 0; row < A.H; ++row) {
            if(row != rank && A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}

int linear_equation(BitMatrix A, vector<int> b, vector<int> &res) {
    int m = A.H, n = A.W;
    BitMatrix M(m, n + 1);
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    // check if it has no solution
    for(int row = rank; row < m; ++row)
        if(M[row][n]) return -1;

    // answer
    res.assign(n, 0);
    for(int i = 0; i < rank; ++i) res[i] = M[i][n];
    return rank;
}

int main() {
    BitMatrix bm(501 * 501, 0);
    TEST {
        INT(n);
        VV(int, a, n * 2, n);
        vpi v;
        vv(int, ng, n * 2, n * 2);
        rep(i, n * 2) rep(j, i) {
            bool flag = true;
            rep(k, n) {
                if(a[i][k] == a[j][k]) flag = false;
            }
            if(!flag) {
                v.eb(i, j);
                ng[i][j] = ng[j][i] = 1;
            }
        }
        vector<E> edges(si(v), {0, 0});
        rep(i, si(v)) {
            auto [x, y] = v[i];
            edges[i] = {x + 1, y + 1};
        }
        auto M = MaximumMatching(n * 2, edges);
        M.maximum_matching();
        auto res = M.get_edges();
        TwoSat sat(n);

        UnionFind uf(n);
        rep(i, n) rep(j, i) {
            vi a{res[i].from - 1, res[i].to - 1};
            vi b{res[j].from - 1, res[j].to - 1};
            bool flag = false;
            rep(x, 2) rep(y, 2) {
                if(ng[a[x]][b[y]]) {
                    // dump(x ? -(i + 1) : i + 1, y ? -(j + 1) : j + 1);
                    sat.IF(i + x * n, j + (1 - y) * n);
                    flag = true;
                }
            }
            if(flag) uf.unite(i, j);
        }

        auto ans = sat.solve();

        bm.H = n * n, bm.W = n;

        rep(i, n) rep(j, n) {
            bm[j * n + a[res[i].from - 1][j] - 1][i].flip();
            bm[j * n + a[res[i].to - 1][j] - 1][i].flip();
        }

        OUT(modpow(2, n - GaussJordan(bm)));

        rep(i, n * n) rep(j, n) bm[i][j] = 0;

        rep(i, n) { cout << (ans[i] ? res[i].from : res[i].to) << " "; }
        OUT();
    }
}