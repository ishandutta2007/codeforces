#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int power(int x, int y, int mod) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % mod;
    x = 1LL * x * x % mod;
  }
  return ret;
}

int n, m;
char s[N], t[N];

vector<int> primes = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131,
    137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211,
    223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271
};

int P[60][300];

bool isPrime(int n) {
  for (int i = 2; i*i <= n; ++i) if (n % i == 0) return false;
  return true;
}

int main() {
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  scanf("%s", t);

  for (int i = 0; i < primes.size(); ++i) {
    int p = primes[i];
    for (int j = 0; j < n; ++j) {
      P[i][j % p] += s[j] - t[j];
    }
  }

  for (int p = m; ; ++p) {
    if (!isPrime(p)) continue;
    for (int i = 0; i < primes.size(); ++i) {
      int d = primes[i];
      if (d >= p) break;
      if ((p - 1) % d > 0) continue;
      int r = -1;
      do {
        r = rand() % (p - 1) + 1;
      } while ((r = power(r, (p - 1) / d, p)) == 1);

      for (int k = 0, rr = 1; k < d; ++k) {
        rr = 1LL * rr * r % p;

        int sum = 0, mul = 1;
        for (int j = 0; j < d; ++j) {
          sum = (1LL * P[i][j] * mul + sum) % p;
          mul = (1LL * mul * rr) % p;
        }
        if (sum == 0) return 0 * printf("%d %d\n", p, rr);
      }
    }
  }
  return 0;
}