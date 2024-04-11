#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int PRIMITIVE_ROOT = 3;

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

const int N = 200005;

int n, m, k;
char s[N];
char t[N];

vector<int> match(char c) {
  vector<int> pre(n);
  pre[0] = s[0] == c;
  for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + (s[i] == c);
  function<int(int)> get = [&](int x) {
    if (x < 0) return 0;
    if (x >= n) return pre.back();
    return pre[x];
  };

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = get(i + k) - get(i - k - 1) > 0 ? 1 : 0;
  }
  vector<int> q(m);
  for (int i = 0; i < m; ++i) {
    q[i] = t[i] == c;
  }
  reverse(q.begin(), q.end());
  p = p * q;
  return vector<int>(p.begin() + m - 1, p.begin() + n);
}

int main() {
  FFT::init_fft();

  scanf("%d %d %d", &n, &m, &k);
  scanf("%s", s);
  scanf("%s", t);

  vector<int> res = match('A') + match('C') + match('G') + match('T');
  int ans = 0;
  for (int u : res) ans += u == m;
  printf("%d\n", ans);
  return 0;
}