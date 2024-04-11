#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }

      int cost = 1000000007;
      int ans = 0;

      for (int t = 1; t <= 100; t++) {
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                  if (a[i] != t) {
                        tmp += abs(a[i] - t) - 1;
                  }
            }
            if (tmp < cost) {
                  ans = t;
                  cost = tmp;
            }
      }

      cout << ans << ' ' << cost;

      return 0;
}