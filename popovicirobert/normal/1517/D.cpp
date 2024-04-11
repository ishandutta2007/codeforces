#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    if (k % 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << -1 << " ";
            }
            cout << "\n";
        }
        return 0;
    }

    vector<vector<pair<int, int>>> g(n * m + 1);

    auto Get = [m](int l, int c) -> int {
        return (l - 1) * m + c;
    };

    auto addEdge = [&g, &Get](int l1, int c1, int l2, int c2, int x) {
        int id1 = Get(l1, c1);
        int id2 = Get(l2, c2);
        g[id1].push_back({id2, x});
        g[id2].push_back({id1, x});
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            int x;
            cin >> x;
            addEdge(i, j, i, j + 1, x);
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            addEdge(i, j, i + 1, j, x);
        }
    }

    constexpr int INF = 1e9;
    vector<vector<int>> dp(n * m + 1, vector<int>(k / 2 + 1, INF));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[Get(i, j)][0] = 0;
        }
    }

    for (int d = 1; d <= k / 2; d++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int nod = Get(i, j);
                for (auto it : g[nod]) {
                    dp[it.first][d] = min(dp[it.first][d], dp[nod][d - 1] + it.second);
                }
            }
        }
    }

    // cerr << dp[Get(1, 2)][2] << "\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << 2 * dp[Get(i, j)][k / 2] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}