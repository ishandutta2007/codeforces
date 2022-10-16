#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);
      srand(time(NULL));

      ll n, s; cin >> n >> s;
      vector<ll> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      sort(a.begin(), a.end());
      ll ans = abs(s - a[n/2]);

      a[n/2] = s;
      for (int i = n/2 - 1; i >= 0; i--) {
            if (a[i] > a[n/2]) {
                  ans += abs(a[i] - a[n/2]);
                  a[i] = a[n/2];
            }
      }
      for (int i = n/2 + 1; i < n; i++) {
            if (a[i] < a[n/2]) {
                  ans += abs(a[i] - a[n/2]);
                  a[i] = a[n/2];
            }
      }
      cout << ans;

      return 0;
}