#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int t; cin >> t;
      while (t--) {
            ll a, b, k; cin >> a >> b >> k;
            ll before = k/2;
            ll now = k % 2;

            ll ans = before*(a - b) + now*a;
            cout << ans << '\n';
      }

      return 0;
}