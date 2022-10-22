#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <string>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <functional>
#include <set>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define ll long long

using namespace std;
const int N = 2e5, mod = 1e9 + 7, p = 464;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n, m; cin >> n >> m;
    vector <vector <ll>> g(n + 1, vector <ll>(n + 1, (ll)mod * mod));
    vector <vector <int>> es;
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        g[u][v] = w;
        g[v][u] = w;
        es.push_back({ u, v, w });
    }
    for (int i = 1; i <= n; ++i) g[i][i] = 0;

    int q; cin >> q;
    vector <vector <pair <int, int>>> qs(n + 1);
    for (int i = 0, u, v, w; i < q; ++i) {
        cin >> u >> v >> w;
        qs[u].push_back({ v, w });
        qs[v].push_back({ u, w });
    }
    vector <vector <ll>> d(n + 1, vector <ll>(n + 1, (ll)mod * mod));
    for (int i = 1; i <= n; ++i) {
        vector <bool> used(n + 1);
        for (auto& x : qs[i]) d[i][x.first] = -x.second;
        for (int iters = 0; iters < n; ++iters) {
            int id = 0;
            for (int k = 1; k <= n; ++k)
                if (!used[k] and (!id or d[i][id] > d[i][k])) id = k;
            for (int k = 1; k <= n; ++k)
                d[i][k] = min(d[i][k], d[i][id] + g[id][k]);
            used[id] = true;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                g[k][j] = min(g[k][j], g[i][k] + g[i][j]);
            }
        }
    }

    vector <bool> good(m);
    for (int i = 0; i < m; ++i) {
        int a = es[i][0], b = es[i][1], w = es[i][2];
        for (int v = 1; v <= n; ++v) {
            ll R = -w - g[v][a];
            if (d[v][b] <= R) good[i] = true;
        }
    }
    int ans = 0;
    for (auto x : good) ans += x;
    cout << ans << '\n';
    return 0;
}