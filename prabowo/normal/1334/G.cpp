#include <bits/stdc++.h>
using namespace std;

namespace FFT {

const int LN = 23;
const int N = 1 << LN;

const int MOD = 998244353;
const int PRIMITIVE_ROOT = 3;

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
  for (int i = 1; i < N; ++i) {
    root[i] = 1LL * UNITY * root[i-1] % MOD;
  }
}

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

} // namespace FFT

const int N = 200005;

int p[26];
char s[N], t[N];

// (s - t)^2 (ps - t)^2 = (s^2 - 2st + t^2)(ps^2 - 2pst + t^2)
// (s^2 ps^2) + (-2s ps^2 - 2s^2 ps) t + (s^2 + 4s ps + ps^2) t^2 + (-2s - 2ps) t^3 + t^4

int main() {
  for (int i = 0; i < 26; ++i) scanf("%d", &p[i]), --p[i];
  scanf("%s", s);
  scanf("%s", t);

  int m = strlen(s);
  reverse(s, s + m);
  vector<int> s0, s1, s2, s3, s4;
  for (int i = 0; i < m; ++i) {
    int c = s[i] - 'a';
    int d = p[c];
    s0.push_back(c*c * d*d);
    s1.push_back(-2*c*d*(c+d) + FFT::MOD);
    s2.push_back(c*c + 4*c*d + d*d);
    s3.push_back(-2*(c+d) + FFT::MOD);
    s4.push_back(1);
  }

  int n = strlen(t);
  vector<int> t0, t1, t2, t3, t4;
  for (int i = 0; i < n; ++i) {
    int c = t[i] - 'a';
    t0.push_back(1);
    t1.push_back(c);
    t2.push_back(c*c);
    t3.push_back(c*c*c);
    t4.push_back(c*c*c*c);
  }

  FFT::init_fft();
  // vector<int> res0 = FFT::multiply(s0, t0);
  vector<int> res1 = FFT::multiply(s1, t1);
  vector<int> res2 = FFT::multiply(s2, t2);
  vector<int> res3 = FFT::multiply(s3, t3);
  // vector<int> res4 = FFT::multiply(s4, t4);

  int res0 = 0;
  for (int i = 0; i < m; ++i) res0 = (res0 + s0[i]) % FFT::MOD;

  vector<int> res4(n);
  for (int i = 0; i < n; ++i) {
    res4[i] = t4[i];
    if (i > 0) res4[i] = (t4[i] + res4[i-1]) % FFT::MOD;
    if (i >= m) res4[i] = (res4[i] - t4[i-m] + FFT::MOD) % FFT::MOD;
  }

  reverse(s, s + m);
  for (int i = m - 1; i < n; ++i) {
    int sum = (1LL * res0 + res1[i] + res2[i] + res3[i] + res4[i]) % FFT::MOD;
    if (sum == 0) {
      int idx = rand() % m;
      if (s[idx] == t[idx + i - (m-1)] || p[s[idx] - 'a'] + 'a' == t[idx + i - (m-1)]) {
        printf("1");
        continue;
      }
    }
    printf("0");
  }
  printf("\n");
  return 0;
}