#pragma region Macros
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("popcnt,fma,abm,mmx,avx,avx2,tune=native")
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

template <typename G> struct HLDecomposition {
    G &g;
    vector<int> sz, in, out, head, rev, par;

    HLDecomposition(G &g) : g(g), sz(g.size()), in(g.size()), out(g.size()), head(g.size()), rev(g.size()), par(g.size()) {}

    void dfs_sz(int idx, int p) {
        par[idx] = p;
        sz[idx] = 1;
        if(g[idx].size() and g[idx][0] == p) swap(g[idx][0], g[idx].back());
        for(auto &to : g[idx]) {
            if(to == p) continue;
            dfs_sz(to, idx);
            sz[idx] += sz[to];
            if(sz[g[idx][0]] < sz[to]) swap(g[idx][0], to);
        }
    }

    void dfs_hld(int idx, int par, int &times) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        for(auto &to : g[idx]) {
            if(to == par) continue;
            head[to] = (g[idx][0] == to ? head[idx] : to);
            dfs_hld(to, idx, times);
        }
        out[idx] = times;
    }

    template <typename T> void dfs_hld(int idx, int par, int &times, vector<T> &v) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        for(auto &to : g[idx]) {
            if(to == par) {
                v[in[idx]] = to.cost;
                continue;
            }
            head[to] = (g[idx][0] == to ? head[idx] : to);
            dfs_hld(to, idx, times, v);
        }
        out[idx] = times;
    }

    template <typename T> void dfs_hld(int idx, int par, int &times, vector<T> &v, vector<T> &a) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        v[in[idx]] = a[idx];
        for(auto &to : g[idx]) {
            if(to == par) continue;
            head[to] = (g[idx][0] == to ? head[idx] : to);
            dfs_hld(to, idx, times, v, a);
        }
        out[idx] = times;
    }

    void build() {
        dfs_sz(0, -1);
        int t = 0;
        dfs_hld(0, -1, t);
    }

    template <typename T> vector<T> build() {
        dfs_sz(0, -1);
        int t = 0;
        vector<T> res(g.size());
        dfs_hld(0, -1, t, res);
        return res;
    }

    template <typename T> vector<T> build(vector<T> &a) {
        dfs_sz(0, -1);
        int t = 0;
        vector<T> res(g.size());
        dfs_hld(0, -1, t, res, a);
        return res;
    }

    int la(int v, int k) {
        while(1) {
            int u = head[v];
            if(in[v] - k >= in[u]) return rev[in[v] - k];
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
    }

    int lca(int u, int v) {
        for(;; v = par[head[v]]) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) return u;
        }
    }

    template <typename T, typename Q, typename F> T query(int u, int v, const T &e, const Q &q, const F &f, bool edge = false) {
        T l = e, r = e;
        for(;; v = par[head[v]]) {
            if(in[u] > in[v]) swap(u, v), swap(l, r);
            if(head[u] == head[v]) break;
            l = f(q(in[head[v]], in[v] + 1), l);
        }
        return f(f(q(in[u] + edge, in[v] + 1), l), r);
    }

    template <typename T, typename Q, typename Q2, typename F> T query(int u, int v, const T &e, const Q &q1, const Q2 &q2, const F &f, bool edge = false) {
        T l = e, r = e;
        for(;;) {
            if(head[u] == head[v]) break;
            if(in[u] > in[v]) {
                l = f(l, q2(in[head[u]], in[u] + 1));
                u = par[head[u]];
            } else {
                r = f(q1(in[head[v]], in[v] + 1), r);
                v = par[head[v]];
            }
        }
        if(in[u] > in[v]) return f(f(l, q2(in[v] + edge, in[u] + 1)), r);
        return f(f(l, q1(in[u] + edge, in[v] + 1)), r);
    }

    template <typename Q> void add(int u, int v, const Q &q, bool edge = false) {
        for(;; v = par[head[v]]) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) break;
            q(in[head[v]], in[v] + 1);
        }
        q(in[u] + edge, in[v] + 1);
    }
};

template <typename T = long long, const int sz = 5 * 10000000> struct IO {
    char reader[sz], writer[sz];
    char *now, *now2 = writer;
    IO() {
        reader[fread(reader, sizeof(char), sizeof(char) * sz, stdin)];
        now = reader;
    }
    inline T read() {
        while(*now && *now <= 32) now++;
        if(*now == '-') {
            now++;
            T res = 0;
            while('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
            return -res;
        } else {
            T res = 0;
            while('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
            return res;
        }
    }
    inline void read(T &res) {
        while(*now && *now <= 32) now++;
        if(*now == '-') {
            now++;
            res = 0;
            while('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
            res = -res;
        } else {
            res = 0;
            while('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
        }
    }
    inline string read_str() {
        string res;
        while(*now and *now != '\n' and *now != ' ') res += *now++;
        now++;
        return res;
    }
    inline void write(T x, char margin = ' ') {
        if(x == 0) {
            putchar('0');
            putchar(margin);
            return;
        }
        if(x < 0) {
            putchar('-');
            x = -x;
        }
        while(x) {
            *now2 = '0' + x % 10;
            now2++;
            x /= 10;
        }
        do {
            now2--;
            putchar(*now2);
        } while(now2 != writer);
        putchar(margin);
    }
    inline void write_str(string s, char margin = ' ') {
        for(auto c : s) putchar(c);
        putchar(margin);
    }
};
IO<int> io;
inline int read() { return io.read(); }
inline void write(int x) { io.write(x); }

using B = bitset<300001>;
int main() {
    int n = read(), Q = read();
    vi a(n);
    rep(i, n) a[i] = read();
    vi par(n, -1);
    Graph g(n);
    rep(i, n - 1) {
        int x = read() - 1, y = read() - 1;
        g[x].eb(y), g[y].eb(x);
    }
    HLDecomposition hld(g);
    hld.build();
    vi mem(n, -1);
    const int T = 50;
    vector<B> bit(6100);
    vi f(6100);

    int cnt = 0;
    auto dfs = [&](auto &&f, int x, int p, B &b) -> int {
        b.flip(a[x]);
        par[x] = p;
        int res = 0;
        for(auto e : g[x]) {
            if(e != p) { chmax(res, f(f, e, x, b)); }
        }
        if(res == T or x == 0) {
            mem[x] = cnt;
            bit[cnt] = b;
            cnt++;
            res = -1;
        }
        b.flip(a[x]);
        return res + 1;
    };
    B b;
    dfs(dfs, 0, -1, b);

    vv(int, v, 6100);
    rep(i, 6010) {
        if(bit[i].count() < 50) {
            f[i] = true;
            for(int j = bit[i]._Find_first(); j < bit[i].size(); j = bit[i]._Find_next(j)) { v[i].eb(j); }
        }
    }
    auto calc = [&](int x) {
        while(mem[x] == -1) {
            b.flip(a[x]);
            x = par[x];
        }
        if(f[mem[x]]) {
            for(auto e : v[mem[x]]) b.flip(e);
        }
        else b ^= bit[mem[x]];
    };
    while(Q--) {
        int u = read() - 1, v = read() - 1, l = read(), r = read();
        int lca = hld.lca(u, v);
        b.reset();
        calc(u), calc(v);
        b.flip(a[lca]);
        int k = b._Find_next(l - 1);
        if(k <= r) {
            cout << k << endl;
        } else
            cout << -1 << endl;
    }
}