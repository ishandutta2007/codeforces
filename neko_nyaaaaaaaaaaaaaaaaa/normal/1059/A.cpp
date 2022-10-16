#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      ll n, l, a; cin >> n >> l >> a;
      ll ans = 0;
      ll prev = 0;
      for (int i = 0; i < n; i++) {
            ll x, y; cin >> x >> y;
            ll tl = x - prev;
            ans += tl/a;
            prev = x+y;
      }
      ll tl = l - prev;
      ans += tl/a;
      cout << ans;

	return 0;
}