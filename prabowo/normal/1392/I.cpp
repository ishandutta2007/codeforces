#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int n, m, q;
int A[N], B[N];

namespace FFT {
const int MAXN = 1 << 18;

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

  return ans;
}

} // namespace FFT

// SF: small face (2x2 nodes)
// V1 - E1 + SF1 + BF1 = C1
// V2 - E2 + SF2 + BF2 = C2

// ans per query: C1 + BF2 - (C2 + BF1)
// C1 - BF1 - C2 + BF2

vector<long long> makePre(vector<long long> v) {
  for (int i = 1; i < v.size(); ++i) v[i] += v[i-1];
  return v;
}

vector<long long> makeSuf(vector<long long> v) {
  for (int i = (int) v.size() - 2; i >= 0; --i) v[i] += v[i+1];
  return v;
}

int main() {
  FFT::init();

  scanf("%d %d %d", &n, &m, &q);

  vector<int> a(N), b(N), amin(N), bmin(N), amax(N), bmax(N);

  for (int i = 0; i < n; ++i) scanf("%d", &A[i]), ++a[A[i]];
  for (int i = 0; i < m; ++i) scanf("%d", &B[i]), ++b[B[i]];
  for (int i = 1; i < n; ++i) ++amin[min(A[i-1], A[i])], ++amax[max(A[i-1], A[i])];
  for (int i = 1; i < m; ++i) ++bmin[min(B[i-1], B[i])], ++bmax[max(B[i-1], B[i])];

  vector<long long> node = FFT::multiply(a, b);
  vector<long long> horiCold = FFT::multiply(amax, b), horiHeat = FFT::multiply(amin, b);
  vector<long long> vertCold = FFT::multiply(a, bmax), vertHeat = FFT::multiply(a, bmin);
  vector<long long> faceCold = FFT::multiply(amax, bmax), faceHeat = FFT::multiply(amin, bmin);

  vector<long long> nodeCold = makePre(node), nodeHeat = makeSuf(node);
  horiCold = makePre(horiCold), horiHeat = makeSuf(horiHeat);
  vertCold = makePre(vertCold), vertHeat = makeSuf(vertHeat);
  faceCold = makePre(faceCold), faceHeat = makeSuf(faceHeat);

  while (q--) {
    int x;
    scanf("%d", &x);

    printf("%lld\n",
      (nodeHeat[x] - horiHeat[x] - vertHeat[x] + faceHeat[x]) -
      (nodeCold[x-1] - horiCold[x-1] - vertCold[x-1] + faceCold[x-1])
    );
  }
  return 0;
}