#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);
      
      ll n;
      cin >> n;
      vector<ll> a(n), b(n), c(n), d(n), e(n), ans;
      for (ll i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
      }
      for (ll i = 0; i < n; i++) {
		bool flag = 1;
		for (ll j = 0; j < n; j++) {
			if (!flag) break;
			if (i == j) continue;
			ll xa = a[j] - a[i], xb = b[j] - b[i], xc = c[j] - c[i], xd = d[j] - d[i], xe = e[j] - e[i];
			for (ll k = 0; k < n; k++) {
				if (!flag) break;
				if (i == k || j == k) continue;
				ll ya = a[k] - a[i], yb = b[k] - b[i], yc = c[k] - c[i], yd = d[k] - d[i], ye = e[k] - e[i];
				if (xa*ya + xb*yb + xc*yc + xd*yd + xe*ye > 0) {
					flag = 0; break;
				}
			}
		}
		if (flag) ans.push_back(i+1);
	}
      cout << ans.size() << "\n";
      for (ll i = 0; i < ans.size(); i++) {
            cout << ans[i] << "\n";
      }
      
      return 0;
}