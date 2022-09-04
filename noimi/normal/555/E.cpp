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
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
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

// template <typename T> struct edge {
//     int from, to;
//     T cost;
//     int id;
//     edge(int to, T cost) : from(-1), to(to), cost(cost) {}
//     edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
//     edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
//     edge &operator=(const int &x) {
//         to = x;
//         return *this;
//     }
//     operator int() const { return to; }
// };
// template <typename T> using Edges = vector<edge<T>>;

// using Tree = vector<vector<int>>;
// using Graph = vector<vector<int>>;
// template <class T> using Wgraph = vector<vector<edge<T>>>;
// Graph getG(int n, int m = -1, bool directed = false, int margin = 1) {
//     Tree res(n);
//     if(m == -1) m = n - 1;
//     while(m--) {
//         int a, b;
//         cin >> a >> b;
//         a -= margin, b -= margin;
//         res[a].emplace_back(b);
//         if(!directed) res[b].emplace_back(a);
//     }
//     return move(res);
// }
// template <class T> Wgraph<T> getWg(int n, int m = -1, bool directed = false, int margin = 1) {
//     Wgraph<T> res(n);
//     if(m == -1) m = n - 1;
//     while(m--) {
//         int a, b;
//         T c;
//         cin >> a >> b >> c;
//         a -= margin, b -= margin;
//         res[a].emplace_back(b, c);
//         if(!directed) res[b].emplace_back(a, c);
//     }
//     return move(res);
// }

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
#pragma endregion

#pragma once

template <typename T = int> struct Edge {
    int from, to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

    operator int() const { return to; }
};

template <typename T = int> struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(int n) : g(n), es(0) {}

    size_t size() const { return g.size(); }

    void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }

    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
        for(int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if(weighted) cin >> c;
            if(directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
};

template <typename T = int> using Edges = vector<Edge<T>>;

/**
 * @brief Low-Link(/)
 * @see http://kagamiz.hatenablog.com/entry/2013/10/05/005213
 * @docs docs/low-link.md
 */
template <typename T = int> struct LowLink : Graph<T> {
  public:
    using Graph<T>::Graph;
    vector<int> ord, low, articulation;
    vector<Edge<T>> bridge;
    using Graph<T>::g;

    virtual void build() {
        used.assign(g.size(), 0);
        ord.assign(g.size(), 0);
        low.assign(g.size(), 0);
        int k = 0;
        for(int i = 0; i < (int)g.size(); i++) {
            if(!used[i]) k = dfs(i, k, -1);
        }
    }

    explicit LowLink(const Graph<T> &g) : Graph<T>(g) {}

  private:
    vector<int> used;

    int dfs(int idx, int k, int par) {
        used[idx] = true;
        ord[idx] = k++;
        low[idx] = ord[idx];
        bool is_articulation = false, beet = false;
        int cnt = 0;
        for(auto &to : g[idx]) {
            if(to == par && !exchange(beet, true)) { continue; }
            if(!used[to]) {
                ++cnt;
                k = dfs(to, k, idx);
                low[idx] = min(low[idx], low[to]);
                is_articulation |= par >= 0 && low[to] >= ord[idx];
                if(ord[idx] < low[to]) bridge.emplace_back(to);
            } else {
                low[idx] = min(low[idx], ord[to]);
            }
        }
        is_articulation |= par == -1 && cnt > 1;
        if(is_articulation) articulation.push_back(idx);
        return k;
    }
};

/**
 * @brief Two-Edge-Connected-Components()
 * @docs docs/two-edge-connected-components.md
 */
template <typename T = int> struct TwoEdgeConnectedComponents : LowLink<T> {
  public:
    using LowLink<T>::LowLink;
    using LowLink<T>::g;
    using LowLink<T>::ord;
    using LowLink<T>::low;
    using LowLink<T>::bridge;

    vector<int> comp;
    Graph<T> tree;
    vector<vector<int>> group;

    int operator[](const int &k) const { return comp[k]; }

    void build() override {
        LowLink<T>::build();
        comp.assign(g.size(), -1);
        int k = 0;
        for(int i = 0; i < (int)comp.size(); i++) {
            if(comp[i] == -1) dfs(i, -1, k);
        }
        group.resize(k);
        for(int i = 0; i < (int)g.size(); i++) { group[comp[i]].emplace_back(i); }
        tree = Graph<T>(k);
        for(auto &e : bridge) { tree.add_edge(comp[e.from], comp[e.to], e.cost); }
    }

    explicit TwoEdgeConnectedComponents(const Graph<T> &g) : Graph<T>(g) {}

  private:
    void dfs(int idx, int par, int &k) {
        if(par >= 0 && ord[par] >= low[idx])
            comp[idx] = comp[par];
        else
            comp[idx] = k++;
        for(auto &to : g[idx]) {
            if(comp[to] == -1) dfs(to, idx, k);
        }
    }
};
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
};

int main() {
    INT(n, m, q);
    TwoEdgeConnectedComponents<> g(n);
    g.read(m, -1);
    g.build();
    int N = g.group.size();
    vector<vi> G(N);
    for(auto &e : g.bridge) G[g[e.from]].eb(g[e.to]), G[g[e.to]].eb(g[e.from]);
    HLDecomposition<vector<vi>> hld(G);
    UnionFind uf(N);
    for(auto &e : g.bridge) uf.unite(g[e.from], g[e.to]);
    hld.build();
    vv(int, a, N, 2);
    bool flag = true;
    while(q--) {
        INT(x, y);
        x--, y--;
        x = g[x], y = g[y];
        if(!uf.same(x, y)) flag = false;
        int p = hld.lca(x, y);
        a[x][0]++;
        a[p][0]--;
        a[p][1]--;
        a[y][1]++;
    }
    if(!flag) {
        cout << "No\n";
        exit(0);
    }
    vi used(N);
    auto dfs = [&](auto &&f, int x, int p) -> pii {
        used[x] = true;
        pii res(0, 0);
        res.fi += a[x][0], res.se += a[x][1];
        for(auto e : G[x]) {
            if(e == p) continue;
            auto p = f(f, e, x);
            res.fi += p.fi, res.se += p.se;
        }
        if(res.fi and res.se) {
            cout << "No\n";
            exit(0);
        }
        return res;
    };
    rep(i, N) {
        if(!used[i]) dfs(dfs, i, -1);
    }
    cout << "Yes\n";
}