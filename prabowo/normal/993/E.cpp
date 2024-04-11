#include <bits/stdc++.h>
using namespace std;

namespace FFT {

const int MAXN = 1 << 19;

typedef complex<double> ftype;
const double PI = acos(-1);
ftype w[MAXN];

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

vector<long long> multiply(vector<int> a, vector<int> b) {
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
  vector<long long> ans(n);
  for(int i = 0; i < n; i++) {
    long long a = llround(nA[i].real() / n);
    long long b = llround(nB[i].real() / n);
    long long c = llround(nA[i].imag() / n);
    ans[i] = (a + (b << sz) + (c << 2 * sz));
  }

  ans.resize(a.size() + b.size() - 1);
  return ans;
}

} // namespace FFT

const int N = 200005;

int n, x;
int a[N];

int main() {
  scanf("%d %d", &n, &x);
  vector<int> p(n + 1, 0);
  ++p[0];

  int pre = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] < x) ++pre;
    ++p[pre];
  }

  vector<int> q = p;
  reverse(q.begin(), q.end());

  FFT::init();
  vector<long long> ans = FFT::multiply(p, q);

  printf("%lld", (ans[n] - n) / 2);
  for (int i = 0; i < n; ++i) {
    printf(" %lld", ans[n + i + 1]);
  }
  printf("\n");

  return 0;
}