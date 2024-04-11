#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000005;
const int MOD = 998244353;

int n;
int fact[N], ifact[N];

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

const int PRIMITIVE_ROOT = 3; // Primitive root modulo `MOD`.

int root[N];

void init_fft() {
  const int UNITY = power(PRIMITIVE_ROOT, MOD-1 >> LN);
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
      for (int j = 0; j < len>>1; ++j) {
        int u = a[i+j];
        int v = 1LL * a[i+j + len/2] * w % MOD;

        a[i+j] = (u + v) % MOD;
        a[i+j + len/2] = (u - v + MOD) % MOD;

        w = 1LL * w * wlen % MOD;
      }
    }
  }

  if (invert) {
    int inv = power(n, MOD-2);
    for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * inv % MOD;
  }
}

vector<int> multiply(vector<int> a, vector<int> b) {
  int len = (a.size() + b.size() == 2 ? 1 : 1 << (32 - __builtin_clz(a.size() + b.size() - 2)));
  a.resize(len); b.resize(len);
  fft(len, a, false); fft(len, b, false);
  a.resize(len);
  for (int i = 0; i < len; ++i) a[i] = 1LL * a[i] * b[i] % MOD; 
  fft(len, a, true);
  return a;
}

}

int C(int n, int k) {
  return 1LL * fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

void init() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = 1LL * fact[i - 1] * i % MOD;
  ifact[N - 1] = power(fact[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; --i) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;
  FFT::init_fft();
}

int solve() {
  scanf("%d", &n);

  vector<int> v(1, 1);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    int sz = v.size();
    int nsz = sz + a - b;

    vector<int> mul(sz + nsz);
    for (int k = 0; k < mul.size(); ++k) {
      int col = b - (int) v.size() + 1 + k;
      if (col < 0 || col > a + b) continue;
      mul[k] = C(a + b, col);
    }
    v = FFT::multiply(v, mul);

    for (int i = 0; i < nsz; ++i) v[i] = v[i + sz - 1];
    v.resize(nsz);


    // for (int j = 0; j < nv.size(); ++j) {
    //   for (int k = 0; k < v.size(); ++k) {
    //     if (k >= v.size()) break;
    //     if (b + j - k < 0) continue;
    //     if (b + j - k > a + b) continue;
    //     nv[j] = (1LL * C(a + b, b + j - k) * v[k] + nv[j]) % MOD;
    //   }
    // }
  }

  int ans = 0;
  for (int u : v) ans = (ans + u) % MOD;
  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  init();
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}