#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      ll n, m;
      cin >> n >> m;
      vector<ll> a(n+1), b(m+1);
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i-1];
      }
      for (int i = 1; i <= m; i++) {
            cin >> b[i];
      }
      ll x; cin >> x;


      ll ans = 0;
      for (ll k = 1; k <= n; k++) {
            ll s = 1e9;
            for (ll i = k; i <= n; i++) {
                  s = min(s, a[i] - a[i-k]);
            }

            ll sz = x/s;

            ll petr1 = 1, petr2 = 1;
            ll sum = 0;
            while (petr2 <= m) {
                  sum += b[petr2];
                  petr2++;

                  while (sum > sz) {
                        sum -= b[petr1];
                        petr1++;
                  }

                  ans = max(ans, k*(petr2 - petr1));
            }
      }
      cout << ans;

      return 0;
}