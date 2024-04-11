#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      ll n; cin >> n;
      ll pw = 1;
      ll ans = 0;
      while (n) {
            if (pw*9 <= n) {
                  ans += 9;
                  n -= pw*9;
                  pw *= 10;
            } else {
                  for (ll i = 9; i >= 0; i--) {
                        if (pw*i <= n) {
                              ans += i;
                              n -= pw*i;
                              pw *= 10;
                              break;
                        }
                  }
                  break;
            }
      }
      while (n) {
            ans += (n % 10);
            n /= 10;
      }
      cout << ans;

      return 0;
}