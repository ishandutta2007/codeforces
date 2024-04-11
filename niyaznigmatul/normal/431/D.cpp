#include <bits/stdc++.h>

int const N = 64;

long long c[N][N];

long long f(long long n, int k) {
  ++n;
  int bits = __builtin_popcountll(n);
  int cur = 0;
  long long ans = 0;
  while (n > 0) {
    if ((n & 1) == 1) {
      --bits;
      if (k >= bits)
        ans += c[cur][k - bits];
    }
    n >>= 1;
    ++cur;
  }
  return ans;
}

int main() {
  for (int i = 0; i < N; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  long long m;
  int k;
  scanf("%lld%d", &m, &k);
  long long l = 0;
  long long r = 1;
  for (int i = 0; i < 18; i++) r *= 10;
  ++r;
  while (l < r - 1) {
    long long mid = (l + r) >> 1;
    if (f(2 * mid, k) - f(mid, k) >= m) r = mid; else l = mid;
  }
  printf("%lld\n", r);
}