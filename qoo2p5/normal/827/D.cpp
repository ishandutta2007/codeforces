#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-9;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define rep(i, f, t) for (int i = f; i < t; i++)
#define per(i, f, t) for (int i = f; i >= t; i--)

ll power(ll x, ll y, ll mod = MOD) {
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return power(x, y - 1, mod) * x % mod;
    } else {
        ll tmp = power(x, y / 2, mod);
        return tmp * tmp % mod;
    }
}

void add(ll &x, ll y, ll mod = MOD) {
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}

ll sum(ll x, ll y, ll mod = MOD) {
    add(x, y, mod);
    return x;
}

ll mult(ll x, ll y, ll mod = MOD) {
    return (x * y) % mod;
}

ll div(ll x, ll y, ll mod) {
    return x * power(y, mod - 2, mod);
}

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

template<typename T> void read(T first, T last) {
    while (first != last) {
        cin >> *(first++);
    }
}

template<typename T> void print(T first, T last) {
    while (first != last) {
        cout << *(first++) << " ";
    }
    cout << "\n";
}

void run();

#define TASK ""

int main() {
#ifdef LOCAL
    if (strlen(TASK) > 0) {
        cerr << "Reminder: you are using file i/o, filename: " TASK "!" << endl << endl;
    }
#endif
#ifndef LOCAL
    if (strlen(TASK)) {
        freopen(TASK ".in", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    cout << fixed << setprecision(12);
    run();
    return 0;
}

// == SOLUTION == //

const int N = (int) 2e5 + 123;
const int L = 19;

struct Edge {
    int u, v, len, id;
    
    bool operator<(const Edge &other) const {
        return mp(len, id) < mp(other.len, other.id);
    }
};

int n, m;
vector<Edge> tree[N];
vector<Edge> g[N];
int tin[N], tout[N];
Edge edge[N];
int p[N];
int depth[N];
int ans[N];
bool used[N];
int up[L][N], ma[L][N];

int get(int v) {
    if (p[v] == v) {
        return v;
    }
    return (p[v] = get(p[v]));
}

bool unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) {
        return 0;
    }
    p[v] = u;
    return 1;
}

int tmr;

void dfs(int v, int p = -1, int up_edge = INF) {
    tin[v] = tmr++;
    if (p == -1) {
        rep(i, 0, L) {
            up[i][v] = v;
            ma[i][v] = INF;
        }
    } else {
        up[0][v] = p;
        ma[0][v] = up_edge;
        rep(i, 1, L) {
            up[i][v] = up[i - 1][up[i - 1][v]];
            ma[i][v] = max(ma[i - 1][v], ma[i - 1][up[i - 1][v]]);
        }
    }
    
    for (auto &e : tree[v]) {
        assert(e.u == v);
        int u = e.v;
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v, e.len);
    }
    
    tout[v] = tmr++;
}

int go(int v, int l) {
    rep(i, 0, L) {
        if (l & (1 << i)) v = up[i][v];
    }
    return v;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = go(u, depth[u] - depth[v]);
    if (u == v) {
        return u;
    }
    per(i, L - 1, 0) {
        int uu = up[i][u];
        int vv = up[i][v];
        if (uu != vv) {
            u = uu;
            v = vv;
        }
    }
    return up[0][u];
}

int _find_max(int v, int l) {
    int res = -INF;
    rep(i, 0, L) {
        if (l & (1 << i)) {
            maxi(res, ma[i][v]);
            v = up[i][v];
        }
    }
    return res;
}

int find_max(int u, int v) {
    int w = lca(u, v);
    return max(_find_max(u, depth[u] - depth[w]), _find_max(v, depth[v] - depth[w]));
}

struct Info {
    set<pair<int, Edge>> *by_tin;
    set<Edge> *best;
    
    Info() {
        by_tin = new set<pair<int, Edge>>();
        best = new set<Edge>();
    }
    
    void just_add(Edge e, int t) {
        by_tin->insert({t, e});
        best->insert(e);
    }
    
    void cut(int l, int r) {
        while (sz(*by_tin)) {
            auto it = by_tin->lower_bound({l, Edge{-1, -1, -1, -1}});
            if (it == by_tin->end() || it->first > r) {
                break;
            }
            by_tin->erase(it);
            best->erase(it->second);
        }
    }
    
    int get() {
        if (sz(*best) == 0) {
            return INF;
        }
        return best->begin()->len;
    }
};

Info merge(Info a, Info b) {
    if (sz(*a.best) < sz(*b.best)) {
        swap(a, b);
    }
    for (auto &el : (*b.best)) {
        a.best->insert(el);
    }
    for (auto &el : (*b.by_tin)) {
        a.by_tin->insert(el);
    }
    return a;
}

Info solve(int v, int p = -1, int edge_id = -1) {
    Info cur;
    
    for (auto &e: tree[v]) {
        assert(e.u == v);
        int u = e.v;
        if (u == p) continue;
        Info tmp = solve(u, v, e.id);
        cur = merge(cur, tmp);
    }
    
    for (auto &e : g[v]) {
        assert(e.u == v);
        if (!used[e.id]) cur.just_add(e, tin[e.v]);
    }
    
    cur.cut(tin[v], tout[v]);
    
    if (edge_id != -1) {
        ans[edge_id] = cur.get() - 1;
    } else {
        assert(sz(*(cur.by_tin)) == 0 && sz(*(cur.by_tin)) == sz(*(cur.best)));
    }
    
    return cur;
}

void run() {
    rep(i, 0, N) p[i] = i;
    
    cin >> n >> m;
    vector<pair<int, int>> srt(m);
    rep(i, 0, m) {
        cin >> edge[i].u >> edge[i].v >> edge[i].len;
        edge[i].id = i;
        srt[i] = {edge[i].len, i};
        
        g[edge[i].u].pb({edge[i].u, edge[i].v, edge[i].len, i});
        g[edge[i].v].pb({edge[i].v, edge[i].u, edge[i].len, i});
    }
    sort(all(srt));
    
    for (auto &ev : srt) {
        Edge e = edge[ev.second];
        if (unite(e.u, e.v)) {
            tree[e.u].pb(Edge{e.u, e.v, e.len, e.id});
            tree[e.v].pb(Edge{e.v, e.u, e.len, e.id});
            used[e.id] = 1;
        }
    }
    
    dfs(1);
    
    rep(i, 0, m) {
        if (!used[i]) {
            ans[edge[i].id] = find_max(edge[i].u, edge[i].v) - 1;
        }
    }
    
    solve(1);
    
    rep(i, 0, m) {
        cout << (ans[i] >= INF - 5 ? -1 : ans[i]) << " ";
    }
    cout << "\n";
}