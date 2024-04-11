#include <bits/stdc++.h>
using namespace std;

const int N = 401;
const int MOD = 998244353;

int n;
int c[26];

int dp[2][2][2];
int dp2[2][N][3][3];
int dp3[2][N][N][4][4];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < 26; ++i) {
    scanf("%d", &c[i]);
  }

  for (int st0 = 0; st0 < 2; ++st0) for (int st1 = 0; st1 < 2; ++st1) {
    dp[0][st0][st1] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int st0 = 0; st0 < 2; ++st0) for (int st1 = 0; st1 < 2; ++st1) {
      dp[i & 1][st0][st1] = (st0 == 0 ? 26LL : 25LL) * dp[i & 1 ^ 1][st1][1] % MOD;
    }

    for (int c1 = 0; c1 <= n; ++c1) {
      for (int st0 = 0; st0 < 3; ++st0) for (int st1 = 0; st1 < 3; ++st1) {
        int use1 = dp2[i & 1 ^ 1][c1][st1][1];
        int use2 = (c1 == 0 ? dp[i & 1 ^ 1][st1 > 0][1] : dp2[i & 1 ^ 1][c1 - 1][st1][2]);

        if (st0 == 2) dp2[i & 1][c1][st0][st1] = 25LL * use1 % MOD;
        else if (st0 == 1) dp2[i & 1][c1][st0][st1] = (24LL * use1 + use2) % MOD;
        else if (st0 == 0) dp2[i & 1][c1][st0][st1] = (25LL * use1 + use2) % MOD;
      }
    }

    for (int c1 = 0; c1 <= n; ++c1) {
      for (int c2 = 0; c2 <= n; ++c2) {
        for (int st0 = 0; st0 < 4; ++st0) for (int st1 = 0; st1 < 4; ++st1) {
          int use1 = dp3[i & 1 ^ 1][c1][c2][st1][1];
          int use2 = (c1 == 0 ? dp2[i & 1 ^ 1][c2][st1 == 2 ? 1 : st1 == 3 ? 2 : st1][1] : dp3[i & 1 ^ 1][c1 - 1][c2][st1][2]);
          int use3 = (c2 == 0 ? dp2[i & 1 ^ 1][c1][st1 == 3 ? 1 : st1][1] : dp3[i & 1 ^ 1][c1][c2 - 1][st1][3]);

          if (st0 == 3) dp3[i & 1][c1][c2][st0][st1] = (24LL * use1 + use2) % MOD;
          else if (st0 == 2) dp3[i & 1][c1][c2][st0][st1] = (24LL * use1 + use3) % MOD;
          else if (st0 == 1) dp3[i & 1][c1][c2][st0][st1] = (23LL * use1 + use2 + use3) % MOD;
          else if (st0 == 0) dp3[i & 1][c1][c2][st0][st1] = (24LL * use1 + use2 + use3) % MOD;
        }
      }
    }
  }

  long long ret = dp[n & 1][0][0];
  for (int i = 0; i < 26; ++i) {
    ret -= dp2[n & 1][c[i]][0][0];
    for (int j = i + 1; j < 26; ++j) {
      ret += dp3[n & 1][c[i]][c[j]][0][0];
    }
  }

  ret %= MOD;
  if (ret < 0) ret += MOD;
  printf("%lld\n", ret);
  return 0;
}