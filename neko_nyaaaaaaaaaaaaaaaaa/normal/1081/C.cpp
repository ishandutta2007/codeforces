#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;

int n, m, k;
int dp[3000][3000];

int solve(int i, int j) {
      if (i == n) {
            return m*(j == k);
      }
      if (dp[i][j] != -1) return dp[i][j];

      int ans = 0;
      ans += solve(i+1, j); ans %= M;
      if (j < k) {
            ans += (m-1)*solve(i+1, j+1); ans %= M;
      }

      return dp[i][j] = ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      memset(dp, -1, sizeof(dp));

      cin >> n >> m >> k;
      cout << solve(1, 0) << endl;


	return 0;
}