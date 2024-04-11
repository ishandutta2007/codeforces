#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      int ans = 1e9, sum = 0;
      vector<pair<int, int>> a(n);
      multiset<int> d;

      for (int i = 0; i < n; i++) cin >> a[i].first;
      for (int i = 0; i < n; i++) {cin >> a[i].second; sum += a[i].second; d.insert(a[i].second);}
      sort(a.begin(), a.end());

      map<int, int> m;
      for (auto i: a) {
            m[i.first] += i.second;
      }

      for (int i = n-1; i >= 0; i--) {
            if (m[a[i].first] == 0) {
                  continue;
            }

            int tmp = m[a[i].first];
            m[a[i].first] = 0;
            int j = i, k = 0;
            while (j >= 0 && a[j].first == a[i].first) {k++; d.erase(d.find(a[j].second)); j--;}

            k--;
            for (auto it = d.rbegin(); it != d.rend() && k > 0; it++) {
                  tmp += *it;
                  k--;
            }

            ans = min(ans, sum - tmp);
      }
      cout << ans;

	return 0;
}