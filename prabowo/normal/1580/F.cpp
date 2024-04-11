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

const int MOD = 998244353;
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

vector<int> operator * (vector<int> a, vector<int> b) {
  if (1LL * a.size() * b.size() <= 5000) return multiply_small(a, b);
  return multiply_large(a, b);
}

vector<int> inverse(vector<int> a, int n=-1) {
  if (n == -1) n = a.size();
  a.resize(n*2);
  vector<int> res = {power(a[0], MOD-2)};
  for (int len = 2; len < n<<1; len <<= 1) {
    vector<int> tmp = (res * res) * vector<int>(a.begin(), a.begin() + len);
    res.resize(len);
    for (int i = 0; i < len; ++i) res[i] = (2LL * res[i] - tmp[i] + MOD) % MOD;
  }
  res.resize(n);
  return res;
}

using Poly = vector<int>;

const int N = 100005;

int fact[N], ifact[N];

void init() {
  FFT::init_fft();
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = 1LL * fact[i - 1] * i % MOD;
  ifact[N - 1] = power(fact[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; --i) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;
}

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return 1LL * ifact[k] * ifact[n - k] % MOD * fact[n] % MOD;
}

int main() {
  init();

  int n, m;
  scanf("%d %d", &n, &m);

  int ans = -1;
  if (n % 2 == 0) {
    Poly P(n / 2 + 1); // for PIE for < > < > ...
    P[0] = 1;
    for (int i = 1; i < P.size(); ++i) {
      P[i] = 1LL * P[i - 1] * fact[2 * i - 2] % MOD * (m + i) % MOD * (m - i + 1) % MOD * ifact[2 * i] % MOD; // C(m + i, 2 * i);
    }
    Poly Q = P; Q[0] = 0;
    for (int i = 1; i < Q.size(); ++i) Q[i] = 1LL * Q[i] * i % MOD;

    ans = (Q * inverse(P))[n / 2];
    if (n / 2 % 2 == 0) ans = (MOD - ans) % MOD;
  } else {
    Poly P(n + 1);
    P[0] = 1;
    for (int i = 2; i < P.size(); i += 2) {
      P[i] = 1LL * P[i - 2] * fact[i - 2] % MOD * (m/2 + i/2) % MOD * (m/2 - i/2 + 1) % MOD * ifact[i] % MOD; // C(m/2 + i/2, i);
    }
    Poly Q(n + 1);
    Q[1] = m/2;
    for (int i = 3; i < Q.size(); i += 2) {
      Q[i] = 1LL * Q[i - 2] * fact[i - 2] % MOD * (m/2 + i/2) % MOD * (m/2 - i/2) % MOD * ifact[i] % MOD; //C(m/2 + i/2, i);
    }

    P = Q * inverse(P); P.resize(n + 1);
    if (m % 2 == 1) P[1] = (P[1] + 1) % MOD;
    for (int i = 3; i < P.size(); i += 4) P[i] = (MOD - P[i]) % MOD; // P is now g.f. for odd chains < > < ...

    Q = P;
    for (int i = 1; i < Q.size(); i += 2) Q[i] = 1LL * Q[i] * i % MOD;
    ans = (Q * inverse(Poly({1}) - P))[n];
  }

  printf("%d\n", ans);
  return 0;
}