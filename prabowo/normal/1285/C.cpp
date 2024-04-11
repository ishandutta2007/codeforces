#include <bits/stdc++.h>
using namespace std;

long long x;

vector<long long> factorize(long long n) {
  vector<long long> ret;
  for (long long i = 2; i*i <= n; ++i) {
    if (n % i == 0) {
      long long term = 1;
      do {
        n /= i;
        term *= i;
      } while (n % i == 0);

      ret.push_back(term);
    }
  }

  if (n > 1) ret.push_back(n);

  return ret;
}

int main() {
  scanf("%lld", &x);

  vector<long long> f = factorize(x);
  int n = f.size();

  long long ans1 = 1, ans2 = x;

  for (int mask = 0; mask < 1 << n; ++mask) {
    long long cur1 = 1, cur2 = 1;
    for (int i = 0; i < n; ++i) {
      if (mask >> i & 1) cur1 *= f[i];
      else cur2 *= f[i];
    }

    if (max(cur1, cur2) < max(ans1, ans2)) {
      ans1 = cur1, ans2 = cur2;
    }
  }

  printf("%lld %lld\n", ans1, ans2);
  return 0;
}