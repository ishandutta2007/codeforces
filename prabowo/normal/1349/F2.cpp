#include <bits/stdc++.h>
using namespace std;

const int LN = 18;
const int N = 1 << LN; 
const int MOD = 998244353; // 2**23 * 119 + 1.

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

namespace FFT {
 
const int PRIMITIVE_ROOT = 3; // Primitive root modulo `MOD`.
 
int root[N];
 
void init_fft() {
  const int UNITY = power(PRIMITIVE_ROOT, (MOD-1) >> LN);
  root[0] = 1;
  for (int i=1; i<N; i++) {
    root[i] = 1LL * UNITY * root[i-1] % MOD;
  }
}
 
// n = 2^k is the length of polynom
void fft(int n, vector<int> &a, bool invert) {
  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j & bit; bit>>=1) j -= bit;
    j |= bit;
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

// PQ = 1
// (PQ - 1)^2 = 0
// 1 = P(2Q - PQ^2)
// Q' = 2Q - PQ^2
vector<int> inverse(int n, vector<int> a) {
  a.resize(n*2);
  vector<int> res = {::power(a[0], MOD-2)};
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
  vector<int> ret = log(n, a);
  for (int i = 0; i < n; ++i) ret[i] = 1LL * ret[i] * k % MOD;
  return exp(n, ret);
}
}

void print(vector<int> v) {
  for (int num: v) printf("%d ", num); printf("\n");
}

int main() {
  // Solution follows editorial
  FFT::init_fft();

  int n;
  scanf("%d", &n);

  vector<int> fact(n+3), ifact(n+3);
  fact[0] = 1; for (int i = 1; i < fact.size(); ++i) fact[i] = 1LL * fact[i-1] * i % MOD;
  ifact.back() = power(fact.back(), MOD-2);
  for (int i = (int) ifact.size() - 2; i >= 0; --i) ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;

  vector<int> F(n+2);
  {
    // Init F with (e^z - 1) / z
    for (int i = 0; i < F.size(); ++i) F[i] = ifact[i+1];
  }

  vector<int> infF(n+1);
  {
    // Init with sum F^k = F/(1-F) = 1/z (F / (1-F)/z)
    for (int i = 0; i <= n; ++i) infF[i] = MOD - F[i+1];
    infF = FFT::multiply(F, FFT::inverse(n+1, infF));
    // infF[0] no longer needed, safe to remove
    for (int i = 0; i < n; ++i) infF[i] = infF[i+1]; infF.resize(n);
  }

  vector<int> phi(n+2);
  {
    // Init with phi(zF) = F; phi(z) = z / log(1 + z) = 1 / (log(1+z)/z)
    for (int i = 0; i < phi.size(); ++i) {
      phi[i] = power(i+1, MOD-2);
      if (i & 1) phi[i] = MOD - phi[i];
    }
    phi = FFT::inverse(phi.size(), phi);
  }
  // print(phi);

  vector<int> phid = FFT::differentiate(phi);
  
  vector<int> phin = FFT::power(n+1, phi, n+1);
  // print(phin);

  vector<int> iphi(n+1);
  {
    // Init with z / (1 - phi) = (1/(1-phi)/z)
    for (int i = 0; i <= n; ++i) iphi[i] = MOD - phi[i+1];
    iphi = FFT::inverse(n+1, iphi);
  }

  vector<int> p1 = FFT::multiply(phin, iphi);
  for (int i = 0; i < n; ++i) p1[i] = p1[i+1]; p1.resize(n);

  vector<int> p2 = FFT::multiply(phin, phid); p2.resize(n+1);
  iphi = FFT::multiply(iphi, iphi); iphi.resize(n+1);
  p2 = FFT::multiply(p2, iphi);
  for (int i = 0; i < n; ++i) p2[i] = p2[i+1]; p2.resize(n);

  vector<int> p(n);
  {
    // Init with the stirling sum GF
    int in = power(n+1, MOD-2);
    for (int i = 0; i < n; ++i) {
      p[i] = (1LL * p1[i] * (n-i+1) + p2[i]) % MOD;
      p[i] = (infF[i] - 1LL * p[i] * in % MOD + MOD) * fact[i] % MOD;
    }
    reverse(p.begin(), p.end());
  }

  vector<int> q(n);
  {
    // Init with the in-ex part
    for (int i = 0; i < n; ++i) {
      q[i] = ifact[i];
      if (i & 1) q[i] = MOD - q[i];
    }
  }

  vector<int> ans = FFT::multiply(p, q); ans.resize(n);
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < n; ++i) {
    ans[i] = 1LL * ans[i] * fact[n] % MOD * ifact[i] % MOD;
  }
  print(ans);
  return 0;
}