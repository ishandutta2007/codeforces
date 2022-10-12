// dp[n][k] := Sequence of n numbers with k bits on

// dp[n][k] = sum(dp[n-1][k-i] * 2^(k-i) * C(k, k-i)) - dp[n-1][k]
// ans = sum(dp[N][i] * C(K, i))

// e.g.f of dp[n](x) = dp[n-1](2x) * (exp(x) - 1)
// dp[0] = 1
// dp[1] = exp(x) - 1
// dp[2] = (exp(2x) - 1)(exp(x) - 1)
// dp[3] = (exp(4x) - 1)(exp(2x) - 1)(exp(x) - 1)

// dp[n] = prod(exp(2^i x) - 1)

// dp[n+m](x) = dp[n](x) * dp[m](2^n x)

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 1 << 16;

typedef complex<double> ftype;
const double PI = acos(-1);
ftype w[MAXN];

int power(int x, int y, int mod=MOD) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % mod;
    x = 1LL * x * x % mod;
  }
  return ret;
}

void init() {
  for (int i = 0; i < MAXN; ++i) {
    w[i] = ftype(cos(2*PI*i / MAXN), sin(2*PI*i / MAXN));
  }
}

void fft(int n, vector<ftype> &a) {
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }

  for (int len=2; len<=n; len<<=1) {
    int wlen = MAXN/len;
    for (int i=0; i<n; i+=len) {
      for (int j=0; j<len>>1; j++) {
        ftype u = a[i+j];
        ftype v = a[i+j + len/2] * w[wlen * j];

        a[i+j] = u + v;
        a[i+j + len/2] = u - v;
      }
    }
  }
}

const int sz = 16, msk = (1 << 16) - 1;

vector<int> multiply(vector<int> a, vector<int> b) {
  int n = 1 << (32 - __builtin_clz(a.size() + b.size()));
  a.resize(n, 0); b.resize(n, 0);

  vector<ftype> A(n), B(n);
  for(int i = 0; i < n; i++) {
    A[i] = ftype(a[i] & msk, a[i] >> sz);
    B[i] = ftype(b[i] & msk, b[i] >> sz);
  }

  fft(n, A); fft(n, B);
  
  ftype im2 = {0, 2}, im = {0, 1};
  
  vector<ftype> nA(n), nB(n);
  for(int i = 0; i < n; i++) {
    ftype lA = (A[i] + conj(A[(n - i) % n])) / 2.;
    ftype gA = (A[i] - conj(A[(n - i) % n])) / im2;
    ftype lB = (B[i] + conj(B[(n - i) % n])) / 2.;
    ftype gB = (B[i] - conj(B[(n - i) % n])) / im2;
    nA[i] = lA * lB + im * gA * gB;
    nB[i] = lA * gB + gA * lB;
  }
  fft(n, nA); fft(n, nB);
  reverse(begin(nA) + 1, end(nA));
  reverse(begin(nB) + 1, end(nB));
  vector<int> ans(n);
  for(int i = 0; i < n; i++) {
    long long a = llround(nA[i].real() / n) % MOD;
    long long b = llround(nB[i].real() / n) % MOD;
    long long c = llround(nA[i].imag() / n) % MOD;
    ans[i] = (a + (b << sz) + (c << 2 * sz)) % MOD;
  }

  // ans.resize(a.size() + b.size() - 1);
  return ans;
}

long long n;
int k;

int fact[MAXN], ifact[MAXN];

vector<int> powerdp(vector<int> x, long long y) {
  vector<int> ret = {1};
  int two = 2;
  for (; y; y >>= 1) {

    if (y & 1) {
      int ttwo = 1;
      for (int &t: ret) {
        t = 1LL * t * ttwo % MOD;
        ttwo = 1LL * ttwo * two % MOD;
      }

      ret = multiply(x, ret);
      ret.resize(k+1);
    }

    int ttwo = 1;
    vector<int> tx = x;
    for (int &t: tx) {
      t = 1LL * t * ttwo % MOD;
      ttwo = 1LL * ttwo * two % MOD;
    }

    x = multiply(x, tx);
    x.resize(k+1);

    two = 1LL * two * two % MOD;
  }

  return ret;
}

int main() {
  init();
  scanf("%lld %d", &n, &k);
  if (n > k) return 0 * printf("0\n");

  fact[0] = 1;
  for (int i = 1; i <= k; ++i) fact[i] = 1LL * fact[i-1] * i % MOD;
  ifact[k] = power(fact[k], MOD-2);
  for (int i = k-1; i >= 0; --i) ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;

  vector<int> dp(k+1);
  for (int i = 1; i <= k; ++i) {
    dp[i] = ifact[i];
  }
  dp = powerdp(dp, n);

  int ans = 0;
  for (int i = n; i <= k; ++i) {
    ans = (ans + 1LL * dp[i] * fact[k] % MOD * ifact[k-i]) % MOD;
  }

  printf("%d\n", ans);
  return 0;
}