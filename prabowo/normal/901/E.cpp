#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
int n;
int b[N], c[N];
 
int power(int x, int y, int mod) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % mod;
    x = 1LL * x * x % mod;
  }
  return ret;
}
 
bool isPrime(int n) {
  for (int i = 2; i*i <= n; ++i) if (n % i == 0) return false;
  return true;
}
 
int primitiveRoot(int p) {
  vector<int> divisors;
  for (int i = 1; i < p - 1; ++i) {
    if ((p - 1) % i == 0) divisors.push_back(i);
  }
 
  for (int g = 2; ; ++g) {
    bool okay = true;
    for (int d: divisors) {
      if (power(g, d, p) == 1) {
        okay = false;
        break;
      }
    }
    if (okay) return g;
  }
  return -1;
}
 
namespace FFT {
 
const int MAXN = 1 << 20;
 
typedef complex<double> ftype;
const double PI = acos(-1);
ftype w[MAXN];
 
void initFft() {
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
vector<int> multiply(vector<int> a, vector<int> b, int mod) {
  int n = 1 << (32 - __builtin_clz(a.size() + b.size() - 2));
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
    long long a = llround(nA[i].real() / n) % mod;
    long long b = llround(nB[i].real() / n) % mod;
    long long c = llround(nA[i].imag() / n) % mod;
    ans[i] = (a + (b << sz) + (c << 2 * sz)) % mod;
  }
 
  ans.resize(a.size() + b.size() - 1);
  return ans;
}
 
}
 
namespace DFT {
 
const int MAXVAL = 5000;
 
int mod, in;
vector<int> zp, izp;
 
void initDft(int n, int _mod=-1) {
  if (_mod == -1) mod = MAXVAL / n * n + n + 1;
  else mod = _mod + n;
 
  while (!isPrime(mod)) mod += n;
  in = power(n, mod - 2, mod);
 
  int z = power(primitiveRoot(mod), (mod-1) / n, mod);
  int iz = power(z, mod - 2, mod);
 
  int len = n*2 - 1;
  zp.assign(len, z), izp.assign(len, iz);
  zp[0] = zp[1] = izp[0] = izp[1] = 1;
 
  for (int k = 0; k < 2; ++k) {
    for (int i = 2; i < len; ++i) {
      zp[i] = 1LL * zp[i] * zp[i-1] % mod;
      izp[i] = 1LL * izp[i] * izp[i-1] % mod;
    }
  }
}
 
void dft(vector<int> &a, bool invert) { // Chirp-Z Transform
  if (invert) swap(zp, izp);
 
  vector<int> A(a.size());
  for (int i = 0; i < a.size(); ++i) {
    A[a.size() - i - 1] = 1LL * a[i] * izp[i] % mod;
  }
  A = FFT::multiply(A, zp, mod);
 
  for (int i = 0; i < a.size(); ++i) {
    a[i] = 1LL * A[i + a.size() - 1] * izp[i] % mod;
  }
 
  if (invert) {
    swap(zp, izp);
    for (int i = 0; i < a.size(); ++i) a[i] = 1LL * a[i] * in % mod;
  } 
}
 
}
 
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
 
  FFT::initFft();
  DFT::initDft(n);
 
  if (false) {
newMod:
    DFT::initDft(n, DFT::mod);
  }
 
  vector<int> A(n), B(n), C(n);
  for (int i = 0; i < n; ++i) {
    B[i] = b[i];
    C[i] = c[(i+n-1) % n] - c[i];
    if (C[i] & 1) return 0 * printf("0\n");
    C[i] /= 2;
    C[i] = (C[i] % DFT::mod + DFT::mod) % DFT::mod;
  }
  reverse(B.begin() + 1, B.end());
 
  DFT::dft(B, false); DFT::dft(C, false);
  for (int i = 0; i < n; ++i) {
    if (B[i] == 0) goto newMod;
    A[i] = 1LL * C[i] * power(B[i], DFT::mod - 2, DFT::mod) % DFT::mod;
  }
  DFT::dft(A, true);
  for (int i = 0; i < n; ++i) {
    A[i] = (A[i] < DFT::mod - A[i] ? A[i] : A[i] - DFT::mod);
    assert(A[i] < DFT::MAXVAL);
  }
 
  A[0] = 0;
  for (int i = 1; i < n; ++i) A[i] += A[i-1];
 
  long long aa = n, bb = 0, cc = -c[0];
  for (int i = 0; i < n; ++i) {
    cc += 1LL * (b[i] - A[i]) * (b[i] - A[i]);
    bb += (b[i] - A[i]);
  }
  bb *= -2;
 
  long long D = 1LL * bb * bb - 4LL * aa * cc;
  if (D < 0) return 0 * printf("0\n");
  long long sD = round(sqrt(D));
  if (sD * sD != D) return 0 * printf("0\n");
 
  vector<int> res;
  if ((-bb + sD) % (2 * aa) == 0) {
    res.push_back((-bb + sD) / (2 * aa));
  }
  if (sD != 0 && (-bb - sD) % (2 * aa) == 0) {
    res.push_back((-bb - sD) / (2 * aa));
  }
 
  printf("%d\n", (int) res.size());
  sort(res.begin(), res.end());
  for (int i = 0; i < res.size(); ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d ", res[i] + A[j]);
    }
    printf("\n");
  }

  return 0;
}