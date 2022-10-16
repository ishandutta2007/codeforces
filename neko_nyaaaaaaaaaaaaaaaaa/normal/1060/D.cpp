#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<ll> a(n), b(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
      }
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());

      ll ans = n;
      for (int i = 0; i < n; i++) {
            ans += max(a[i], b[i]);
      }
      cout << ans;

      return 0;
}