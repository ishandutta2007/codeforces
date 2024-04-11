#pragma region Macros
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2,avx")
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
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
using namespace std;
string YES[2] = {"NO", "YES"};
string Yes[2] = {"No", "Yes"};
string yes[2] = {"no", "yes"};
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
int popcount(ll x) { return __builtin_popcountll(x); }
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
    for(auto &e : v) cout << e << " ";
    cout << endl;
    return os;
}
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) {
    cout << "(" << p.fi << ", " << p.se << ")";
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int rnd(int n) { return uniform_int_distribution<int>(0, n - 1)(rng); }
// ll rndll(ll n) { return uniform_int_distribution<ll>(0, n - 1)(rng); }

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
#pragma endregion

// q / p
struct frac {
    template <typename T> static constexpr inline T gcd(const T a, const T b) { return (b == 0) ? a : gcd(b, a % b); }
    ll q, p;
    inline constexpr void simplify() {
        if(p < 0) {
            p *= -1;
            q *= -1;
        }
        ll g = gcd(q < 0 ? -q : q, p);
        if(g) {
            p /= g;
            q /= g;
        }
    }
    constexpr frac(ll q = 0, ll p = 1) noexcept : q(q), p(p) { simplify(); }

    constexpr bool operator<(const frac &r) const { return (i128)q * r.p < (i128)p * r.q; }
    constexpr bool operator>(const frac &r) const { return (i128)q * r.p > (i128)p * r.q; }
    template <class T> const bool operator<(const T &r) const { return *this < frac(r); }
    template <class T> const bool operator>(const T &r) const { return *this > frac(r); }
    constexpr bool operator!=(const frac &r) const { return q * r.p < p * r.q; }
    constexpr bool operator==(const frac &r) const { return q * r.p == p * r.q; }
    constexpr frac operator+(const frac r) const noexcept { return frac(*this) += r; }
    constexpr frac operator-(const frac r) const noexcept { return frac(*this) -= r; }
    constexpr frac operator*(const frac r) const noexcept { return frac(*this) *= r; }
    constexpr frac operator/(const frac r) const noexcept { return frac(*this) /= r; }
    constexpr frac &operator+=(const frac &r) noexcept {
        ll g = gcd(p, r.p);
        q = r.p / g * q + p / g * r.q;
        p = p / g * r.p;
        (*this).simplify();
        return *this;
    }
    constexpr frac &operator-=(const frac &r) noexcept {
        ll g = gcd(p, r.p);
        q = r.p / g * q - p / g * r.q;
        p = p / g * r.p;
        (*this).simplify();
        return *this;
    }
    constexpr frac &operator*=(const frac &r) noexcept {
        q *= r.q;
        p *= r.p;
        (*this).simplify();
        return *this;
    }
    constexpr frac &operator/=(const frac &r) noexcept {
        q *= r.p;
        p *= r.q;
        (*this).simplify();
        return *this;
    }

    void print() {
        long double tmp = (long double)q / (long double)p;
        cout << tmp;
    }
};
ostream &operator<<(ostream &os, frac r) {
    os << r.q << " " << r.p;
    return os;
}

#define int long long
signed main() {
    INT(k, n, m);
    VEC(ll, a, k);
    vpi as(k);
    vv(pii, add, k);
    vpi mul;
    vi ismul(n), isas(n);
    rep(i, n) {
        INT(t, j, b);
        j--;
        if(t == 1) {
            if(chmax(as[j].fi, b)) as[j] = pii(b, i + 1), isas[i] = 1;
        } else if(t == 2) {
            add[j].eb(b, i + 1);
        } else
            mul.eb(b, i + 1), ismul[i] = 1;
    }
    vector<pair<frac, int>> p;
    for(auto [x, y] : mul) p.eb(frac(x, 1), y);
    rep(i, k) {
        if(a[i] < as[i].fi) add[i].eb(as[i].fi - a[i], as[i].se);
        sort(all(add[i]), greater{});
        for(auto [x, y] : add[i]) {
            p.eb(frac(a[i] + x, a[i]), y);
            a[i] += x;
        }
    }
    sort(all(p), greater{});
    cout << min(m, si(p)) << endl;
    vi rala, mirei, sofi;
    rep(i, min(m, si(p))) {
        int now = p[i].se;
        if(isas[now - 1])
            rala.eb(now);
        else if(ismul[now - 1])
            sofi.eb(now);
        else
            mirei.eb(now);
    }
    for(auto e : rala) cout << e << " ";
    for(auto e : mirei) cout << e << " ";
    for(auto e : sofi) cout << e << " ";
    cout << endl;
}