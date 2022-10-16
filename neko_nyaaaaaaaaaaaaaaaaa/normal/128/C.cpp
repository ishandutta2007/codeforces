#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll M = 1e9+7;

ll solve(ll n, ll k) {
      vector<vector<ll>> dp(1111, vector<ll>(1111));
      dp[0][n] = 1;
      for (int i = 1; i <= k; i++) {
            vector<ll> tmp = dp[i-1];
            for (int j = n; j; j--) {
                  tmp[j] += tmp[j+1];
                  tmp[j] %= M;
            }
            for (int j = n-2; j > 0; j--) {
                  dp[i][j] = (dp[i][j+1] + tmp[j+2]) % M;
            }
      }
      ll ans = 0;
      for (int i = 1; i <= n; i++) {
            ans = (ans + dp[k][i]) % M;
      }
      return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

      ll n, m, k;
      cin >> n >> m >> k;
      cout << (solve(n, k)*solve(m, k))%M;

	return 0;
}