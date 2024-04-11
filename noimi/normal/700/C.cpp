#pragma region Macros
#pragma GCC optimize("O3")
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
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
using namespace std;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define Size(c) (int)(c).size()
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
template <class T> void scan(T a) { cin >> a; }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(char a[]) { scanf("%s", a); }
void scan(string &a) { cin >> a; }
template <class T> void scan(vector<T> &);
template <class T, size_t size> void scan(array<T, size> &);
template <class T, class L> void scan(pair<T, L> &);
template <class T, size_t size> void scan(T (&)[size]);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(deque<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T, size_t size> void scan(array<T, size> &a) {
    for(auto &i : a) scan(i);
}
template <class T, class L> void scan(pair<T, L> &p) {
    scan(p.first);
    scan(p.second);
}
template <class T, size_t size> void scan(T (&a)[size]) {
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
vector<int> divisor(int x) {
    vector<int> ans;
    for(int i = 1; i * i <= x; i++)
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
    inline void add(int a, int b, bool directed = false) {
        (*this)[a].emplace_back(b);
        if(!directed) (*this)[b].emplace_back(a);
    }
    void read(int n = -1, int offset = 1) {
        if(n == -1) n = this->size() - 1;
        int a, b;
        while(n--) {
            cin >> a >> b;
            Graph::add(a - offset, b - offset);
        }
    }
};
template <typename T> struct WeightedGraph : vector<Edges<T>> {
    using vector<Edges<T>>::vector;
    inline void add(int a, int b, T c, bool directed = false) {
        (*this)[a].emplace_back(b, c);
        if(!directed) (*this)[b].emplace_back(a, c);
    }
    inline void add(int a, int b, T c, int id, bool directed = false) {
        (*this)[a].emplace_back(a, b, c, id);
        if(!directed) (*this)[b].emplace_back(b, a, c, id);
    }
    void read(int n = -1, int offset = 1) {
        if(n == -1) n = this->size() - 1;
        int a, b;
        while(n--) {
            cin >> a >> b;
            Graph::add(a - offset, b - offset);
        }
    }
};
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
#pragma endregion

// ____________________

template <typename G> struct LowLink {
    const G &g;
    vector<int> used, ord, low;
    vector<int> articulation;
    vector<pair<int, int>> bridge;

    LowLink(const G &g) : g(g) {}

    int dfs(int idx, int k, int par) {
        used[idx] = true;
        ord[idx] = k++;
        low[idx] = ord[idx];
        bool is_articulation = false;
        int cnt = 0;
        for(auto &to : g[idx]) {
            if(!used[to]) {
                ++cnt;
                k = dfs(to, k, idx);
                low[idx] = min(low[idx], low[to]);
                is_articulation |= ~par && low[to] >= ord[idx];
                if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int)to));
            } else if(to != par) {
                low[idx] = min(low[idx], ord[to]);
            }
        }
        is_articulation |= par == -1 && cnt > 1;
        if(is_articulation) articulation.push_back(idx);
        return k;
    }

    virtual void build() {
        used.assign(g.size(), 0);
        ord.assign(g.size(), 0);
        low.assign(g.size(), 0);
        int k = 0;
        for(int i = 0; i < g.size(); i++) {
            if(!used[i]) k = dfs(i, k, -1);
        }
    }
};
template <typename G> struct TwoEdgeConnectedComponents : LowLink<G> {
    using LoL = LowLink<G>;
    vector<int> comp;

    TwoEdgeConnectedComponents(const G &g) : LoL(g) {}

    int operator[](const int &k) { return comp[k]; }

    void dfs(int idx, int par, int &k) {
        if(~par && this->ord[par] >= this->low[idx])
            comp[idx] = comp[par];
        else
            comp[idx] = k++;
        for(auto &to : this->g[idx]) {
            if(comp[to] == -1) dfs(to, idx, k);
        }
    }

    void build(Graph &t) {
        LoL::build();
        comp.assign(this->g.size(), -1);
        int k = 0;
        for(int i = 0; i < comp.size(); i++) {
            if(comp[i] == -1) dfs(i, -1, k);
        }
        t.resize(k);
        for(auto &e : this->bridge) {
            int x = comp[e.first], y = comp[e.second];
            t[x].push_back(y);
            t[y].push_back(x);
        }
    }
};

constexpr ll INF = 1e15;
main() {
    INT(n, m);
    INT(s, t);
    s--, t--;
    WeightedGraph<ll> g(n);
    Edges<ll> E;
    map<pair<int, int>, int> cnt;
    rep(i, m) {
        LL(x, y, c);
        x--, y--;
        cnt[pii(x, y)] = ++cnt[pii(y, x)];
        E.eb(x, y, c, i + 1);
        g.add(x, y, c, i + 1, false);
    }
    Edges<ll> flow;
    {
        vi vis(n);
        auto dfs = [&](auto &&f, edge<ll> &ed) -> bool {
            bool flag = false;
            vis[ed] = true;
            for(auto e : g[ed])
                if(e != ed.from and !vis[e]) flag |= f(f, e);
            flag |= ed == t;
            if(ed.from != -1 and flag) flow.eb(ed);
            return flag;
        };
        edge<ll> _(-1, s, 0, 0);
        if(!dfs(dfs, _)) {
            cout << 0 << endl;
            cout << 0 << endl;
            exit(0);
        };
    }
    ll ans = INF;
    vi v;
    for(auto e : flow) {
        cnt[pii(e.to, e.from)] = --cnt[pii(e.from, e.to)];
        WeightedGraph<ll> G(n);
        rep(i, m) {
            if(i + 1 == e.id) continue;
            G.add(E[i].from, E[i].to, E[i].cost, E[i].id, false);
        }
        TwoEdgeConnectedComponents<WeightedGraph<ll>> bcc(G);
        Graph buf;
        bcc.build(buf);
        set<pii> br;
        for(auto p : bcc.bridge)
            if(cnt[p] == 1) br.emplace(p), br.emplace(p.se, p.fi);
        ll res = e.cost;
        ll mi = INF;
        int mem;
        vi vis(n);
        auto dfs = [&](auto &&f, edge<ll> e) -> bool {
            bool flag = false;
            vis[e] = true;
            for(auto to : G[e]) {
                if(to == e.from or vis[to]) continue;
                flag |= f(f, to);
            }
            flag |= e == t;
            if(e.from != -1 and flag and br.count(pii(e.from, e.to)) and chmin(mi, e.cost)) mem = e.id;
            return flag;
        };
        if(!dfs(dfs, edge<ll>(-1, s, 0, 0))) {
            if(chmin(ans, res)) v = {e.id};
        } else {
            if(chmin(ans, res + mi)) v = {e.id, mem};
        }
        cnt[pii(e.from, e.to)] = --cnt[pii(e.to, e.from)];
    }
    if(ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
        cout << v.size() << endl;
        print(v);
    }
}