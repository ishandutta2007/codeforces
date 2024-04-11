#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    if (n % 2050) cout << -1 << '\n';
    else {
      long long u = n / 2050;
      int res = 0;
      while (u) {
        res += u % 10;
        u /= 10;
      }
      cout << res << '\n';
    }
  }
  return 0;
}