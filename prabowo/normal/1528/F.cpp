#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

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

}

vector<int> multiply(vector<int> a, vector<int> b) {
  int len = (a.size() + b.size() == 2 ? 1 : 1 << (32 - __builtin_clz(a.size() + b.size() - 2)));
  a.resize(len); b.resize(len);
  FFT::fft(len, a, false); FFT::fft(len, b, false);
  a.resize(len);
  for (int i = 0; i < len; ++i) a[i] = 1LL * a[i] * b[i] % MOD; 
  FFT::fft(len, a, true);
  return a;
}

// sum(C(n, i) * i^k * n^(n - i))

// (n + x)^n = sum(C(n, i) * n^(n-i) * x^i)

// n(n + x)^(n-1) x

// n(n-1)(n + x)^(n-2) x^2 + n(n + x)^(n-1) x

// n(n-1)(n-2)(n + x)^(n-3) x^3 + 3n(n-1)(n + x)^(n-2) x^2 + n(n + x)^(n-1) x

// sum(C(n, i) * i! * S(k, i) * (n + 1)^(n - i))

// sum(S(k, i) x^i) = exp(-x) sum_i i^k / i! x^i

const int N = 100005;

int fact[N];
int ifact[N];

int main() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = 1LL * fact[i - 1] * i % MOD;
  ifact[N - 1] = power(fact[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; --i) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;

  FFT::init_fft();

  int n, k;
  scanf("%d %d", &n, &k);

  vector<int> e(k + 1), f(k + 1);
  for (int i = 0; i <= k; ++i) {
    e[i] = i & 1 ? MOD - ifact[i] : ifact[i];
    f[i] = 1LL * power(i, k) * ifact[i] % MOD;
  }
  vector<int> S = multiply(e, f);

  int ans = 0;
  int P = 1, in = power(n + 1, MOD - 2), n1 = power(n + 1, n);
  for (int i = 0; i <= k; ++i) {
    ans = (ans + 1LL * P * S[i] % MOD * n1) % MOD;
    P = 1LL * P * (n - i) % MOD;
    n1 = 1LL * n1 * in % MOD;
  }

  printf("%d\n", ans);
  return 0;
}