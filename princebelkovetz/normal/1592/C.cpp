#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, p = 239, N = 4e5 + 5;

vector <vector <int>> g;
vector <int> a, tree_x, findk, find0;

void dfs(int v, int p) {
    for (auto u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        tree_x[v] ^= tree_x[u];
    }
    tree_x[v] ^= a[v];
}

bool found(int v, int p, int k) {
    if (tree_x[v] == 0)
        find0[v] = 1;
    if (tree_x[v] == k and find0[v])
        return true;
    for (auto u : g[v]) {
        if (u == p) continue;
        find0[u] += find0[v];
        if (found(u, v, k)) return true;
        findk[v] += findk[u];
    }
    if (findk[v] > 1) return true;
    if (tree_x[v] == k)
        findk[v] = 1;
    findk[v] = bool(findk[v]);
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt--) {
        int n, k, full = 0; cin >> n >> k;

        g.resize(0);
        tree_x.resize(0);
        a.resize(0);
        find0.resize(0);
        findk.resize(0);

        a.resize(n);
        tree_x.resize(n);
        g.resize(n);
        find0.resize(n);
        findk.resize(n);
        for (auto& x : a) cin >> x, full ^= x;
        for (int i = 0, u, v; i < n - 1; ++i) {
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (full == 0) {
            cout << "YES\n";
            continue;
        }
        if (k < 3) {
            cout << "NO\n";
            continue;
        }
        dfs(0, 0);
        
        cout << (found(0, 0, full) ? "YES" : "NO") << '\n';

    }


    return 0;
}