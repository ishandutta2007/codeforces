#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;

int n;
long long kk;

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

int fact[N];
int ifact[N];

int C(int n, int k) {
  return 1LL * fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

int solve() {
  scanf("%d %lld", &n, &kk);

  if (kk >= n) return 0 * printf("0\n");

  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = 1LL * fact[i-1] * i % MOD;
  ifact[n] = power(fact[n], MOD-2);
  for (int i = n-1; i >= 0; --i) ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;

  if (kk == 0) return 0 * printf("%d\n", fact[n]);

  int k = n - kk;

  int ans = 0;
  int neg = -1;
  for (int i = k; i >= 1; --i) {
    neg *= -1;
    ans = (1LL * power(i, n) * neg * C(k, i) + ans) % MOD;
  }
  ans = 2LL * ans * C(n, k) % MOD;
  if (ans < 0) ans += MOD;

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}