#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      if (n < 3) {cout << 0; return 0;}

      vector<pair<int, int>> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
      }
      int ans = n*(n-1)*(n-2)/6;

      int collinear = 0;
      for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> mp;
            for (int j = 0; j < n; j++) {
                  if (i == j) continue;

                  int p = (a[j].first - a[i].first), q = (a[j].second - a[i].second), k = __gcd(p, q);
                  p /= k; q /= k;
                  if (p < 0) {
                        p *= -1;
                        q *= -1;
                  } else if (p == 0) {
                        if (q < 0) q *= -1;
                  }

                  mp[make_pair(p, q)]++;
            }
            for (auto u: mp) {
                  int k = u.second;
                  if (k == 1) continue;
                  collinear += k*(k - 1)/2;
            }
      }
      collinear /= 3;

      cout << ans - collinear;

      return 0;
}