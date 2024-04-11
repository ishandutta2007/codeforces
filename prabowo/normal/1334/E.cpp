#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long d;
int q;

const int L = 200;
int fact[L], ifact[L];

int main() {
  vector<long long> primes;
  scanf("%lld", &d);
  
  // Factorize
  {
    for (long long i = 2; i*i <= d; ++i) {
      if (d % i > 0) continue;
      primes.push_back(i);
      do {
        d /= i;
      } while (d % i == 0);
    }

    if (d > 1) primes.push_back(d);
  }

  // Init factorial
  {
    fact[0] = 1;
    for (int i = 1; i < L; ++i) fact[i] = 1LL * fact[i-1] * i % MOD;
    ifact[L-1] = 977307459;
    for (int i = L-2; i >= 0; --i) ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;
  }

  scanf("%d", &q);
  while (q--) {
    long long u, v;
    scanf("%lld %lld", &u, &v);

    long long ans1 = 1, ans2 = 1;
    int sum1 = 0, sum2 = 0;
    for (long long p: primes) {
      int cnt1 = 0, cnt2 = 0;
      while (u % p == 0) {
        ++cnt1;
        u /= p;
      }

      while (v % p == 0) {
        ++cnt2;
        v /= p;
      }

      if (cnt1 > cnt2) {
        ans2 = ans2 * ifact[cnt1 - cnt2] % MOD;
        sum2 += cnt1 - cnt2;
      } else if (cnt2 > cnt1) {
        ans1 = ans1 * ifact[cnt2 - cnt1] % MOD;
        sum1 += cnt2 - cnt1;
      }
    }

    ans1 = ans1 * fact[sum1] % MOD;
    ans2 = ans2 * fact[sum2] % MOD;
    printf("%lld\n", ans1 * ans2 % MOD);
  }

  return 0;
}