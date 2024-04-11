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
constexpr ll allbit(int n) { return (1LL << n) - 1; }
// int popcount(signed t) { return __builtin_popcount(t); }
// int popcount(ll t) { return __builtin_popcountll(t); }
int popcount(uint64_t t) { return __builtin_popcountll(t); }
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
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
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

vmint power_table(mint x, int len) {
    vmint res(len + 1);
    res[0] = 1;
    rep(i, len) res[i + 1] = res[i] * x;
    return res;
}

} // namespace modular
using namespace modular;

struct AngelBeats {
    using i64 = long long;
    static constexpr i64 INF = numeric_limits<i64>::max() / 2.1;

    struct alignas(32) Node {
        i64 sum = 0, g1 = 0, l1 = 0;
        i64 g2 = -INF, gc = 1, l2 = INF, lc = 1, add = 0;
    };

    vector<Node> v;
    i64 n, log;

    AngelBeats() {}
    AngelBeats(int _n) : AngelBeats(vector<i64>(_n)) {}
    AngelBeats(const vector<i64> &vc) {
        n = 1, log = 0;
        while(n < (int)vc.size()) n <<= 1, log++;
        v.resize(2 * n);
        for(i64 i = 0; i < (int)vc.size(); ++i) { v[i + n].sum = v[i + n].g1 = v[i + n].l1 = vc[i]; }
        for(i64 i = n - 1; i; --i) update(i);
    }

    void range_chmin(int l, int r, i64 x) { inner_apply<1>(l, r, x); }
    void range_chmax(int l, int r, i64 x) { inner_apply<2>(l, r, x); }
    void range_add(int l, int r, i64 x) { inner_apply<3>(l, r, x); }
    void range_update(int l, int r, i64 x) { inner_apply<4>(l, r, x); }
    i64 range_min(int l, int r) { return inner_fold<1>(l, r); }
    i64 range_max(int l, int r) { return inner_fold<2>(l, r); }
    i64 range_sum(int l, int r) { return inner_fold<3>(l, r); }

  private:
    void update(int k) {
        Node &p = v[k];
        Node &l = v[k * 2 + 0];
        Node &r = v[k * 2 + 1];

        p.sum = l.sum + r.sum;

        if(l.g1 == r.g1) {
            p.g1 = l.g1;
            p.g2 = max(l.g2, r.g2);
            p.gc = l.gc + r.gc;
        } else {
            bool f = l.g1 > r.g1;
            p.g1 = f ? l.g1 : r.g1;
            p.gc = f ? l.gc : r.gc;
            p.g2 = max(f ? r.g1 : l.g1, f ? l.g2 : r.g2);
        }

        if(l.l1 == r.l1) {
            p.l1 = l.l1;
            p.l2 = min(l.l2, r.l2);
            p.lc = l.lc + r.lc;
        } else {
            bool f = l.l1 < r.l1;
            p.l1 = f ? l.l1 : r.l1;
            p.lc = f ? l.lc : r.lc;
            p.l2 = min(f ? r.l1 : l.l1, f ? l.l2 : r.l2);
        }
    }

    void push_add(int k, i64 x) {
        Node &p = v[k];
        p.sum += x << (log + __builtin_clz(k) - 31);
        p.g1 += x;
        p.l1 += x;
        if(p.g2 != -INF) p.g2 += x;
        if(p.l2 != INF) p.l2 += x;
        p.add += x;
    }
    void push_min(int k, i64 x) {
        Node &p = v[k];
        p.sum += (x - p.g1) * p.gc;
        if(p.l1 == p.g1) p.l1 = x;
        if(p.l2 == p.g1) p.l2 = x;
        p.g1 = x;
    }
    void push_max(int k, i64 x) {
        Node &p = v[k];
        p.sum += (x - p.l1) * p.lc;
        if(p.g1 == p.l1) p.g1 = x;
        if(p.g2 == p.l1) p.g2 = x;
        p.l1 = x;
    }
    void push(int k) {
        Node &p = v[k];
        if(p.add != 0) {
            push_add(k * 2 + 0, p.add);
            push_add(k * 2 + 1, p.add);
            p.add = 0;
        }
        if(p.g1 < v[k * 2 + 0].g1) push_min(k * 2 + 0, p.g1);
        if(p.l1 > v[k * 2 + 0].l1) push_max(k * 2 + 0, p.l1);

        if(p.g1 < v[k * 2 + 1].g1) push_min(k * 2 + 1, p.g1);
        if(p.l1 > v[k * 2 + 1].l1) push_max(k * 2 + 1, p.l1);
    }

