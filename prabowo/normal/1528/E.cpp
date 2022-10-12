#include <cstdio>

const int N = 1000005;
const int MOD = 998244353;

int n;

int dp[N];

inline int C2(int n) {
  return 1LL * n * (n + 1) / 2 % MOD;
}

inline int C3(int n) {
  return 1LL * n * (n + 1) % MOD * (n + 2) % MOD * ((MOD + 1) / 6) % MOD;
}

int main() {
  scanf("%d", &n);

  dp[0] = 1;
  int pre = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = (dp[i - 1] + 1LL * dp[i - 1] * pre + C2(dp[i - 1])) % MOD;
    pre = (pre + dp[i - 1]) % MOD;
  }

  pre = (pre + MOD - dp[n - 1]) % MOD;
  int ans = (dp[n] + 1LL * dp[n - 1] * C2(pre) + 1LL * C2(dp[n - 1]) * pre + C3(dp[n - 1])) % MOD;
  ans = (ans * 2LL + MOD - 1) % MOD;

  for (int i = 1; i < n; ++i) {
    ans = (ans + 1LL * (dp[i] + MOD - dp[i - 1]) * (dp[n - i - 1] + MOD - 1)) % MOD;
  }

  printf("%d\n", ans);
  return 0;
}