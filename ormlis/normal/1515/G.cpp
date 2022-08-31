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
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 3e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<pair<int, int>> g[maxN];
vector<pair<int, int>> g2[maxN];
int comp[maxN];
vector<int> tocomp[maxN];
int c = 0;
int T = 1;
int used[maxN];
vector<int> ord;

void dfs(int v) {
    used[v] = T;
    for(auto &[u, l] : g[v]) {
        if (used[u] == T) continue;
        dfs(u);
    }
    ord.push_back(v);
}

void dfs2(int v) {
    used[v] = T;
    comp[v] = c;
    tocomp[c].push_back(v);
    for(auto &[u, l] : g2[v]) {
        if (used[u] == T) continue;
        dfs2(u);
    }
}

int n;
void compress() {
    for(int i = 1; i <= n; ++i) {
        for(auto &[j, l] : g[i]) {
            g2[j].emplace_back(i, l);
        }
    }
    for(int i = 1; i <= n; ++i) {
        if (used[i] == T) continue;
        dfs(i);
    }
    reverse(all(ord));
    T++;
    for(auto &v : ord) {
        if (used[v] == T) continue;
        c++;
        dfs2(v);
    }
}

ll res[maxN];
ll dist[maxN];

void dfs3(int v) {
    for(auto &[u, l] : g[v]) {
        if (comp[u] != comp[v] || dist[u]) continue;
        dist[u] = dist[v] + l;
        dfs3(u);
    }
}

void solve() {
    int m; cin >> n >> m;
    range(_, m) {
        int a, b, l; cin >> a >> b >> l;
        g[a].push_back({b, l});
    }
    compress();
    for(int i = 1; i <= c; ++i) {
        vector<ar<int, 3>> edges;
        auto verts = tocomp[i];
        ll gc = 0;
        for(auto &v : verts) {
            for(auto &[u, l] : g[v]) {
                if (comp[u] != i) continue;
                edges.push_back({v, u, l});
            }
        }
        int root = verts.front();
        dist[root] = 1;
        dfs3(root);
        for(auto &[v, u, l] : edges) {
            ll d2 = dist[u] - dist[v];
            d2 -= l;
            gc = __gcd(gc, d2);
        }
        res[i] = gc;
    }
    int q; cin >> q;
    range(_, q) {
        int v, s, t; cin >> v >> s >> t;
        v = comp[v];
        ll d = __gcd(res[v], 1ll * t);
        if ((t - s) % d == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}