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
  const int UNITY = power(PRIMITIVE_ROOT, MOD-1 >> LN);
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

vector<int> differentiate(vector<int> a) {
  for (int i = 0; i+1 < a.size(); ++i) a[i] = 1LL * a[i+1] * (i+1) % MOD;
  a.pop_back();
  return a;
}

vector<int> integral(vector<int> a) {
  a.resize(a.size() + 1);
  for (int i = (int) a.size() - 1; i > 0; --i) a[i] = 1LL * a[i-1] * power(i, MOD-2) % MOD;
  a[0] = 0;
  return a;
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

vector<int> inverse(int n, vector<int> a) {
  a.resize(n*2);
  vector<int> res = {power(a[0], MOD-2)};
  for (int len = 2; len < n<<1; len <<= 1) {
    vector<int> tmp = multiply(multiply(res, res), vector<int>(a.begin(), a.begin() + len));
    res.resize(len);
    for (int i = 0; i < len; ++i) res[i] = (2LL * res[i] - tmp[i] + MOD) % MOD;
  }
  res.resize(n);
  return res;
}

// integral P'/P
vector<int> log(int n, vector<int> a) {
  vector<int> ret = multiply(differentiate(a), inverse(n, a));
  ret.resize(n-1);
  return integral(ret);
}
 
// log(Q) - P = 0
// Q' = Q - (log(Q) - P) Q
vector<int> exp(int n, vector<int> a) {
  // Assume a[0] = 0
  vector<int> res = {1};
  a.resize(n*2);
  for (int len = 2; len < n<<1; len <<= 1) {
    vector<int> lg = log(len, res);
    vector<int> sub(len); for (int i = 0; i < len; ++i) sub[i] = (lg[i] - a[i] + MOD) % MOD;
    vector<int> tmp = multiply(sub, res);
    res.resize(len);
    for (int i = 0; i < len; ++i) res[i] = (res[i] - tmp[i] + MOD) % MOD;
  }
  res.resize(n);
  return res;
}
 
vector<int> power(int n, vector<int> a, int k) {
  // assume a[0] != 0
  vector<int> ret = log(n, a);
  for (int i = 0; i < n; ++i) ret[i] = 1LL * ret[i] * k % MOD;
  return exp(n, ret);
}

}

// // Consider one side
// dp[n][a] = dp[n-1][a-1] + dp[n-1][a] (N - n)
// dp[n](x) = dp[n-1](x) (x + N-n)
// (x)(x + 1)(x + 2)...(x + n-1)
// dp is actually stirling first kind

// (x + x^2/2 + ...)^k / k! is "column" E.G.F. of s(n, k)
// Let p(x) = (x + x^2/2 + ...)

// ans = sum_k s(k, a) * s(n-k, b) * C(n, k)
// ans: [x^n] p(x)^a / a! * p(x)^b / b!
// = [x^n] p(x)^(a+b) / (a+b)! * C(a+b, a)
// = s(n, a+b) * C(a+b, a)

int main() {
  FFT::init_fft();

  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  if (a == 0 || b == 0) return 0 * printf("0\n");
  --n, --a, --b;
  if (n < a + b) return 0 * printf("0\n");
  if (n == 0) return 0 * printf("1\n");

  vector<int> P = FFT::integral(vector<int>(n, 1)); P = vector<int>(P.begin() + 1, P.end());
  int ans = FFT::power(n-a-b+1, P, a + b)[n - a - b];

  int den = 1;
  for (int i = 1; i <= a; ++i) den = 1LL * den * i % MOD;
  for (int i = 1; i <= b; ++i) den = 1LL * den * i % MOD;
  for (int i = 1; i <= n; ++i) ans = 1LL * ans * i % MOD;
  ans = 1LL * ans * power(den, MOD - 2) % MOD;

  printf("%d\n", ans);
  return 0;
}