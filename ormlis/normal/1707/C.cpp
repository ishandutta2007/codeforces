#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 2e5 + 200;


struct dsu {
    vector<int> dsu;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        dsu.resize(n);
        range(i, n)
            dsu[i] = i;
    }

    bool unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (rand() % 2) {
            swap(a, b);
        }
        dsu[a] = b;
        return a == b;
    }
};

vi g[maxN];

int T = 1;
int tin[maxN];
int tout[maxN];
int add[maxN];
int up[maxN][20];


void dfs(int v, int p) {
    tin[v] = T++;
    up[v][0] = p;
    for (int i = 1; i < 20; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    tout[v] = T;
}

bool check(int v, int p) {
    return tin[p] <= tin[v] && tout[v] <= tout[p];
}

int get(int v, int p) {
    for(int i = 19; i >= 0; --i) {
        if (up[v][i] != p && check(up[v][i], p)) {
            v = up[v][i];
        }
    }
    return v;
}

int add2[maxN];

void dfs2(int v, int p) {
    for(auto &u : g[v]) {
        if (u == p) continue;
        add[u] += add[v];
        dfs2(u, v);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    dsu d;
    d.build(n + 1);
    vector<pair<int, int>> edges;
    rep(_, m) {
        int u, v; cin >> u >> v;
        if (!d.unio(u, v)) {
            g[v].push_back(u);
            g[u].push_back(v);
        } else {
            edges.emplace_back(u, v);
        }
    }
    dfs(1, 1);
    for(auto [x, y] : edges) {
        if (tin[x] > tin[y]) swap(x, y);
        if (check(y, x)) {
            add[1]++;
            add[y]++;
            add[get(y, x)]--;
        } else {
            add[x]++;
            add[y]++;
        }
    }
    dfs2(1, -1);
    for(int i = 1; i <= n; ++i) {
        if (add[i] == edges.size()) cout << "1";
        else cout << "0";
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}