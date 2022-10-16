#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> a(n+1), b(n+1);
      for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
      }

      vector<int> ans(1, 1);
      vector<int> vis(n+1); vis[1] = 1;
      while (ans.size() < n) {
            int u = ans.back();

            int x = a[u], y = b[u];
            if ((a[y] == x || b[y] == x) && !vis[y]) {
                  ans.push_back(y);
                  vis[y] = 1;
            } else {
                  ans.push_back(x);
                  vis[x] = 1;
            }
      }
      for (int i: ans) cout << i << ' ';

	return 0;
}