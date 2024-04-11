// sum f(ai) - 1 = sum_i ai/n [ (1/2 + (n-ai)/2n) f(ai - 1) + (n-ai)/2n f(ai + 1) + 1/2 f(1) + 1] + sum_i [ (n-ai)/2n + (ai^2 + (n-ai)^2)/2n^2 ] f(ai)

// a/n [ (1/2 + 1/2n (n-ai)) f(a-1) + (n-a)/2n f(a+1) + 1/2 f(1) + 1 ] + ((n-a)/2n + (2ai^2 + n^2 - 2nai) / 2n^2) f(a) = 0

// // multiply by 2n^2

// a[(2n - a) f(a - 1) + (n - a) f(a + 1) + (2a - 3n) f(a) + nf(1) + 2n] = 0

// f(1) = -2 // to eliminate constant term
// f(0) = 0 // because 0 can't be chosen

// (n - a)(f(a + 1) - f(a)) + (a - 2n)(f(a) - f(a - 1)) = 0
// g(a + 1) = (2n - a) / (n - a) g(a)
// g(1) = f(1) - f(0) = -2

// f(n + 1) = g(n + 1) + f(n)
// f(n) = g(1) + ... + g(n) + f(0)

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int MOD = 998244353;

int m;
int a[N];

int inv(int x) {
  int ret = 1;
  for (int y = MOD - 2; y > 1; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return 1LL * ret * x % MOD;
}

int main() {
  scanf("%d", &m);
  int n = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a[i]);
    n += a[i];
  }

  sort(a, a + m);
  a[m] = n;

  int ans = 0;

  int numf = -2, numg = -2, den = 1, cur = 1;
  for (int i = 0, cur = 1; i <= m; ++i) {
    for (; cur < a[i]; ++cur) {
      numg = 1LL * numg * (n*2 - cur) % MOD;
      numf = 1LL * numf * (n - cur) % MOD;
      den = 1LL * den * (n - cur) % MOD;
      numf = (numf + numg) % MOD;
    }
    if (i < m) ans = (ans + 1LL * numf * inv(den)) % MOD;
    else ans = (ans - 1LL * numf * inv(den)) % MOD;
  }

  if (ans < 0) ans += MOD;
  printf("%d\n", ans);
  return 0;
}