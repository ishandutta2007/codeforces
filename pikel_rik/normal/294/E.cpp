#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 5e3 + 5;

struct edge {
    int u, v, w;
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

int n, cur, sz[N];
ll d[N][N], ans[N];

vector<pair<int, int>> g[N];
vector<int> comp[2];
vector<edge> edges;

void fdfs(int x, int p, ll h) {
    d[cur][x] = h;

    for (auto &[v, w] : g[x]) {
        if (v == p) continue;
        fdfs(v, x, h + w);
    }
}

int idx;
void dfs(int x, int p) {
    comp[idx].push_back(x);
    sz[x] = 1;

    for (auto &[v, w] : g[x]) {
        if (v == cur or v == p) continue;
        dfs(v, x);
        sz[x] += sz[v];
    }
}

int tot;
void reroot(int x, int p, int w) {
    if (p) {
        ans[x] = ans[p] + (tot - 2 * sz[x]) * (ll)w;
    }

    for (auto &[v, w] : g[x]) {
        if (v == cur or v == p) continue;
        reroot(v, x, w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0, u, v, w; i < n - 1; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        edges.emplace_back(u, v, w);
    }

    //d1 * d2

    for (int i = 1; i <= n; i++) {
        cur = i;
        fdfs(i, 0, 0);
    }

    ll best = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            best += d[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        comp[0].clear();
        comp[1].clear();

        edge e = edges[i];

        cur = e.v;
        idx = 0;
        dfs(e.u, -1);

        cur = e.u;
        idx = 1;
        dfs(e.v, -1);

        ans[e.u] = 0;
        for (int j = 0; j < comp[0].size(); j++)
            ans[e.u] += d[e.u][comp[0][j]];

        tot = sz[e.u];
        reroot(e.u, 0, 0);

        ans[e.v] = 0;
        for (int j = 0; j < comp[1].size(); j++)
            ans[e.v] += d[e.v][comp[1][j]];

        tot = sz[e.v];
        reroot(e.v, 0, 0);

        ll sum = 0, d1 = LLONG_MAX, d2 = LLONG_MAX;
        for (int j = 0; j < comp[0].size(); j++) {
            d1 = min(d1, ans[comp[0][j]]);
            sum += ans[comp[0][j]];
        }

        for (int j = 0; j < comp[1].size(); j++) {
            d2 = min(d2, ans[comp[1][j]]);
            sum += ans[comp[1][j]];
        }

        sum /= 2;
        sum = sum + comp[0].size() * d2 + comp[1].size() * d1 + comp[0].size() * (ll)comp[1].size() * e.w;
        best = min(best, sum);
    }

    cout << best << "\n";
    return 0;
}