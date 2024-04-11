#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      ll n, k; cin >> n >> k;
      ll prev; cin >> prev;
      ll ans = prev/k;
      prev %= k;

      for (int i = 1; i < n; i++) {
            ll x; cin >> x;
            if (prev) {
                  ans++;
                  ll s = k - prev;
                  x = max(0LL, x - s);
            }
            prev = x;
            ans += prev/k;
            prev %= k;
      }

      if (prev) ans++;

      cout << ans;

      return 0;
}