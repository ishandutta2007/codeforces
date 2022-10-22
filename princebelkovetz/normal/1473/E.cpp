#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#pragma GCC optimize("O3")
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 2e5 + 2, mod = 1e18 + 7;
int dp[N][2][2];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int n, m; cin >> n >> m;
    vector <vector <pair <int, int>>> g(n + 1);
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    set <vector <int>> heap;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = mod;
                heap.insert({ mod, i, j, k });
            }
        }
    }
    heap.erase({ mod, 1, 0, 0 });
    heap.insert({ 0, 1, 0, 0 });
    dp[1][0][0] = 0;
    while (!heap.empty()) {
        vector <int> v = *heap.begin();
        heap.erase(v);
        for (auto &u : g[v[1]]) {
            for (int i = v[2]; i < 2; ++i) {
                for (int j = v[3]; j < 2; ++j) {
                    int x = dp[u.first][i][j], cur = v[0];
                    if (i != v[2]) cur -= u.second;
                    if (j != v[3]) cur += u.second;
                    if (x > cur + u.second) {
                        heap.erase({ x, u.first, i, j });
                        heap.insert({ cur + u.second, u.first, i, j });
                        dp[u.first][i][j] = cur + u.second;
                    }
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << dp[i][1][1] << ' ';
    }
    return 0;
}