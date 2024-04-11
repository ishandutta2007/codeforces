#pragma GCC diagnostic ignored "-Wshift-op-parentheses"

#include <bits/stdc++.h>
using namespace std;

int n, m;

const int MAXW = 1 << 17;
const int MOD = 998244353;

namespace FFT {

/* ----- Adjust the constants here ----- */
const int LN = 23;
const int N = 1 << LN;

// `MOD` must be of the form 2**`LN` * k + 1, where k odd.
const int MOD = 998244353; // 2**23 * 119 + 1.
const int PRIMITIVE_ROOT = 3; // Primitive root modulo `MOD`.
/* ----- End of constants ----- */

int root[N];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

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

// PQ = 1
// PQ - 1 = 0
// (PQ - 1)^2 = 0
// P^2 Q^2 - 2PQ + 1 = 0
// 1 = P(2Q - PQ^2)
// Q' = 2Q - PQ^2
void inverse(int n, vector<int> &a) {
  a.resize(n);
  vector<int> res = {power(a[0], MOD-2)};

  for (int len = 2; len <= n; len <<= 1) {
    vector<int> tmp_res;

    multiply(res, res, tmp_res);
    multiply(tmp_res, vector<int>(a.begin(), a.begin() + len), tmp_res);

    res.resize(len);
    for (int i = 0; i < len; ++i) {
      res[i] = (2LL * res[i] - tmp_res[i] + MOD) % MOD;
    }
  }

  a = res;
}

// Q^2 - P = 0
// Q' = Q - (Q^2 - P) / 2Q = 1/2 Q + 1/2 P/Q
void sqrt_fft(int n, vector<int> &a) {
  // supposed to be sqrt(a[0]), but for this problem a[0] = 1
  vector<int> res = {1};

  const int INV2 = power(2, MOD-2);

  for (int len = 2; len <= n; len <<= 1) {
    vector<int> tmp_res;

    vector<int> res_inv = res;
    inverse(len, res_inv);

    multiply(vector<int>(a.begin(), a.begin() + len), res_inv, tmp_res);

    res.resize(len);
    for (int i = 0; i < len; ++i) {
      res[i] = 1LL * INV2 * (res[i] + tmp_res[i]) % MOD;
    }
  }

  a = res;
}

}

int main() {
  FFT::init_fft();
  // Q = Q^2 P + 1
  // Q^2 - Q/P + 1/P = 0
  // (Q - 1/(2P))^2 + 1/P - 1/(4P^2) = 0
  // (Q - 1/(2P))^2 = (1 - 4P) / 4P^2
  // Q = (1 +- sqrt(1 - 4P)) / 2P
  // Q = 4P / 2P(1 -+ sqrt(1 - 4P))
  // For it to have inverse:
  // Q = 2 / (1 + sqrt(1 - 4P))

  vector<int> P(MAXW, 0);

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    ++P[c];
  }

  for (int i = 0; i < MAXW; ++i) {
    P[i] = (-4LL * P[i]) % MOD;
    if (P[i] < 0) P[i] += MOD;
  }
  P[0] += 1;

  FFT::sqrt_fft(MAXW, P);
  P[0] = (P[0] + 1);
  FFT::inverse(MAXW, P);

  for (int i = 1; i <= m; ++i) {
    printf("%d\n", P[i]*2 % MOD);
  }

  return 0;
}