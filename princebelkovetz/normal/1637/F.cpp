#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int mod = 1e9 + 7, N = 2e5 + 3;

vector <int> h, mx;
vector <vector <int>> g;
int ans = mod * mod, res = 0, maxH = 0;

void dfs(int v, int p) {
    for (auto u : g[v]) if (u != p) {
        dfs(u, v);
        mx[v] = max({ mx[v], mx[u], h[u] });
    }
    res += max(0ll, h[v] - mx[v]);
}

void dfsReroot(int v, int p) {
    multiset <int> vals = { 0 };
    for (auto u : g[v]) {
        vals.insert(mx[u]);
        vals.insert(h[u]);
    }
    if (g[v].size() == 1) ans = min(ans, res + maxH);
    for (auto u : g[v]) if (u != p) {
        int wasV = mx[v], wasU = mx[u];
        res -= max(0ll, h[v] - mx[v]);
        res -= max(0ll, h[u] - mx[u]);
        vals.erase(vals.find(mx[u]));
        vals.erase(vals.find(h[u]));
        mx[v] = *(--vals.end());
        mx[u] = max({ mx[u], mx[v], h[v] });
        res += max(0ll, h[v] - mx[v]);
        res += max(0ll, h[u] - mx[u]);
        dfsReroot(u, v);
        res -= max(0ll, h[v] - mx[v]);
        res -= max(0ll, h[u] - mx[u]);
        mx[v] = wasV, mx[u] = wasU;
        vals.insert(mx[u]);
        vals.insert(h[u]);
        res += max(0ll, h[v] - mx[v]);
        res += max(0ll, h[u] - mx[u]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    h.resize(n + 1);
    g.resize(n + 1);
    mx.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        maxH = max(maxH, h[i]);
    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1)
            root = i;
    }

    dfs(root, root);
    dfsReroot(root, root);
    cout << ans << '\n';


    return 0;
}