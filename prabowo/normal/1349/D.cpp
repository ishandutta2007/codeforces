#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int S = 300005;
const int MOD = 998244353;

int n;
int a[N];
int dp[S];
pair<int, int> chain[S];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

// dp[sum] = 0

// dp[0] = 1 + 1/(n-1) * dp[1] + (n-2)/(n-1) dp[0]
// dp[0] = (n-1) + dp[1]

// dp[x] = x/sum * dp[x-1] + (sum-x)/sum * (1/(n-1) * dp[x+1] + (n-2)/(n-1) * dp[x]) + 1
// (sum(n-1)) dp[x] = x(n-1) dp[x-1] + (sum-x) dp[x+1] + (sum-x)(n-2) dp[x] + sum(n-1)
// (sum(n-1) - (sum-x)(n-2)) dp[x] = x(n-1) dp[x-1] + (sum-x) dp[x+1] + sum(n-1)

// n * ans = sum(E') - C(n-1)

int main() {
  scanf("%d", &n);

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }

  chain[0] = {n-1, 1};
  for (int i = 1; i < sum; ++i) {
    int d = (1LL*sum*(n-1) - 1LL*(sum-i)*(n-2) - 1LL*i*(n-1)%MOD*chain[i-1].second) % MOD;
    if (d < MOD) d += MOD;
    d = power(d, MOD-2);

    chain[i] = {(1LL*sum*(n-1) + 1LL*i*(n-1)%MOD*chain[i-1].first)%MOD * d % MOD, 1LL*(sum-i)*d%MOD};
  }

  dp[sum] = 0;
  for (int i = sum-1; i >= 0; --i) {
    dp[i] = (chain[i].first + 1LL * chain[i].second * dp[i+1]) % MOD;
  }

  int ans = -1LL * dp[0] * (n-1) % MOD;
  for (int i = 0; i < n; ++i) {
    ans = (ans + dp[a[i]]) % MOD;
  }
  ans = 1LL * ans * power(n, MOD-2) % MOD;

  printf("%d\n", ans);
  return 0;
}