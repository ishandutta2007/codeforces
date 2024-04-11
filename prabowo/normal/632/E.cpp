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

vector<int> multiply_small(vector<int> a, vector<int> b) {
  vector<int> c(a.size() + b.size() - 1);
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      c[i+j] |= a[i] * b[j];
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
  for (int &u : a) if (u != 0) u = 1;
  return a;
}

vector<int> operator * (vector<int> a, vector<int> b) {
  if (1LL * a.size() * b.size() <= 5000) return multiply_small(a, b);
  return multiply_large(a, b);
}


vector<int> power(vector<int> a, int y) {
  vector<int> ret = {1};
  for (; y > 1; y >>= 1) {
    if (y & 1) ret = ret * a;
    a = a * a;
  }
  return ret * a;
}

int solve() {
  int n, k;
  scanf("%d %d", &n, &k);

  vector<int> a(1001, 0);
  int mini = a.size();
  for (int i = 0; i < n; ++i) {
    int w;
    scanf("%d", &w);
    a[w] = 1;
    mini = min(mini, w);
  }

  for (int i = mini; i < a.size(); ++i) {
    a[i - mini] = a[i];
  }
  a.resize(a.size() - mini);
  while (a.back() == 0) a.pop_back();

  int cnt = 0;
  a = power(a, k);

  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != 0) {
      printf("%d ", i + mini * k);
    }
  }
  printf("\n");
  return 0;
}

int main() {
  FFT::init_fft();

  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}