#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;

int n;
char s[N];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

int fact[N], ifact[N];
int C(int n, int k) {
  return 1LL * fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

int main() {
  scanf("%d %*d", &n);
  scanf("%s", s);

  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = 1LL * fact[i - 1] * i % MOD;
  ifact[n] = power(fact[n], MOD - 2);
  for (int i = n - 1; i >= 0; --i) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;

  int cnt[2][2] = {{0, 0}, {0, 0}};
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'b') ++cnt[i & 1][0];
    else if (s[i] == 'w') ++cnt[i & 1][1];
  }

  int cntOdd = n/2 - cnt[0][0] - cnt[0][1];
  int cntEven = n/2 - cnt[1][0] - cnt[1][1];
  int ans = 0, total = 0;
  for (int i = 0; i <= cntOdd + cntEven; ++i) {
    int intersect = abs(cnt[0][0] - cnt[1][0] + (i - cntEven));
    if (intersect & 1) continue;

    ans = (1LL * intersect/2 * C(cntOdd + cntEven, i) + ans) % MOD;
    total = (C(cntOdd + cntEven, i) + total) % MOD;
  }
  ans = 1LL * ans * power(total, MOD - 2) % MOD;

  printf("%d\n", ans);
  return 0;
}