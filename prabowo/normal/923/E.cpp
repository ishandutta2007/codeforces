#pragma GCC diagnostic ignored "-Wshift-op-parentheses"

#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
const int MOD = 998244353;

int n;
long long m;

int fact[N];
int ifact[N];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

namespace FFT {

/* ----- Adjust the constants here ----- */
const int LN = 23;
const int N = 1 << LN;

// `MOD` must be of the form 2**`LN` * k + 1, where k odd.
const int MOD = 998244353; // 2**23 * 119 + 1.
const int PRIMITIVE_ROOT = 3; // Primitive root modulo `MOD`.
/* ----- End of constants ----- */

int root[N];

void init_fft() {
  const int UNITY = power(PRIMITIVE_ROOT, MOD-1 >> LN);
  root[0] = 1;
  for (int i=1; i<N; i++) {
    root[i] = 1LL * UNITY * root[i-1] % MOD;
  }
}

// n = 2^k is the length of polynom
void fft(int n, vector<int> &a, bool invert) {
  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j>=bit; bit>>=1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }

  for (int len=2; len<=n; len<<=1) {
    int wlen = (invert ? root[N - N/len] : root[N/len]);
    for (int i=0; i<n; i+=len) {
      int w = 1;
      for (int j=0; j<len>>1; j++) {
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
    for (int i=0; i<n; i++) a[i] = 1LL * a[i] * inv % MOD;
  }
}

void multiply(vector<int> a, vector<int> b, vector<int> &c) {
  int len = 1 << 32 - __builtin_clz(a.size() + b.size() - 2);
  a.resize(len, 0); b.resize(len, 0);
  fft(len, a, false); fft(len, b, false);
  c.resize(len);
  for (int i = 0; i < len; ++i) c[i] = 1LL * a[i] * b[i] % MOD; 
  fft(len, c, true);
}

// c[i] = sum_k a[k] * b[i+k]
void correlation(vector<int> a, vector<int> b, vector<int> &c) {
  reverse(a.begin(), a.end());
  multiply(a, b, c);

  for (int i = 0; i < b.size(); ++i) {
    c[i] = c[i-1 + a.size()];
  }
  c.resize(b.size());
}

}

int main() {
  FFT::init_fft();
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = 1LL * fact[i-1] * i % MOD;
  }

  ifact[N-1] = power(fact[N-1], MOD-2);
  for (int i = N-2; i >= 0; --i) ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;

  scanf("%d %lld", &n, &m);
  ++n;

  vector<int> P(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &P[i]);
  }

  // Our transition matrix is obvious:
  // [[1, 1/2, 1/3, ...], [0, 1/2, 1/3, ...], [0, 0, 1/3, ...], ...]

  // Multiply by its inverse eigenvectors
  {
    vector<int> P_ifact(ifact, ifact + n);

    for (int i = 0; i < n; ++i) {
      P[i] = 1LL * P[i] * fact[i] % MOD;
    }

    FFT::correlation(P_ifact, P, P);

    for (int i = 0; i < n; ++i) {
      P[i] = 1LL * P[i] * ifact[i] % MOD;
    }
  }

  // Multiply by its eigenvalues
  {
    for (int i = 0; i < n; ++i) {
      P[i] = 1LL * P[i] * power(power(i+1, MOD-2), m % (MOD-1)) % MOD;
    }
  }

  // Multiply by its eigenvectors
  {
    vector<int> P_ifact(ifact, ifact + n);

    for (int i = 0; i < n; ++i) {
      P[i] = 1LL * P[i] * fact[i] % MOD * power(MOD-1, i) % MOD;
    }

    FFT::correlation(P_ifact, P, P);

    for (int i = 0; i < n; ++i) {
      P[i] = 1LL * P[i] * ifact[i] % MOD * power(MOD-1, i) % MOD;
    }
  }

  for (int i = 0; i < n; ++i) printf("%d ", P[i]);
  printf("\n");

  return 0;
}