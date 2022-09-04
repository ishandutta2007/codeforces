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

vector<vector<pair<edge<int>, int>>> g(200001);
template <typename T> vector<edge<T>> eulerian_path(Edges<T> es, int s, bool directed) {
    int V = 0;
    for(auto &e : es) V = max(V, max(e.to, e.from) + 1);
    for(auto &e : es) {
        int sz_to = (int)g[e.to].size();
        g[e.from].emplace_back(e, sz_to);
        if(!directed) {
            int sz_src = (int)g[e.from].size() - 1;
            swap(e.from, e.to);
            g[e.from].emplace_back(e, sz_src);
        }
    }
    vector<edge<T>> ord;
    stack<pair<int, edge<T>>> st;
    st.emplace(s, edge<T>(-1, -1));
    while(st.size()) {
        int idx = st.top().first;
        if(g[idx].empty()) {
            ord.emplace_back(st.top().second);
            st.pop();
        } else {
            auto e = g[idx].back();
            g[idx].pop_back();
            if(e.second == -1) continue;
            if(!directed) g[e.first.to][e.second].second = -1;
            st.emplace(e.first.to, e.first);
        }
    }
    ord.pop_back();
    reverse(begin(ord), end(ord));
    for(auto &e : es) g[e].clear();
    if(ord.size() != es.size()) return {};
    return ord;
}
struct UnionFind {
    vector<int> data;
    vector<int> v;
    int num;

    UnionFind(int n) : num(n), v(n) { data.assign(n, -1); }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) {
            v[x]++;
            return false;
        }
        num--;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        v[x] += v[y] + 1;
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
    INT(n, m);
    UnionFind uf(n);
    Graph g(n);
    vi deg(n);
    rep(_, m) {
        INT(a, b);
        a--, b--;
        uf.unite(a, b);
        g[a].emplace_back(b);
        deg[a]++, deg[b]++;
        //  g[b].emplace_back(a);
    }
    vv(int, odd, n);
    rep(i, n) {
        if(deg[i] & 1) odd[uf.find(i)].eb(i);
    }
    rep(i, n) {
        rep(j, si(odd[i]) / 2) {
            int a = odd[i][j * 2], b = odd[i][j * 2 + 1];
            g[a].eb(b);
            // g[b].eb(a);
            uf.unite(a, b);
            m++;
        }
    }
    rep(i, n) {
        if(uf.find(i) == i) {
            if(uf.v[uf.find(i)] & 1) {
                // g[i].emplace_back(i);
                g[i].emplace_back(i), m++;
            }
        }
    }
    {
        cout << m << endl;
        // vector<multiset<int>> G(n);
        // rep(i, n) {
        //     for(auto &e : g[i]) G[i].emplace(e);
        // }
        // auto erase = [&](int i, int j) {
        //     G[i].erase(G[i].lower_bound(j));
        //     G[j].erase(G[j].lower_bound(i));
        // };
        // rep(i, n) {
        //     int now = i;
        //     int k = 0;
        //     while(G[now].size()) {
        //         int nxt = *G[now].begin();
        //         if(k)
        //             cout << now + 1 << " " << nxt + 1 << endl;
        //         else
        //             cout << nxt + 1 << " " << now + 1 << endl;
        //         erase(now, nxt);
        //         now = nxt;
        //         k ^= 1;
        //     }
        // }
        vector<Edges<int>> E(n);
        rep(i, n) {
            int r = uf.find(i);
            for(auto &e : g[i]) { E[r].eb(edge<int>(i + 1, e + 1, 1)); }
        }
        rep(i, n) {
            if(uf.find(i) == i) {
                auto v = eulerian_path(E[i], i + 1, false);
                rep(i, si(v) / 2) {
                    cout << v[i * 2].from << " " << v[i * 2].to << endl;
                    cout << v[i * 2 + 1].to << " " << v[i * 2 + 1].from << endl;
                }
            }
        }
    }
}