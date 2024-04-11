#include <bits/stdc++.h>
using namespace std;

namespace FFT {

const int MAXN = 1 << 19;
const int MOD = 1009;

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

  while (ans.back() == 0) ans.pop_back();
  return ans;
}

} // namespace FFT

const int N = 200005;

int n, m, k;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  vector<int> col(m);
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    ++col[--c];
  }

  auto greaterSize = [&](const vector<int> &u, const vector<int> &v) { return u.size() > v.size(); };
  priority_queue<vector<int>, vector<vector<int>>, decltype(greaterSize)> pq(greaterSize);

  for (int c : col) {
    if (c == 0) continue;
    pq.push(vector<int>(c + 1, 1));
  }

  FFT::init();
  while (pq.size() > 1) {
    vector<int> p = pq.top(); pq.pop();
    vector<int> q = pq.top(); pq.pop();
    pq.push(FFT::multiply(p, q));
  }

  printf("%d\n", pq.top()[k]);

  return 0;
}