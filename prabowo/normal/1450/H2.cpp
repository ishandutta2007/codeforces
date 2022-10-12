#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;
const int I2 = (MOD + 1) / 2;

int n, m;
char s[N];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

int i2[N];
int fact[N], ifact[N];
int C(int n, int k) {
  if (n == -1) return k >= 0 ? k % 2 == 0 ? 1 : -1 : 0;
  if (k < 0 || k > n) return 0;
  return 1LL * fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

struct PrefixComb {
  int n, k;
  int sum = 0;

  PrefixComb(int _n, int _k): n(_n), k(_k) {
    for (int i = 0; i <= k; ++i) {
      sum = (sum + C(n, i)) % MOD;
    }
  }

  void incN() {
    sum = (2LL * sum + MOD - C(n++, k)) % MOD;
  }

  void decN() {
    sum = 1LL * I2 * (sum + C(--n, k)) % MOD;
  }

  void incK() {
    sum = (sum + C(n, ++k)) % MOD;
  }

  void decK() {
    sum = (sum + MOD - C(n, k--)) % MOD;
  }
};

int main() {
  scanf("%d %d", &n, &m);
  scanf("%s", s);

  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = 1LL * fact[i - 1] * i % MOD;
  ifact[n] = power(fact[n], MOD - 2);
  for (int i = n - 1; i >= 0; --i) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;
  i2[0] = 1;
  for (int i = 1; i <= n; ++i) i2[i] = 1LL * i2[i - 1] * I2 % MOD;

  int unknown = 0;
  int cnt[2][2] = {{0, 0}, {0, 0}};
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'b') ++cnt[i & 1][0];
    else if (s[i] == 'w') ++cnt[i & 1][1];
    else if (s[i] == '?') ++unknown;
  }

  // C(unknown, i) * (cnt[0][0] + cnt[1][1] - n/2 + i)

  int k = n/2 - cnt[0][0] - cnt[1][1];
  PrefixComb p1(unknown - 1, k), p2(unknown - 2, k - 1);
  PrefixComb q1(unknown - 1, unknown - k), q2(unknown - 2, unknown - k);

  function<int()> eval = [&]() {
    return 1LL * i2[unknown] * (
      ((1LL * k * (p1.sum - q1.sum) - 1LL * unknown * (p2.sum - q2.sum)) % MOD + MOD)
    ) % MOD;
  };
  printf("%d\n", eval());

  for (int i = 0; i < m; ++i) {
    int x; char c;
    scanf("%d %c", &x, &c);
    --x;

    if (s[x] == '?') {
      --unknown;
      p1.decN(); q1.decN(); q1.decK();
      p2.decN(); q2.decN(); q2.decK();
    } else if (s[x] == 'b' && (x & 1) == 0 || s[x] == 'w' && (x & 1) == 1) {
      ++k;
      p1.incK(); q1.decK(); p2.incK(); q2.decK();
    }

    s[x] = c;

    if (c == '?') {
      ++unknown;
      p1.incN(); q1.incN(); q1.incK();
      p2.incN(); q2.incN(); q2.incK();
    } else if (c == 'b' && (x & 1) == 0 || c == 'w' && (x & 1) == 1) {
      --k;
      p1.decK(); q1.incK(); p2.decK(); q2.incK();
    }

    printf("%d\n", eval());
  }

  return 0;
}