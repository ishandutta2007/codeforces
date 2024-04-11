#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

// Ring (x^10 - 1)
struct TenthRing {
  long long w[10];

  TenthRing(long long x=0) {
    w[0] = x;
    for (int i = 1; i < 10; ++i) {
      w[i] = 0;
    }
  }

  // multiply by w^k
  TenthRing multiplyUnity(int k) {
    k %= 10; if (k < 0) k += 10;
    TenthRing ret;
    for (int i = 0; i < 10; ++i) ret.w[(i+k) % 10] = w[i];
    return ret;
  }

  void operator += (const TenthRing &other) {
    for (int i = 0; i < 10; ++i) {
      w[i] += other.w[i];
    }
  }

  TenthRing operator * (const TenthRing &other) {
    TenthRing ret;
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        ret.w[(i+j) % 10] += w[i] * other.w[j];
      }
    }
    return ret;
  }

  void reduce() {
    for (int i = 9; i >= 4; --i) {
      for (int j = 4; j >= 0; --j) {
        if (j & 1) w[i-j] += w[i];
        else w[i-j] -= w[i];
      }
    }
  }
};

// n is power of 10
void dftTenth(int n, TenthRing a[], bool inv) {
  int root = (inv ? -1 : 1);
  for (int len = 1; len < n; len *= 10) {
    for (int i = 0; i < n; i += len * 10) {

      for (int j = 0; j < len; ++j) {
        TenthRing t[10];
        int mul = 0;
        for (int ii = 0; ii < 10; ++ii) {
          int w = 0;
          for (int jj = 0; jj < 10; ++jj) {
            t[ii] += a[i+j + jj*len].multiplyUnity(w);
            w += mul;
          }
          mul += root;
        }

        for (int ii = 0; ii < 10; ++ii) {
          a[i+j + ii*len] = t[ii];
        }
      }
    }
  }
}

template<class T>
T power(T x, long long y) {
  T ret = T(1);
  for (; y > 1; y >>= 1) {
    if (y & 1) ret = ret * x;
    x = x * x;
  }
  ret = ret * x;
  return ret;
}

int n;
TenthRing a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ++a[x].w[0];
  }

  dftTenth(N, a, false);

  for (int i = 0; i < N; ++i) {
    a[i] = power(a[i], n);
  }

  dftTenth(N, a, true);

  // Since 10^5 doesn't have an inverse mod 2^58, we break it into
  //   2^5 and 5^5. 5^5 has an inverse. For 2^5, since all computation is under long long,
  //   it is already under mod 2^64, so we simply divide it by 2^5

  // Inverse of 5^5 mod 2^58
  long long i5 = power(power(5LL, (1LL << 57) - 1), 5);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
      ((a[i].w[j] *= i5) >>= 5) &= (1LL << 58) - 1;
    }
  }

  // Our current ring still as non-zero coefficients of w^k for k > 0
  // Note that for the DFT to work, the chosen root must be principal root
  // A primitive root is a principal root
  // The primitive root is the roots of the 10-th cyclotomic polynomial:
  //   x^4 - x^3 + x^2 - x^1 + 1
  // ==> x^k = x^(k-1) - x^(k-2) + x^(k-3) - x^(k-4)

  for (int i = 0; i < n; ++i) {
    a[i].reduce();
    printf("%lld\n", a[i].w[0] & (1LL << 58) - 1);
  }

  return 0;
}