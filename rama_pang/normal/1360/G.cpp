#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int can = 1;
    vector<string> ans(n, string(m, '-'));
    vector<int> col(m, 0), row(n, 0);

    int sx = 0, sy = 0;
    
    for (int rep = 0; rep < max(n, m); rep++) {
      int x = sx, y = sy;

      while (ans[x][y] == '-') {
        ans[x][y] = '0';
        if (row[x] < a && col[y] < b) {
          row[x]++;
          col[y]++;
          ans[x][y] = '1';
        }
        x++, y++;
        x %= n;
        y %= m;
      }

      if (n <= m) sy++;
      else sx++;
    }

    for (int i = 0; i < n; i++) {
      if (row[i] != a) {
        can = 0;
      }
    }
    for (int i = 0; i < m; i++) {
      if (col[i] != b) {
        can = 0;
      }
    }

    if (can) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
      }
    } else {
      cout << "NO\n";
    }
  }
}