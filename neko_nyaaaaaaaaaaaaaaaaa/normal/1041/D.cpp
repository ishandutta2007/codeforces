#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      ll n, h;
      cin >> n >> h;
      vector<ll> a(n+1), w(n+1), pref(n+1);
      for (int i = 1; i <= n; i++) {
            ll x, y; cin >> x >> y;
            a[i] = x;
            w[i] = y-x;
            pref[i] = pref[i-1] + w[i];
      }
      for (int i = 1; i < n; i++) {
            a[i+1] -= pref[i];
      }

      ll ans = 0;
      for (int i = 1; i <= n; i++) {
            auto it = lower_bound(a.begin(), a.end(), a[i] + h) - 1 - a.begin();
            ll tmp = pref[it] - pref[i-1];
            ans = max(ans, tmp);
      }
      cout << ans + h;

      return 0;
}