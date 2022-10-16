#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      if (n == 1) {string a; cin >> a; cout << a; return 0;}

      vector<ll> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      sort(a.begin(), a.end());

      if (a[0] > 0) {
            ll ans = abs(a[0] - a[1]);
            for (int i = 2; i < n; i++) {
                  ans += a[i];
            }
            cout << ans;
      } else if (a[n-1] < 0) {
            ll ans = abs(a[n-1] - a[n-2]);
            for (int i = n-3; i >= 0; i--) {
                  ans += abs(a[i]);
            }
            cout << ans;
      } else {
            ll ans = 0;
            for (int i = 0; i < n; i++) {
                  ans += abs(a[i]);
            }
            cout << ans;
      }

	return 0;
}