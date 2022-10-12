#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;

int n;
int dp[N];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

int solve() {
  scanf("%d", &n);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i] = (dp[i-1] + dp[i-2]) % MOD;
  }

  int ans = (n > 1 ? dp[n] - dp[n-2] : 1);
  if (ans < 0) ans += MOD;

  ans = 1LL * ans * power(power(2, n), MOD - 2) % MOD;
  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}