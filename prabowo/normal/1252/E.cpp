#pragma GCC diagnostic ignored "-Wshift-op-parentheses"

#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[3000005];


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

// Borrowed from neal's code
static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
  return x % m;
#endif
  // Optimized mod for Codeforces 32-bit machines.
  // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
  unsigned x_high = x >> 32, x_low = (unsigned) x;
  unsigned quot, rem;
  asm("divl %4\n"
      : "=a" (quot), "=d" (rem)
      : "d" (x_high), "a" (x_low), "r" (m));
  return rem;
}

void init_fft() {
  const int UNITY = power(PRIMITIVE_ROOT, MOD-1 >> LN);
  root[0] = 1;
  for (int i=1; i<N; i++) {
    root[i] = fast_mod(1LL * UNITY * root[i-1]);
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
        int v = fast_mod(1LL * a[i+j + len/2] * w);

        a[i+j] = fast_mod(u + v);
        a[i+j + len/2] = fast_mod(u - v + MOD);

        w = fast_mod(1LL * w * wlen);
      }
    }
  }

  if (invert) {
    int inv = power(n, MOD-2);
    for (int i=0; i<n; i++) a[i] = fast_mod(1LL * a[i] * inv);
  }
}

void multiply(vector<int> a, vector<int> b, vector<int> &c) {
  int cdeg = a.size() + b.size() - 2;
  int len = 1 << 32 - __builtin_clz(cdeg);
  a.resize(len, 0); b.resize(len, 0);
  fft(len, a, false); fft(len, b, false);
  c.resize(len);
  for (int i = 0; i < len; ++i) c[i] = 1LL * a[i] * b[i] % MOD; 
  fft(len, c, true);
  c.resize(cdeg+1);
}

}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int p;
    scanf("%d", &p);
    ++cnt[p];
  }

  vector<int> cnts;
  for (int i = 2; i < 3000005; ++i) {
    if (cnt[i] > 0) cnts.push_back(cnt[i]);
  }

  sort(cnts.begin(), cnts.end());

  vector<int> res = {1};

  auto greaterSize = [&](const vector<int> &u, const vector<int> &v) {
    return u.size() > v.size();
  };
  priority_queue<vector<int>, vector<vector<int>>, decltype(greaterSize)> pq(greaterSize);

  for (int c: cnts) pq.push(vector<int>(c+1, 1));

  FFT::init_fft();
  while (pq.size() > 1) {
    vector<int> u = pq.top();
    pq.pop();
    vector<int> v = pq.top();
    pq.pop();

    FFT::multiply(u, v, u);
    pq.push(u);
  }

  printf("%d\n", pq.top()[n >> 1]);
  return 0;  
}