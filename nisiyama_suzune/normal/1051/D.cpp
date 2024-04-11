#include <bits/stdc++.h>

const int MOD = 998244353;
int N, K;
int dp[2100][2100][4];

int main () {
  std::ios::sync_with_stdio (0);
  std::cin >> N >> K;
  dp[0][1][0] = dp[0][1][3] = dp[0][2][1] = dp[0][2][2] = 1;
  for (int i = 0; i + 1 < N; ++i) for (int j = 0; j <= K; ++j) {
    (dp[i + 1][j][0] += dp[i][j][0]) %= MOD;
    (dp[i + 1][j + 1][1] += dp[i][j][0]) %= MOD;
    (dp[i + 1][j + 1][2] += dp[i][j][0]) %= MOD;
    (dp[i + 1][j + 1][3] += dp[i][j][0]) %= MOD;
    (dp[i + 1][j][0] += dp[i][j][1]) %= MOD;
    (dp[i + 1][j][1] += dp[i][j][1]) %= MOD;
    (dp[i + 1][j + 2][2] += dp[i][j][1]) %= MOD;
    (dp[i + 1][j][3] += dp[i][j][1]) %= MOD;
    (dp[i + 1][j][0] += dp[i][j][2]) %= MOD;
    (dp[i + 1][j + 2][1] += dp[i][j][2]) %= MOD;
    (dp[i + 1][j][2] += dp[i][j][2]) %= MOD;
    (dp[i + 1][j][3] += dp[i][j][2]) %= MOD;
    (dp[i + 1][j + 1][0] += dp[i][j][3]) %= MOD;
    (dp[i + 1][j + 1][1] += dp[i][j][3]) %= MOD;
    (dp[i + 1][j + 1][2] += dp[i][j][3]) %= MOD;
    (dp[i + 1][j][3] += dp[i][j][3]) %= MOD;
  }
  std::cout << ((long long) dp[N - 1][K][0] + dp[N - 1][K][1] + dp[N - 1][K][2] + dp[N - 1][K][3]) % MOD << "\n";
}