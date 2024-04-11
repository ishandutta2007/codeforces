#include <bits/stdc++.h>
using namespace std;

#define int long long
int M = 998244353;

int dp[20][2][1080];
int ans[20][2][1080];

int solve(int n, int k) {
      string s = to_string(n);
      memset(dp, 0, sizeof(dp));
      memset(ans, 0, sizeof(ans));
      n = s.size();

      dp[0][1][0] = 1;
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < 1024; j++) {
                  for (int less = 0; less < 2; less++) {
                        for (int dig = 0; dig < 10; dig++) {
                              if (less && (dig > s[i] - '0')) continue;

                              int mask = (j == 1 ? 0 : j) | (1 << dig);
                              int ls = (dig == s[i] - '0') & less;

                              dp[i+1][ls][mask] = (dp[i+1][ls][mask] + dp[i][less][j]) % M;
                              ans[i+1][ls][mask] = (ans[i+1][ls][mask] + 10*ans[i][less][j] + dig*dp[i][less][j]) % M;
                        }
                  }
            }
      }

      int res = 0;
      for (int i = 0; i < 1024; i++) {
            if (__builtin_popcountll(i) <= k) {
                  res = (res + ans[n][0][i]) % M;
                  res = (res + ans[n][1][i]) % M;
            }
      }
      return res;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int l, r, k;
      cin >> l >> r >> k;
      int ans = (solve(r, k) - solve(l-1, k)) % M;
      if (ans < 0) ans += M;
      cout << ans;

      return 0;
}