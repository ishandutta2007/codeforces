#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll M = 1e9+7;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

      ll n, a, b, k;
      cin >> n >> a >> b >> k;

      vector<vector<ll>> dp(5008, vector<ll>(5008));
      fill(dp[0].begin() + a, dp[0].begin() + n + 1, 1LL);
      for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                  dp[i][j] = dp[i][j-1];
                  if (j == b) continue;

                  ll pos;
                  if (b < j) pos = (b+j)/2 + 1;
                  else pos = 1;
                  dp[i][j] += dp[i-1][j-1] - dp[i-1][pos-1];
                  dp[i][j] %= M; if (dp[i][j] < 0) dp[i][j] += M;

                  if (b < j) pos = n;
                  else pos = (b+j-1)/2;
                  dp[i][j] += dp[i-1][pos] - dp[i-1][j];
                  dp[i][j] %= M; if (dp[i][j] < 0) dp[i][j] += M;
            }
      }
      cout << dp[k][n];

	return 0;
}