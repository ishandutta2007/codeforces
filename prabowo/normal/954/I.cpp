#include <bits/stdc++.h>
using namespace std;

namespace FFT {

const int LN = 21;
const int N = 1 << LN;

const int MOD = 998244353; // 2**23 * 119 + 1.
const int PRIMITIVE_ROOT = 3; // Primitive root modulo `MOD`.

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

  for (int len = 1; len < n; len <<= 1) {
    int wlen = (invert ? root[N - N/len/2] : root[N/len/2]);
    for (int i = 0; i < n; i += len << 1) {
      int w = 1;
      for (int j = 0; j < len; ++j) {
        int u = a[i + j];
        int v = 1LL * a[i + j + len] * w % MOD;
        a[i + j] = (u + v) % MOD;
        a[i + j + len] = (u - v + MOD) % MOD;
        w = 1LL * w * wlen % MOD;
      }
    }
  }

  if (invert) {
    int inv = power(n, MOD - 2);
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

const int N = 125005;
const int K = 6;

char s[N];
char t[N];

int edges[N][K][K];

int main() {
  scanf("%s", s);
  scanf("%s", t);
  int n = strlen(s), m = strlen(t);

  vector<int> p[K], q[K];
  for (int i = 0; i < K; ++i) {
    p[i] = vector<int>(n);
    q[i] = vector<int>(m);
  }

  for (int i = 0; i < n; ++i) {
    p[s[i] - 'a'][i] = 1;
  }
  for (int i = 0; i < m; ++i) {
    q[t[i] - 'a'][i] = 1;
  }
  for (int i = 0; i < K; ++i) {
    reverse(q[i].begin(), q[i].end());
  }

  FFT::init_fft();
  for (int c = 0; c < K; ++c) for (int d = 0; d < K; ++d) {
    if (c == d) continue;
    vector<int> res = FFT::multiply(p[c], q[d]);
    for (int i = m - 1; i < n; ++i) {
      edges[i][c][d] = res[i];
    }
  }

  for (int i = m - 1; i < n; ++i) {
    vector<int> par(K); for (int i = 0; i < K; ++i) par[i] = i;
    function<int(int)> root = [&](int u) { return u == par[u] ? u : par[u] = root(par[u]); };
    for (int u = 0; u < K; ++u) {
      for (int v = 0; v < K; ++v) {
        if (!edges[i][u][v]) continue;
        if (root(u) == root(v)) continue;
        par[par[u]] = par[v];
      }
    }

    int ans = K;
    for (int i = 0; i < K; ++i) if (root(i) == i) --ans;
    printf("%d ", ans);
  }
  printf("\n");

  return 0;
}