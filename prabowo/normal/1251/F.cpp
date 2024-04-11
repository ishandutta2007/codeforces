#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int MOD = 998244353;

int n, k;
int a[MAXN], b[MAXN];

int cntA[MAXN];

int fact[MAXN];
int ifact[MAXN];

int ans[MAXN*4];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

namespace FFT {

const int LN = 23;
const int N = 1 << LN;

// `MOD` must be of the form 2**`LN` * k + 1, where k odd.
const int MOD = 998244353; // 2**23 * 119 + 1.
const int PRIMITIVE_ROOT = 3; // Primitive root modulo `MOD`.

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
}

int main() {
  FFT::init_fft();

  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cntA[a[i]];
  }

  for (int i = 0; i < k; ++i) {
    scanf("%d", &b[i]);
  }

  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fact[i] = 1LL * fact[i-1] * i % MOD;
  }
  ifact[MAXN-1] = power(fact[MAXN-1], MOD-2);
  for (int i = MAXN-2; i >= 0; --i) {
    ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;
  }

  for (int j = 0; j < k; ++j) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < b[j]; ++i) {
      if (cntA[i] == 1) ++cnt1;
      else if (cntA[i] >= 2) ++cnt2;
    }

    vector<int> one(cnt1 + 1), two(cnt2*2 + 1);

    int p2 = 1;
    for (int i = 0; i <= cnt1; ++i) {
      one[i] = 1LL * p2 * fact[cnt1] % MOD * ifact[i] % MOD * ifact[cnt1-i] % MOD;
      p2 = 2 * p2 % MOD;
    }

    for (int i = 0; i <= cnt2*2; ++i) {
      two[i] = 1LL * fact[cnt2*2] * ifact[i] % MOD * ifact[cnt2*2 - i] % MOD;
    }


    FFT::multiply(one, two, one);

    for (int i = 0; i < one.size(); ++i) {
      ans[i + b[j] + 1] = (ans[i + b[j] + 1] + one[i]) % MOD;
    }
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    int p;
    scanf("%d", &p);
    printf("%d\n", ans[p/2]);
  }

  return 0;
}