#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MAGIC = 4096;
const int MOD = 998244353;
const int I2 = (MOD + 1) / 2;

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

namespace FFT {

const int LN = 21;
const int N = 1 << LN;

const int PRIMITIVE_ROOT = 3;

int root[N];

void init_fft() {
  const int UNITY = power(PRIMITIVE_ROOT, (MOD-1) >> LN);
  root[0] = 1;
  for (int i = 1; i < N; ++i) {
    root[i] = 1LL * UNITY * root[i-1] % MOD;
  }
}

// n is the length of polynom
void fft(int n, vector<int> &a, bool invert) {
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    int wlen = (invert ? root[N - N/len] : root[N/len]);
    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < len >> 1; ++j) {
        int u = a[i + j], v = 1LL * a[i + j + len/2] * w % MOD;

        a[i + j] = (u + v) % MOD;
        a[i + j + len/2] = (u - v + MOD) % MOD;
        w = 1LL * w * wlen % MOD;
      }
    }
  }

  if (invert) {
    int inv = power(n, MOD-2);
    for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * inv % MOD;
  }
}

}

char s[N], t[N];
short distances[N / MAGIC][N];

void init() {
  FFT::init_fft();

  int n = strlen(s), m = strlen(t);

  int deg = 1 << (32 - __builtin_clz(m + MAGIC - 2));

  vector<int> Q(deg);
  reverse(t, t + m);
  for (int i = 0; i < m; ++i) {
    Q[i] = (t[i] - '0') * 2 - 1;
  }
  reverse(t, t + m);
  FFT::fft(deg, Q, false);

  for (int i = 0; i + MAGIC <= n; i += MAGIC) {
    vector<int> P(deg);
    for (int j = i; j < i + MAGIC; ++j) {
      P[j - i] = s[j] == '0' ? MOD - 1 : 1;
    }
    FFT::fft(deg, P, false);

    for (int j = 0; j < deg; ++j) P[j] = 1LL * P[j] * Q[j] % MOD;
    FFT::fft(deg, P, true);

    int len = min(MAGIC, n - i);
    for (int j = 0; j < m; ++j) {
      P[j] = 1LL * (len - P[j] + MOD) * I2 % MOD;
      if (P[j] > m) P[j] -= MOD;
      distances[i / MAGIC][m - j - 1] = P[j];
    }
  }
}

int main() {
  scanf("%s", s);
  scanf("%s", t);
  init();

  int q;
  scanf("%d", &q);
  while (q--) {
    int a, b, len;
    scanf("%d %d %d", &a, &b, &len);
    int ans = 0;
    while (len > 0) {
      if (a % MAGIC != 0 || len < MAGIC) {
        ans += s[a++] != t[b++];
        --len;
        continue;
      }

      ans += distances[a / MAGIC][b];
      a += MAGIC; b += MAGIC; len -= MAGIC;
    }

    printf("%d\n", ans);
  }
  return 0;
}