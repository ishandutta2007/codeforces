#pragma region Macros
#pragma GCC optimize("O3")
#pragma GCC target("avx2,avx")
#pragma GCC optimize("unroll-loops")
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
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
using namespace std;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define si(c) (int)(c).size()
#define INT(...)                                                                                                                                               \
    int __VA_ARGS__;                                                                                                                                           \
    IN(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
    ll __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
#define ULL(...)                                                                                                                                               \
    ull __VA_ARGS__;                                                                                                                                           \
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
#define LD(...)                                                                                                                                                \
    ld __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
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
string stin() {
    string s;
    cin >> s;
    return s;
}
template <class T, class S> inline bool chmax(T &a, S b) {

    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T, class S> inline bool chmin(T &a, S b) {

    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
vi iota(int n) {
    vi a(n);
    iota(all(a), 0);
    return a;
}
template <class T> void UNIQUE(vector<T> &x) {
    sort(all(x));
    x.erase(unique(all(x)), x.end());
}
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
void print() { putchar(' '); }
void print(bool a) { cout << a; }
void print(int a) { cout << a; }
void print(long long a) { cout << a; }
void print(char a) { cout << a; }
void print(string &a) { cout << a; }
void print(double a) { cout << a; }
template <class T> void print(const vector<T> &);
template <class T, size_t size> void print(const array<T, size> &);
template <class T, class L> void print(const pair<T, L> &p);
template <class T, size_t size> void print(const T (&)[size]);
template <class T> void print(const vector<T> &a) {
    if(a.empty()) return;
    print(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        cout << " ";
        print(*i);
    }
    cout << endl;
}
template <class T> void print(const deque<T> &a) {

    if(a.empty()) return;
    print(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        cout << " ";
        print(*i);
    }
}
template <class T, size_t size> void print(const array<T, size> &a) {
    print(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        cout << " ";
        print(*i);
    }
}
template <class T, class L> void print(const pair<T, L> &p) {
    cout << '(';
    print(p.first);
    cout << ",";
    print(p.second);
    cout << ')';
}
template <class T> void print(set<T> &x) {
    for(auto e : x) print(e), cout << " ";
    cout << endl;
}
template <class T> void print(multiset<T> &x) {
    for(auto e : x) print(e), cout << " ";
    cout << endl;
}
template <class T, size_t size> void print(const T (&a)[size]) {
    print(a[0]);
    for(auto i = a; ++i != end(a);) {
        cout << " ";
        print(*i);
    }
}
template <class T> void print(const T &a) { cout << a; }
int out() {
    putchar('\n');
    return 0;
}
template <class T> int out(const T &t) {
    print(t);
    putchar('\n');
    return 0;
}
template <class Head, class... Tail> int out(const Head &head, const Tail &... tail) {
    print(head);
    putchar(' ');
    out(tail...);
    return 0;
}
ll gcd(ll a, ll b) {
    while(b) {
        ll c = b;
        b = a % b;
        a = c;
    }
    return a;
}
ll lcm(ll a, ll b) {

    if(!a || !b) return 0;
    return a * b / gcd(a, b);
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
int popcount(ll x) { return __builtin_popcountll(x); }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n) { return uniform_int_distribution<int>(0, n - 1)(rng); }
ll rndll(ll n) { return uniform_int_distribution<ll>(0, n - 1)(rng); }
template <typename T> void shuffle(vector<T> &v) {
    rep3(i, v.size() - 1, 1) { swap(v[i], v[rnd(i)]); }
}
#define endl '\n'
vector<string> YES{"NO", "YES"};
vector<string> Yes{"No", "Yes"};
vector<string> yes{"no", "yes"};

#ifdef _LOCAL
#undef endl
#define debug(x)                                                                                                                                               \
    cout << #x << ": ";                                                                                                                                        \
    print(x);                                                                                                                                                  \
    cout << endl;
void err() {}
template <class T> void err(const T &t) {
    print(t);
    cout << " ";
}
template <class Head, class... Tail> void err(const Head &head, const Tail &... tail) {
    print(head);
    putchar(' ');
    out(tail...);
}
#else
#define debug(x)
template <class... T> void err(const T &...) {}
#endif

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

struct Graph : vector<vector<int>> {
    using vector<vector<int>>::vector;
    Graph(int n, int m) : vector(n) { read(m); }
    inline void add(int a, int b, bool directed = false) {
        (*this)[a].emplace_back(b);

        if(!directed) (*this)[b].emplace_back(a);
    }
    void read(int n = -1, int offset = 1, bool directed = false) {

        if(n == -1) n = this->size() - 1;
        int a, b;
        while(n--) {
            cin >> a >> b;
            Graph::add(a - offset, b - offset, directed);
        }
    }
};
template <typename T> struct WeightedGraph : vector<Edges<T>> {
    using vector<Edges<T>>::vector;
    inline void add(int a, int b, T c, bool directed = false) {
        (*this)[a].emplace_back(b, c);

        if(!directed) (*this)[b].emplace_back(a, c);
    }
    void read(int n = -1, int offset = 1) {

        if(n == -1) n = this->size() - 1;
        int a, b;
        T c;
        while(n--) {
            cin >> a >> b >> c;
            WeightedGraph::add(a - offset, b - offset, c);
        }
    }
};
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;

#define i128 __int128_t
#define ull unsigned long long int
#define TEST                                                                                                                                                   \
    INT(testcases);                                                                                                                                            \
    while(testcases--)
#pragma endregion

// ____________________
namespace modular {
constexpr ll MOD = 1000000007;
const int MAXN = 1100000;
template <ll Modulus> class modint {
    using u64 = ll;

  public:
    u64 a;

    constexpr modint(const u64 x = 0) noexcept : a(((x % Modulus) + Modulus) % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr modint operator-() const noexcept { return modint() - *this; }
    constexpr modint operator+(const modint rhs) const noexcept { return modint(*this) += rhs; }
    constexpr modint operator-(const modint rhs) const noexcept { return modint(*this) -= rhs; }
    constexpr modint operator*(const modint rhs) const noexcept { return modint(*this) *= rhs; }
    template <typename T> constexpr modint operator^(T rhs) const noexcept { return modint(*this) ^= rhs; }
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
    constexpr bool operator==(const modint rhs) const noexcept { return a == rhs.a; }
    template <typename T> constexpr modint &operator^=(T n) noexcept {
        modint<Modulus> res = 1;
        modint<Modulus> x = a;
        while(n) {
            if(n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        a = res.a;
        return *this;
    }
};
#define mint modint<MOD>
#define vmint vector<mint>
vmint Inv{0, 1}, Prd{1, 1}, Invprd{1, 1};
mint inv(int n) {
    if(Inv.size() > n)
        return Inv[n];
    else {
        for(int i = Inv.size(); i <= n; ++i) Inv.emplace_back(Inv[MOD % i] * (-MOD / i));
        return Inv[n];
    }
}
mint prd(int n) {
    if(Prd.size() > n)
        return Prd[n];
    else
        for(int i = Prd.size(); i <= n; ++i) Prd.emplace_back(Prd[i - 1] * i);
    return Prd[n];
}
mint invprd(int n) {
    if(Invprd.size() > n)
        return Invprd[n];
    else
        for(int i = Invprd.size(); i <= n; ++i) Invprd.emplace_back(Invprd[i - 1] * inv(i));
    return Invprd[n];
}
mint modpow(ll a, ll n) {
    mint x = a;
    return x ^= n;
}
template <ll T> modint<T> operator/(modint<T> l, modint<T> r) {
    if(r.a < MAXN) return l * inv(r.a);
    return l * (r ^ (MOD - 2));
}
template <typename T, ll S> modint<S> operator/(T l, modint<S> r) { return modint<S>(l) / r; }
template <ll T> modint<T> operator/=(modint<T> &l, modint<T> r) { return l = l / r; }
mint C(int a, int b) {
    if(a < 0 || b < 0) return 0;
    if(a < b) return 0;
    return prd(a) * invprd(b) * invprd(a - b);
}
mint P(int a, int b) {
    if(a < 0 || b < 0) return 0;
    if(a < b) return 0;
    return prd(a) * invprd(a - b);
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
template <int mod> void FMT(vector<modint<mod>> &f, bool inv = false) {
    using V = vector<modint<mod>>;
    static V g(30), ig(30);
    if(g.front().a == 0) {
        modint<mod> root = 2;
        while((root ^ ((mod - 1) / 2)).a == 1) root += 1;
        rep(i, 30) g[i] = -(root ^ ((mod - 1) >> (i + 2))), ig[i] = g[i] ^ (mod - 2);
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
        c = modint<mod>(n) ^ (mod - 2);
    else
        c = 1;
    for(auto &&e : f) e *= c;
}
using Poly = vmint;
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
ostream &operator<<(ostream &os, Poly a) {
    for(auto e : a) cout << e.a << " ";
    return os;
}
} // namespace modular
using namespace modular;
main() {
    INT(p, k);
    if(k == 0) {
        cout << modpow(p, p - 1) << endl;
        return 0;
    } else if(k == 1) {
        cout << modpow(p, p) << endl;
        return 0;
    }
    vi used(p);
    mint ans = 1;
    rep2(i, 1, p - 1) {
        if(used[i]) continue;
        ll now = i;
        ll K = 1;
        while(!used[now]) {
            K = K * k % p;
            used[now] = true;
            now = now * k % p;
        }
        if(K == 1) ans *= p;
    }
    cout << ans << endl;
}