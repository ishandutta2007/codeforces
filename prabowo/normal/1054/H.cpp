#include <bits/stdc++.h>
using namespace std;

using ftype = complex<double>;

const int MOD = 490019;
const double PI = acos(-1);

namespace CZT {

const int MAXN = 1 << 21;

ftype w[MAXN];

void init() {
  for (int i = 0; i < MAXN; ++i) {
    w[i] = ftype(cos(2*PI*i / MAXN), sin(2*PI*i / MAXN));
  }
}

int power(int x, int y) {
  int ret = 1;
  for (; y > 1; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return 1LL * ret * x % MOD;
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

  ans.resize(a.size() + b.size() - 1);
  return ans;
}

// yk = sum(a_i * z^ik), k = 0..n-1
// = z^(-k(k-1)/2) sum(a_i * z^(-i(i-1)/2) * z^((k+i)(k+i-1)/2))
// a.size() >= 2
vector<int> czt(vector<int> a, int z, int n) {
  int sz = n + a.size() - 1;
  int iz = power(z, MOD-2);

  // zp[i] = z^C(i, 2)
  vector<int> zp(sz), izp(sz);
  zp[0] = zp[1] = izp[0] = izp[1] = 1;

  for (int i = 2; i < sz; ++i) {
    zp[i] = 1LL * zp[i-1] * z % MOD;
    izp[i] = 1LL * izp[i-1] * iz % MOD;
  }

  for (int i = 2; i < sz; ++i) {
    zp[i] = 1LL * zp[i] * zp[i-1] % MOD;
    izp[i] = 1LL * izp[i] * izp[i-1] % MOD;
  }

  vector<int> A(a.size());
  for (int i = 0; i < a.size(); ++i) {
    A[a.size() - i - 1] = 1LL * a[i] * izp[i] % MOD;
  }
  A = multiply(A, zp);

  for (int i = 0; i < n; ++i) {
    A[i] = 1LL * A[i + a.size() - 1] * izp[i] % MOD;
  }
  A.resize(n);
  return A;
}

} // namespace CZT

int n, m, c;
int a[MOD], b[MOD];

// sum_{n, m}(a_i b_j c^{i^2j^3}) = sum_{MOD-1, MOD-1}(A_i B_j c^ij); A_{i*i} = sum(a_i)

int main() {
  scanf("%d %d %d", &n, &m, &c);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    (a[1LL*i*i % (MOD-1)] += x) %= MOD;
  }

  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    (b[1LL*i*i*i % (MOD-1)] += x) %= MOD;
  }

  CZT::init();
  vector<int> res = CZT::czt(vector<int>(b, b + MOD-1), c, MOD-1);

  int ans = 0;
  for (int i = 0; i < MOD-1; ++i) ans = (ans + 1LL * a[i] * res[i]) % MOD;

  printf("%d\n", ans);
  return 0;
}