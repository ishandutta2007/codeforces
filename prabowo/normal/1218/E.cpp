#include <bits/stdc++.h>
using namespace std;

const int N = 20005;
const int MOD = 998244353;

int n, k;

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

}


vector<int> sum[N << 2];
void build(int node, int l, int r, vector<int> &a) {
  if (l == r) {
    sum[node] = {1, a[l]};
    return;
  }

  int mid = l + r >> 1;
  build(node*2 + 1, l, mid+0, a);
  build(node*2 + 2, mid+1, r, a);
  FFT::multiply(sum[node*2 + 1], sum[node*2 + 2], sum[node]);
  sum[node].resize(min(k+1, (int) sum[node].size()));
}

int main() {
  FFT::init_fft();

  scanf("%d %d", &n, &k);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  int q;
  scanf("%d", &q);
  while (q--) {
    int t, q;
    scanf("%d %d", &t, &q);

    vector<int> b = a;

    if (t == 1) {
      int i, d;
      scanf("%d %d", &i, &d);
      --i;
      b[i] = d;

    } else if (t == 2) {
      int l, r, d;
      scanf("%d %d %d", &l, &r, &d);
      --l, --r;

      for (int i = l; i <= r; ++i) (b[i] += d) %= MOD;
    }

    for (int &num: b) {
      num = (q - num) % MOD;
      if (num < 0) num += MOD;
    }
    build(0, 0, n-1, b);
    if (sum[0][k] < 0) sum[0][k] += MOD;
    printf("%d\n", sum[0][k]);
  }
  return 0;
}