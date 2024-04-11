#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      vector<pair<int, int>> a(3);
      for (int i = 0; i < 3; i++) {
            cin >> a[i].first >> a[i].second;
      }
      sort(a.begin(), a.end());

      set<pair<int, int>> ans;
      for (int i = a[0].first; i <= a[1].first; i++) {
            ans.insert({i, a[0].second});
      }
      for (int i = a[2].first; i >= a[1].first; i--) {
            ans.insert({i, a[2].second});
      }

      if (a[0].second >= a[1].second || a[2].second >= a[1].second) {
            for (int i = a[1].second; i <= a[0].second || i <= a[2].second; i++) {
                  ans.insert({a[1].first, i});
            }
      }
      if (a[0].second <= a[1].second || a[2].second <= a[1].second) {
            for (int i = a[1].second; i >= a[0].second || i >= a[2].second; i--) {
                  ans.insert({a[1].first, i});
            }
      }

      cout << ans.size() << '\n';

      for (auto u: ans) cout << u.first << ' ' << u.second << '\n';

	return 0;
}