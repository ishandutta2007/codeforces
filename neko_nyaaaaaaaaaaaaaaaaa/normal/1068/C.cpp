#include <bits/stdc++.h>
using namespace std;

int a[5001][5001];

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, m; cin >> n >> m;
      for (int i = 1; i <= n; i++) {
            a[i][i] = i;
      }
      int k = 500;
      while (m--) {
            int x, y; cin >> x >> y;
            if (x > y) swap(x, y);
            a[x][k] = x;
            a[y][k] = y;
            k++;
      }

      vector<int> x[n+1], y[n+1];
      for (int i = 1; i <= 5000; i++) {
            for (int j = 1; j <= 5000; j++) {
                  if (a[i][j]) {
                        x[a[i][j]].push_back(i);
                        y[a[i][j]].push_back(j);
                  }
            }
      }

      for (int i = 1; i <= n; i++) {
            cout << x[i].size() << '\n';
            for (int j = 0; j < x[i].size(); j++) {
                  cout << x[i][j] << ' ' << y[i][j] << '\n';
            }
      }

      return 0;
}