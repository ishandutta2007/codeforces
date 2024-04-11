#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, b;
ll cost[105][105];
ll dp[105][105][105];
int c[105];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                  for (int k = 0; k <= 100; k++) {
                        dp[i][j][k] = 100000000000000LL;
                  }
            }
      }

      cin >> n >> m >> b;
      for (int i = 1; i <= n; i++) {
            cin >> c[i];
      }
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  cin >> cost[i][j];
            }
      }

      if (c[1] == 0) {
            for (int i = 1; i <= m; i++) {
                  dp[1][1][i] = cost[1][i];
            }
      } else {
            dp[1][1][c[1]] = 0;
      }

      // 1st dimension is coloring first i-th trees
      // 2nd dimension is beauty j
      // 3rd dimension is the color of the k-th tree

      for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= b; j++) {
                  if (c[i] == 0) {
                        for (int k = 1; k <= m; k++) {
                              dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k] + cost[i][k]);
                              for (int p = 1; p <= m; p++) {
                                    if (p != k) {
                                          dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][p] + cost[i][k]);
                                    }
                              }
                        }
                  } else {
                        dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j][c[i]]);
                        for (int k = 1; k <= m; k++) {
                              if (k != c[i]) dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j-1][k]);
                        }
                  }
            }
      }

      ll ans = 100000000000000LL;
      for (int i = 1; i <= m; i++) {
            ans = min(ans, dp[n][b][i]);
      }
      if (ans == 100000000000000LL) cout << -1;
      else cout << ans;

	return 0;
}