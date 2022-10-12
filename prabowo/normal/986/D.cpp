#include <bits/stdc++.h>
using namespace std;

namespace FFT {

const int MAXN = 1 << 20;

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

const int BASE = 10000;
struct BigInt {
  vector<int> digits;

  BigInt(int n) {
    digits = {n};
    normalize(digits);
  }

  BigInt(char s[]) {
    int len = strlen(s);
    digits.clear();
    for (; len >= 4; len -= 4) {
      digits.push_back((s[len - 4] - '0') * 1000 + (s[len - 3] - '0') * 100 + (s[len - 2] - '0') * 10 + (s[len - 1] - '0'));
    }

    if (len == 1) {
      digits.push_back(s[0] - '0');
    } else if (len == 2) {
      digits.push_back((s[0] - '0') * 10 + (s[1] - '0'));
    } else if (len == 3) {
      digits.push_back((s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0'));
    }
  }

  template<class T>
  void normalize(vector<T> &digits) {
    long long carry = 0;
    for (int i = 0; i < digits.size(); ++i) {
      carry += digits[i];
      digits[i] = carry % BASE;
      carry /= BASE;
    }
    while (carry > 0) {
      digits.push_back(carry % BASE);
      carry /= BASE;
    }
    while (digits.back() == 0) digits.pop_back();
  }

  void operator += (const BigInt &other) {
    int mini = min(digits.size(), other.digits.size());

    for (int i = 0; i < mini; ++i) digits[i] += other.digits[i];
    if (digits.size() < other.digits.size()) {
      digits.reserve(other.digits.size());
      while (digits.size() < other.digits.size()) digits.push_back(other.digits[digits.size()]);
    }

    normalize(digits);
  }

  void operator += (int x) {
    if (digits.size() > 0) digits[0] += x;
    else digits = {x};
    normalize(digits);
  }

  void operator *= (int x) {
    for (int &d : digits) d *= x;
    normalize(digits);
  }

  void operator *= (const BigInt &other) {
    vector<long long> digs = FFT::multiply(digits, other.digits);
    normalize(digs);
    digits.resize(digs.size());
    for (int i = 0; i < digs.size(); ++i) digits[i] = digs[i];
  }

  void operator /= (int x) {
    for (int i = (int) digits.size() - 1; i >= 0; --i) {
      if (i > 0) digits[i - 1] += (digits[i] % x) * BASE;
      digits[i] /= x;
    }
    while (digits.back() == 0) digits.pop_back();
  }

  bool operator < (const BigInt &other) {
    if (digits.size() != other.digits.size()) return digits.size() < other.digits.size();
    for (int i = (int) digits.size() - 1; i >= 0; --i) {
      if (digits[i] != other.digits[i]) return digits[i] < other.digits[i];
    }
    return false;
  }

  int digitLength() {
    if (digits.size() == 0) return 1;
    int ret = digits.size() * 4;
    if (digits.back() < 10) ret -= 3;
    else if (digits.back() < 100) ret -= 2;
    else if (digits.back() < 1000) ret -= 1;
    return ret;
  }

  void print() {
    for (int i = (int) digits.size() - 1; i >= 0; --i) cout << digits[i];
  }
};

BigInt power(BigInt x, int y) {
  BigInt ret(1);
  for (; y; y >>= 1) {
    if (y & 1) ret *= x;
    x *= x;
  }
  return ret;
}

const int N = 1500005;

char s[N];

int main() {
  FFT::init();
  scanf("%s", s);

  if (strcmp(s, "1") == 0) return 0 * printf("1\n");

  vector<BigInt> twos;
  twos.push_back(BigInt(s));
  twos.push_back(twos.back()); twos.back() += 1; twos.back() /= 2;
  twos.push_back(twos.back()); twos.back() += 1; twos.back() /= 2;

  int three = (twos.back().digitLength() - 1) * log(10) / log(3);
  BigInt num = power(BigInt(3), three);

  int ans = 1e9;
  for (int two = 2; two >= 0; --two) {
    while (num < twos[two]) num *= 3, ++three;

    ans = min(ans, three*3 + two*2);
  }

  printf("%d\n", ans);
  return 0;
}