#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n;
long long a[N];

int primes[N];
bool isPrime(int n) {
  if (~primes[n]) return primes[n];
  for (int i = 2; i*i <= n; ++i) {
    if (n % i == 0) return primes[n] = 0;
  }
  return primes[n] = 1;
}

int solve() {
  scanf("%d", &n);
  if (a[n] != -1) return 0 * printf("%lld\n", a[n]);

  int p = n + 1;
  while (!isPrime(p)) ++p;

  int q = p + n;
  while (!isPrime(q)) ++q;

  long long ans = a[n] = 1LL * p * q;
  printf("%lld\n", ans);
  return 0;
}

int main() {
  memset(a, -1, sizeof a);
  memset(primes, -1, sizeof primes);
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}