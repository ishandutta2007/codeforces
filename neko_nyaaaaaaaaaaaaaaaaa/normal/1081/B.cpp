#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<pair<int, int>> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].first = n - a[i].first;
            a[i].second = i;
      }
      vector<int> ans(n);
      sort(a.begin(), a.end());

      int petr = 1;
      for (int i = 0; i < n; i++) {
            if (ans[a[i].second]) continue;

            ans[a[i].second] = petr;
            for (int j = i+1, k = a[i].first - 1; k > 0; j++, k--) {
                  if (j >= n || a[j].first != a[i].first) {cout << "Impossible\n"; return 0;}
                  ans[a[j].second] = petr;
            }
            petr++;
      }

      cout << "Possible\n";
      for (int i: ans) cout << i << ' ';

	return 0;
}