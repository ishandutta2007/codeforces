#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g[maxN];

int d = -1, f = -1;

void dfs_find(int v, int p, int dd) {
    if (dd > d) {
        d = dd;
        f = v;
    }
    for (auto &u : g[v]) {
        if (u == p) continue;
        dfs_find(u, v, dd + 1);
    }
}

vector<int> path;
vector<int> ans;

void find_path(int v, int p) {
    path.push_back(v);
    if (v == f) {
        ans = path;
    }
    for (auto &u : g[v]) {
        if (u == p) continue;
        find_path(u, v);
    }
    path.pop_back();
}

int dist[maxN];

void dfs_dist(int v, int p) {
    for (auto &u : g[v]) {
        if (u == p) continue;
        dist[u] = dist[v] + 1;
        dfs_dist(u, v);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs_find(1, -1, 0);
    int a = f;
    d = -1;
    dfs_find(a, -1, 0);
    int b = f;
    f = b;
    find_path(a, -1);
    int sz = ans.size();
    if ((ll) sz != 1ll * k * 2 + 1) {
        cout << "No\n";
        return;
    }
    int root = ans[sz / 2];
    dist[root] = 0;
    dfs_dist(root, -1);
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) {
            if (dist[i] != k) {
                cout << "No\n";
                return;
            }
        } else {
            int cur = g[i].size();
            if (i != root) cur--;
            if (cur < 3) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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