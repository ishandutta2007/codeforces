#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 5e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

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
        range(i, n)dsu[i] = i;
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

vector<pair<int, int>> g[maxN];
int tin[maxN];
int tout[maxN];

int up[maxN][20];
int h[maxN];
int x[maxN];
int T = 1;

void dfs(int v, int p) {
    tin[v] = T++;
    up[v][0] = p;
    for (int i = 1; i < 20; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
    for (auto &[u, w] : g[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        x[u] = x[v] ^ w;
        dfs(u, v);
    }
    tout[v] = T;
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (h[up[v][i]] >= h[u]) v = up[v][i];
    }
    if (u == v) return v;
    for (int i = 19; i >= 0; --i) {
        if (up[v][i] != up[u][i]) v = up[v][i], u = up[u][i];
    }
    return up[v][0];
}

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

void solve() {
    dsu d;
    int n, q;
    cin >> n >> q;
    d.build(n + 1);
    vector<bool> ans(q, false);
    vector<ar<int, 3>> qs(q);
    range(i, q) {
        int u, v, x;
        cin >> u >> v >> x;
        if (!d.unio(u, v)) {
            ans[i] = true;
            g[u].emplace_back(v, x);
            g[v].emplace_back(u, x);
        }
        qs[i] = {u, v, x};
    }
    for (int i = 1; i <= n; ++i) {
        if (tin[i]) continue;
        dfs(i, i);
    }
    fenwick F;
    F.build(T + 5);
    range(i, q) {
        if (ans[i]) {
            cout << "YES\n";
            continue;
        }
        auto[u, v, X] = qs[i];
        if ((x[u] ^ x[v] ^ X) != 1) {
            cout << "NO\n";
            continue;
        }
        auto w = lca(v, u);
        if (F.get(tin[w]) != F.get(tin[u]) || F.get(tin[w]) != F.get(tin[v])) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        while (u != w) {
            F.upd(tin[u], 1);
            F.upd(tout[u], -1);
            u = up[u][0];
        }
        while (v != w) {
            F.upd(tin[v], 1);
            F.upd(tout[v], -1);
            v = up[v][0];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}