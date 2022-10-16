#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int x, int y, int n) {
      vector<int> ans(n+1);
      ans[x] = 1; ans[y] = 2;
      for (int i = 1, j = 3; i <= n; i++) {
            if (ans[i] == 0) {
                  ans[i] = j++;
            }
      }

      for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
      }
      cout << '\n';

      ans[y] = 1;
      for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
      }
      cout << '\n';

      exit(0);
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, m; cin >> n >> m;
      if (n == 0 || n*(n-1)/2 == m) {cout << "NO\n";}
      else {
            cout << "YES\n";

            set<pair<int, int>> st;
            for (int i = 0; i < m; i++) {
                  int x, y; cin >> x >> y;
                  if (x > y) swap(x, y);
                  st.insert({x, y});
            }

            for (int i = 1; i <= n; i++) {
                  for (int j = i+1; j <= n; j++) {
                        if (st.find({i, j}) == st.end()) {
                              solve(i, j, n);
                        }
                  }
            }
      }

      return 0;
}