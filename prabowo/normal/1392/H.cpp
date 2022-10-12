#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
const int MOD = 998244353;

int n, m;

int fact[N], ifact[N];

int inv(int x) {
  int ret = 1;
  for (int y = MOD-2; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

int C(int n, int k) {
  return 1LL * fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

int main() {
  scanf("%d %d", &n, &m);

  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = 1LL * fact[i-1] * i % MOD;
  ifact[n] = inv(fact[n]);
  for (int i = n-1; i >= 0; --i) ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;

  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int term = 1LL * C(n, i) * (m + i) % MOD * (1LL * ifact[i] * fact[i-1] % MOD) % MOD;
    if (i & 1) ans += term;
    else ans -= term;
  }

  ans %= MOD;
  ans = (ans * (1LL * n * inv(m + 1) % MOD + 1)) % MOD;
  if (ans < 0) ans += MOD;

  printf("%lld\n", ans);
  return 0;
}