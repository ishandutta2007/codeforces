// a (n - a) (f(a + 1) + f(a - 1)) + (a(a - 1) + (n - a)(n - a - 1) - n(n - 1)) f(a) + a(n - 1)
// a(n - a)(f(a + 1) + f(a - 1)) - 2a(n - a) f(a) + a(n - 1) = 0
// (n - a)(f(a + 1) - f(a)) - (n - a)(f(a) - f(a - 1)) + (n - 1) = 0

// f(0) = 0

// g(a + 1) = f(a + 1) - f(a)

// (g(a + 1) - g(a)) = (1 - n) / (n - a)
// g(a + 1) = g(a) + (1 - n) / (n - a)

// g(1)
// g(1) + (1 - n) / (n - 1)
// g(1) + (1 - n) / (n - 1) + (1 - n) / (n - 2)
// g(1) + (1 - n) / (n - 1) + (1 - n) / (n - 2) + (1 - n) / (n - 3)

// mg(1) + (1 - n)(m - 1)/(n - 1) + (1 - n)(m - 2)/(n - 2)

// f(m) = g(1) + g(2) + ... + g(m)
// f(m) = mg(1) + (1 - n) sum_{a = 1 .. m-1} (m - a) / (n - a)

// f(n) = ng(1) + (1 - n)(n - 1)
// g(1) = (n - 1)(n - 1) / n

#include <bits/stdc++.h>
using namespace std;

const int N = 2505;
const int M = 100005;
const int MOD = 1000000007;

int n;
int a[N];

int f[M], g[M];

int inv(int x) {
  int ret = 1;
  for (int y = MOD - 2; y > 1; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return 1LL * ret * x % MOD;
}

int main() {
  scanf("%d", &n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    m += a[i];
  }

  g[1] = 1LL * (m - 1) * (m - 1) % MOD * inv(m) % MOD;
  f[1] = g[1];
  for (int i = 2; i < M; ++i) {
    g[i] = (g[i - 1] + 1LL * (1 - m) * inv(m - i + 1)) % MOD;
    f[i] = (f[i - 1] + g[i]) % MOD;
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += f[a[i]];
  }
  ans %= MOD;
  if (ans < 0) ans += MOD;

  printf("%lld\n", ans);

  return 0;
}