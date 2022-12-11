#include <bits/stdc++.h>

using namespace std;

constexpr int X = 40;

long long dp[X][X];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    long long n;
    cin >> n;

    long long x = n / 2;
    long long total = x * (x+1);
    total += (n % 2 ? (n/2)+1 : 0LL);

    long long ans = sqrt(total);
    cout << ans << endl;
  }

  return 0;
}