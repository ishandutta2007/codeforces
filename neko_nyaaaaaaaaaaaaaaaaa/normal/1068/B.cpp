#include <bits/stdc++.h>
using namespace std;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      long long x; cin >> x;
      long long ans = 0;
      for (long long i = 1; i*i <= x; i++) {
            if (x % i == 0) {
                  ans += 2;
                  ans -= (x/i == i);
            }
      }
      cout << ans;

      return 0;
}