#include <bits/stdc++.h>
using namespace std;

using Poly = vector<int>;

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

const int PRIMITIVE_ROOT = 3; // Primitive root modulo `MOD`.

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

vector<int> operator + (vector<int> a, vector<int> b) {
  if (a.size() < b.size()) swap(a, b);
  for (int i = 0; i < b.size(); ++i) a[i] = (a[i] + b[i]) % MOD;
  return a;
}

vector<int> operator - (vector<int> a, vector<int> b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < b.size(); ++i) a[i] = (a[i] - b[i] + MOD) % MOD;
  return a;
}

vector<int> multiply_small(vector<int> a, vector<int> b) {
  vector<int> c(a.size() + b.size() - 1);
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      c[i+j] = (1LL * a[i] * b[j] + c[i+j]) % MOD;
    }
  }
  return c;
}

vector<int> multiply_large(vector<int> a, vector<int> b) {
  int deg = a.size() + b.size() - 2;
  int len = (deg == 0 ? 1 : 1 << (32 - __builtin_clz(deg)));
  a.resize(len); b.resize(len);
  FFT::fft(len, a, false); FFT::fft(len, b, false);
  a.resize(len);
  for (int i = 0; i < len; ++i) a[i] = 1LL * a[i] * b[i] % MOD; 
  FFT::fft(len, a, true);
  a.resize(deg + 1);
  return a;
}

vector<int> multiply(vector<int> a, vector<int> b) {
  if (1LL * a.size() * b.size() <= 5000) return multiply_small(a, b);
  return multiply_large(a, b);
}

vector<int> operator * (vector<int> a, vector<int> b) {
  vector<int> ret = multiply(a, b);
  ret.resize(max(a.size(), b.size()));
  return ret;
}

vector<int> inverse(int n, vector<int> a) {
  a.resize(n*2);
  vector<int> res = {power(a[0], MOD-2)};
  for (int len = 2; len < n<<1; len <<= 1) {
    vector<int> tmp = multiply(multiply(res, res), vector<int>(a.begin(), a.begin() + len));
    res.resize(len);
    for (int i = 0; i < len; ++i) res[i] = (2LL * res[i] - tmp[i] + MOD) % MOD;
  }
  res.resize(n);
  return res;
}

int main() {
  FFT::init_fft();

  int n;
  scanf("%d", &n);
  ++n;

  Poly G(n);
  G[0] = 1; G[2] = 1;
  for (int i = 4; i < n; i += 2) G[i] = (G[i - 2] + G[i - 4]) % MOD;

  Poly G0 = G, G1 = G, G2 = G;
  for (int i = 0; i < n; i += 2) {
    G0[i] = 1LL * G0[i] * i % MOD * i % MOD;
    G1[i] = 1LL * G1[i] * (i + 1) % MOD * (i + 1) % MOD;
    G2[i] = 1LL * G2[i] * (i + 2) % MOD * (i + 2) % MOD;
  }

  Poly x0 = {1}, x1 = {0, 1}, x2 = {0, 0, 1}, x3 = {0, 0, 0, 1}, x4 = {0, 0, 0, 0, 1};

  Poly den = inverse(n, x0 - x3 * G2);

  Poly F0 = (x3 * G1 * G1 * den + G0) * inverse(n, x0 - (x1 * G0 + x4 * G1 * G1 * den));
  Poly F1 = (x1 * G1 * F0 + G1) * den;
  Poly F2 = (x1 * G1 * F1 + G2) * den;

  int ans = 1LL * (G[n - 2] + G[n - 4]) * (n - 2) % MOD * (n - 2) % MOD * (n - 1) % MOD;
  for (int i = 1; i < n - 2; ++i) {
    int beauty = 1LL * i * i % MOD;
    ans = (ans + 1LL * G[i] * beauty % MOD * F0[n - i - 3] % MOD * (i + 1)) % MOD;
    if (n - i - 4 >= 0) {
      ans = (ans + 1LL * G[i - 1] * beauty % MOD * F1[n - i - 4] % MOD * (i + 1) * 2) % MOD;
    }
    if (i >= 2 && n - i - 5 >= 0) {
      ans = (ans + 1LL * G[i - 2] * beauty % MOD * F2[n - i - 5] % MOD * (i + 1)) % MOD;
    }
  }

  printf("%d\n", ans);
  return 0;
}