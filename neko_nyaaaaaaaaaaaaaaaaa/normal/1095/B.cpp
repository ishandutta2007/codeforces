#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> a(n);
      for (auto &i: a) cin >> i;
      sort(a.begin(), a.end());

      if (n == 2) {cout << 0;}
      else {
            cout << min(a[n-1] - a[1], a[n-2] - a[0]);
      }

	return 0;
}