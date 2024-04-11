#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int MOD = 998244353;

int n;

int fact[N], ifact[N];
int dp[N][N];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

int main() {
  scanf("%d", &n);

  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = 1LL * fact[i-1] * i % MOD;
  ifact[n] = power(fact[n], MOD-2);
  for (int i = n-1; i >= 0; --i) ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;

  dp[0][0] = 1; // Number of permutation with i+1 elements with j increasing adjacent
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] = (1LL * (j+1) * dp[i-1][j] + 1LL * (i-j+1) * dp[i-1][j-1]) % MOD;
    }
  }

  for (int i = 0; i < n; ++i) {
    int ans = 0;
    for (int j = 0; j < n; ++j) {
      // Count contribution of (i+1) placed at j
      ans = (ans + 1LL * dp[j][i] * fact[n] % MOD * ifact[j+1]) % MOD;
    }
    printf("%d ", ans);
  }

  printf("\n");
  return 0;
}