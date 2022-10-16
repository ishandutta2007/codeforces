#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, k; cin >> n >> k;
      map<int, int> dp[101];

      int a[n+1], b[n+1];
      for (int i = 1; i <= n; i++) cin >> a[i];
      for (int i = 1; i <= n; i++) cin >> b[i];

      for (int i = 1; i <= n; i++) {
            b[i] *= k;
            int x = a[i] - b[i];
            dp[i][x] = max(dp[i][x], a[i]);

            for (auto u: dp[i-1]) {
                  dp[i][u.first] = u.second;
            }
            for (auto u: dp[i-1]) {
                  dp[i][u.first + x] = max(dp[i][u.first + x], u.second + a[i]);
            }
      }

      cout << (dp[n][0] ? dp[n][0] : -1);

      return 0;
}