    void subtree_chmin(int k, i64 x) {
        if(v[k].g1 <= x) return;
        if(v[k].g2 < x) {
            push_min(k, x);
            return;
        }
        push(k);
        subtree_chmin(k * 2 + 0, x);
        subtree_chmin(k * 2 + 1, x);
        update(k);
    }

    void subtree_chmax(int k, i64 x) {
        if(x <= v[k].l1) return;
        if(x < v[k].l2) {
            push_max(k, x);
            return;
        }
        push(k);
        subtree_chmax(k * 2 + 0, x);
        subtree_chmax(k * 2 + 1, x);
        update(k);
    }

    template <int cmd> inline void _apply(int k, i64 x) {
        if constexpr(cmd == 1) subtree_chmin(k, x);
        if constexpr(cmd == 2) subtree_chmax(k, x);
        if constexpr(cmd == 3) push_add(k, x);
        if constexpr(cmd == 4) subtree_chmin(k, x), subtree_chmax(k, x);
    }

    template <int cmd> void inner_apply(int l, int r, i64 x) {
        if(l == r) return;
        l += n, r += n;
        for(int i = log; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }
        {
            int l2 = l, r2 = r;
            while(l < r) {
                if(l & 1) _apply<cmd>(l++, x);
                if(r & 1) _apply<cmd>(--r, x);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
        for(int i = 1; i <= log; i++) {
            if(((l >> i) << i) != l) update(l >> i);
            if(((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <int cmd> inline i64 e() {
        if constexpr(cmd == 1) return INF;
        if constexpr(cmd == 2) return -INF;
        return 0;
    }

    template <int cmd> inline void op(i64 &a, const Node &b) {
        if constexpr(cmd == 1) a = min(a, b.l1);
        if constexpr(cmd == 2) a = max(a, b.g1);
        if constexpr(cmd == 3) a += b.sum;
    }

    template <int cmd> i64 inner_fold(int l, int r) {
        if(l == r) return e<cmd>();
        l += n, r += n;
        for(int i = log; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }
        i64 lx = e<cmd>(), rx = e<cmd>();
        while(l < r) {
            if(l & 1) op<cmd>(lx, v[l++]);
            if(r & 1) op<cmd>(rx, v[--r]);
            l >>= 1;
            r >>= 1;
        }
        if constexpr(cmd == 1) lx = min(lx, rx);
        if constexpr(cmd == 2) lx = max(lx, rx);
        if constexpr(cmd == 3) lx += rx;
        return lx;
    }
};

/**
 * @brief Range Chmin Chmax Add Update Range Min Max Sum Segment Tree Beats!
 * @docs docs/segment-tree/segment-tree-beats.md
 */

int main() {
    TEST {
        INT(n);
        VEC(int, a, n);
        mint ans;
        vpi v;
        rep3(i, n - 1, 0) {
            for(auto [x, y] : v) { ans += mint(1) * (ceil(a[i], x) - 1) * y * (i + 1); }
            vpi nxt;
            bool flag = true;
            if(!empty(v) and begin(v)->fi < rbegin(v)->fi) {
                nxt.eb(a[i], 1);
                flag = false;
            }
            for(auto [x, y] : v) {
                int t = ceil(a[i], x);
                int k = a[i] / t;
                if(!empty(nxt) and nxt.back().fi == k)
                    nxt.back().se += y;
                else
                    nxt.eb(k, y);
            }
            if(flag) {
                if(!empty(nxt) and nxt.back().fi == a[i])
                    nxt.back().se++;
                else
                    nxt.eb(a[i], 1);
            }
            swap(v, nxt);
        }
        OUT(ans);
    }
}