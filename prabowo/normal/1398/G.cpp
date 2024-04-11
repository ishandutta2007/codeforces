#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 19;
const int L = 1000001;

int n, x, y;
int a[N], b[N];

int ans[L];

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
  for (int i=1; i<N; i++) {
    root[i] = 1LL * UNITY * root[i-1] % MOD;
  }
}

// n is the length of polynom
void fft(int n, int a[], bool invert) {
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

}

int main() {
  scanf("%d %d %d", &n, &x, &y);
  for (int i = 0; i <= n; ++i) {
    int num;
    scanf("%d", &num);
    a[num] = 1, b[N/2 - num] = 1;
  }

  FFT::init_fft();
  FFT::fft(N, a, false); FFT::fft(N, b, false);
  for (int i = 0; i < N; ++i) {
    a[i] = 1LL * a[i] * b[i] % FFT::MOD;
  }
  FFT::fft(N, a, true);

  for (int i = 2*y + 2; i < L; i += 2) {
    int idx = i/2 - y + N/2;
    if (idx >= N) break;
    if (a[i/2 - y + N/2] > 0) {
      for (int j = i; j < L; j += i) ans[j] = i;
    }
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    int l;
    scanf("%d", &l);
    if (ans[l] > 0) printf("%d ", ans[l]);
    else printf("-1 ");
  }
  printf("\n");
  return 0;
}