#include <bits/stdc++.h>
using namespace std;

const int N = 17;
const int MOD = 1000000007;
const int I2 = 742744451; // 2^-17

int a[1 << N]; // AND
int x[1 << N]; // XOR
int s[1 << N]; // SUBSET

int f[1 << N]; // FIBO
int p[N + 1][1 << N]; // POPCOUNT


void xorTransform(int n, int a[]) {
  for (int len = 1; len < 1 << n; len <<= 1) {
    for (int i = 0; i < 1 << n; i += len << 1) {
      for (int j = 0; j < len; ++j) {
        int u = a[i + j], v = a[i + j + len];
        a[i + j] = (u + v) % MOD;
        a[i + j + len] = (u - v + MOD) % MOD;
      }
    }
  }
}

void andTransform(int n, int a[]) {
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < 1 << n; ++mask) {
      if (mask >> i & 1) a[mask ^ (1 << i)] = (a[mask ^ (1 << i)] + a[mask]) % MOD;
    }
  }
}

void iandTransform(int n, int a[]) {
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < 1 << n; ++mask) {
      if (mask >> i & 1) a[mask ^ (1 << i)] = (a[mask ^ (1 << i)] - a[mask] + MOD) % MOD;
    }
  }
}

void zetaTransform(int n, int a[]) {
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < 1 << n; ++mask) {
      if (mask >> i & 1) a[mask] = (a[mask] + a[mask ^ (1 << i)]) % MOD;
    }
  }
}

void izetaTransform(int n, int a[]) {
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < 1 << n; ++mask) {
      if (mask >> i & 1) a[mask] = (a[mask] - a[mask ^ (1 << i)] + MOD) % MOD;
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int s;
    scanf("%d", &s);
    ++a[s];
  }

  for (int i = 0; i < 1 << N; ++i) {
    x[i] = a[i];
    p[__builtin_popcount(i)][i] = a[i];
  }

  // xor convolution
  xorTransform(N, x);
  for (int i = 0; i < 1 << N; ++i) x[i] = 1LL * x[i] * x[i] % MOD;
  xorTransform(N, x);
  for (int i = 0; i < 1 << N; ++i) x[i] = 1LL * I2 * x[i] % MOD;

  // subset convolution
  for (int i = 0; i <= N; ++i) zetaTransform(N, p[i]);
  for (int i = N; i >= 0; --i) for (int mask = 0; mask < 1 << N; ++mask) {
    int sum = 0;
    for (int j = 0; j <= i; ++j) sum = (1LL * p[j][mask] * p[i - j][mask] + sum) % MOD;
    p[i][mask] = sum;
  }
  for (int i = 0; i <= N; ++i) izetaTransform(N, p[i]);
  for (int i = 0; i < 1 << N; ++i) s[i] = p[__builtin_popcount(i)][i];

  f[0] = 0; f[1] = 1; for (int i = 2; i < 1 << N; ++i) f[i] = (f[i - 1] + f[i - 2]) % MOD;
  for (int i = 0; i < 1 << N; ++i) {
    x[i] = 1LL * x[i] * f[i] % MOD;
    s[i] = 1LL * s[i] * f[i] % MOD;
    a[i] = 1LL * a[i] * f[i] % MOD;
  }

  andTransform(N, x);
  andTransform(N, s);
  andTransform(N, a);
  for (int i = 0; i < 1 << N; ++i) a[i] = 1LL * a[i] * x[i] % MOD * s[i] % MOD;
  iandTransform(N, a);

  long long ans = 0;
  for (int i = 0; i < N; ++i) ans += a[1 << i];

  printf("%lld\n", ans % MOD);
  return 0;
}