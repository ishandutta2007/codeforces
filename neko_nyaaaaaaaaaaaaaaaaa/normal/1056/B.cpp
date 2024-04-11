#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      ll n, m; cin >> n >> m;
      vector<ll> a(m);
      ll md = n % m;
      ll k = n/m;
      for (ll i = 0; i < m; i++) {
            ll j = (i*i) % m;
            a[j] += k;
            if (i <= md && i > 0) a[j]++;
      }

      ll ans = a[0]*a[0];
      for (ll i = 1; i < m; i++) {
            for (ll j = 1; j < m; j++) {
                  if ((i+j) % m == 0) {ans += a[i]*a[j];}
            }
      }
      cout << ans;

	return 0;
}