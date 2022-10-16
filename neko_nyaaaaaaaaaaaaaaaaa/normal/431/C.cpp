#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll m = 1e9 + 7;

int main() {
      ll n, k, d;
      cin >> n >> k >> d;
      vector<vector<ll>> dp(1000, vector<ll>(2, 0));
      dp[0][0] = 1;
      for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= min(i, k); j++) {
                  if (j < d) {
                        dp[i][0] += dp[i-j][0];
                        dp[i][0] %= m;
                        dp[i][1] += dp[i-j][1];
                        dp[i][1] %= m;
                  } else {
                        dp[i][1] += dp[i-j][0];
                        dp[i][1] %= m;
                        dp[i][1] += dp[i-j][1];
                        dp[i][1] %= m;
                  }
            }
      }
      cout << dp[n][1]%m;
}