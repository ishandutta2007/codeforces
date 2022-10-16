#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, m; cin >> n >> m;
      vector<ll> a(n), b(m);
      for (auto &i: a) cin >> i;
      for (auto &i: b) cin >> i;
      sort(a.begin(), a.end()); sort(b.begin(), b.end(), greater<ll>());

      ll ans = 0;
      for (int i = 0; i < min(n, m); i++) {
            if (a[i] < b[i]) ans += b[i] - a[i];
      }
      cout << ans;

      return 0;
}