#include<bits/stdc++.h>

using namespace std;

long long lcm(long long x, long long y) {
  return (x / __gcd(x, y)) * y;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  long long n; cin >> n;

  long long ans = n;

  for(long long i = 1; i * i <= n; ++i) {
    if(n % i == 0) {
      long long j = n / i;
      if(lcm(i, j) == n) ans = min(ans, j);
    }
  }

  cout << n / ans << " " << ans << endl;

  return 0;
}