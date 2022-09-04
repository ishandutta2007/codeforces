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
        rep(i, num) UNIQUE(res[i]);
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
    bool is_built = false;
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
        if(!is_built) { build(), is_built = true; }
        vector<int> res(n);
        rep(i, n) {
            if(comp[i] == comp[rev(i)]) return vector<int>();
            res[i] = comp[i] > comp[rev(i)];
        }
        return res;
    }
    bool can() {
        if(!is_built) { build(), is_built = true; }
        rep(i, n) {
            if(comp[i] == comp[rev(i)]) return false;
        }
        return true;
    }
};

int main() {
    using B = bitset<2001>;
    INT(n);
    vpi w[2];
    VEC(int, m, 2);
    bool can[2];
    vector<TwoSat> Sat(2, TwoSat(n));
    rep(i, 2) {
        rep(j, m[i]) {
            INT(x, y);
            if(-x == y) continue;
            w[i].eb(x, y);
            Sat[i].OR(x, y);
        }
        can[i] = Sat[i].can();
    }
    if(can[0] ^ can[1]) {
        rep(i, 2) {
            const auto &v = Sat[i].solve();
            if(si(v)) cout << v;
        }
        exit(0);
    } else if(!can[0] and !can[1]) {
        cout << "SIMILAR\n";
    } else {
        using B = bitset<2001>;
        vvv(int, v, 2, n * 2, n * 2);
        rep(i, 2) {
            auto g = Sat[i].getGraph();
            vector<B> can(si(g));
            rep(j, n * 2) can[Sat[i][j]].set(j);
            rep(j, si(g)) for(auto &e : g[j]) can[e] |= can[j];
            rep(j, n * 2) rep(k, n * 2) v[i][j][k] = can[Sat[i][k]][j];
        }
        vv(int, fxd, 2, n + 1, -1);
        vv(int, can, 2, n * 2, 1);
        rep(i, 2) rep2(j, 1, n) {
            int t = Sat[0].id(j);
            int f = Sat[0].rev(t);
            if(v[i][t][f]) {
                fxd[i][j] = 0;
                can[i][t] = 0;
            }
            if(v[i][f][t]) {
                fxd[i][j] = 1;
                can[i][f] = 0;
            }
        }
        rep(i, 2) {
            rep2(j, 1, n) {
                if(fxd[i][j] != -1 and fxd[i][j] != fxd[i ^ 1][j]) {
                    TwoSat sat(n);
                    int t = sat.id(j);
                    int f = sat.rev(t);
                    if(fxd[i][j]) {
                        // j = 1
                        sat.IF(t, f);
                    } else
                        sat.IF(f, t);
                    for(auto &[x, y] : w[i ^ 1]) sat.OR(x, y);
                    cout << sat.solve();
                    exit(0);
                }
            }
        }
        rep(i, 2) rep(j, n * 2) rep(k, n * 2) {
            if(can[i][j] and can[i][k] and v[i][j][k] and !v[i ^ 1][j][k]) {
                // cout << i << " " << j << " " << k << endl;
                TwoSat sat(n);
                int rj = sat.rev(j), rk = sat.rev(k);
                sat.IF(rj, j), sat.IF(k, rk);
                for(auto &[x, y] : w[i ^ 1]) sat.OR(x, y);
                cout << sat.solve();
                exit(0);
            }
        }
        cout << "SIMILAR\n";
    }
}