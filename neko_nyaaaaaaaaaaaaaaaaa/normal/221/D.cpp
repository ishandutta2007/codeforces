#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n, q; cin >> n >> q;
      vector<int> a(n+1);
      vector<int> f(n+1);
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] <= n) f[a[i]]++;
      }

      vector<int> num;
      for (int i = 1; i <= n; i++) {
            if (f[i] >= i) num.push_back(i);
      }

      vector<vector<int>> pref;
      for (int u: num) {
            vector<int> s(n+1);
            for (int i = 1; i <= n; i++) {
                  s[i] = s[i-1] + (a[i] == u);
            }
            pref.push_back(s);
      }

      while (q--) {
            int l, r; cin >> l >> r;
            int ans = 0;
            for (int i = 0; i < num.size(); i++) {
                  if (pref[i][r] - pref[i][l-1] == num[i]) ans++;
            }
            cout << ans << '\n';
      }

	return 0;
}