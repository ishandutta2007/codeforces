#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 1000000007;

int n, k;
int a[N];

int ifact[N];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

int S(int n, int k) {
  int neg = 1, ret = 0;
  for (int i = k; i >= 0; --i) {
    ret = (1LL * neg * ifact[i] * ifact[k-i] % MOD * power(i, n) + ret) % MOD;
    neg *= -1;
  }
  if (ret < 0) ret += MOD;
  return ret;
}

int solve() {
  scanf("%d %d", &n, &k);

  int fact = 1;
  for (int i = 2; i <= k; ++i) fact = 1LL * fact * i % MOD;
  ifact[k] = power(fact, MOD - 2);
  for (int i = k - 1; i >= 0; --i) ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int w;
    scanf("%d", &w);
    ans += w;
  }
  ans %= MOD;

  ans = (S(n, k) + 1LL * (n-1) * S(n-1, k)) % MOD * ans % MOD;
  printf("%lld\n", ans);
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