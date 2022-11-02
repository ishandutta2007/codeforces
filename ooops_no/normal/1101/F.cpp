#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> v(n);
    vector<vector<vector<int>>> go(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    for (int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--;
        go[a].pb({b, c, d});
    }
    for (int i = 0; i < n; i++){
        int dp[n + 1][n + 1];
        for (int j = 0; j <= n; j++){
            for (int k = 0; k <= n; k++){
                dp[i][j] = 1e18;
            }
        }
        for (int j = i; j < n; j++){
            dp[0][j] = v[j] - v[i];
        }
        for (int k = 1; k <= n; k++){
            int r = i;
            for (int j = i; j < n; j++){
                while(r < j && max(dp[k - 1][r], v[j] - v[r]) >= max(dp[k - 1][r + 1], v[j] - v[r + 1])){
                    r++;
                }
                dp[k][j] = max(dp[k - 1][r], v[j] - v[r]);
            }
        }
        for (auto to : go[i]){
            ans = max(ans, dp[to[2]][to[0]] * to[1]);
        }
    }
    cout << ans << endl;
    return 0;
}