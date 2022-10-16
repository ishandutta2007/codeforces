#include <bits/stdc++.h>
using namespace std;

#define int long long
int M = 1e9+7;

int a[3];
int dp[200005][3];

signed main() {
      //ios::sync_with_stdio(0); cin.tie(0);

      int n, l, r; cin >> n >> l >> r;
      for (int i = 0; i < 3; i++) {
            int left = (l - 1)/3;

            if ((l - 1) % 3 >= i) {
                  left++;
            }
            a[i] -= left;

            int right = r/3;
            if (r % 3 >= i) {
                  right++;
            }
            a[i] += right;
      }

      dp[0][0] = 1;
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                  for (int k = 0; k < 3; k++) {
                        int s = (j + k) % 3;

                        dp[i+1][s] += dp[i][j]*a[k];
                        dp[i+1][s] %= M;
                  }
            }
      }
      cout << dp[n][0];

      return 0;
}