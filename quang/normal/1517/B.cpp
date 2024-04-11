#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m;
int a[N][N];
int res[N][N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    for (int it = 1; it <= m; it++) {
      int min_val = 2e9;
      pair<int, int> pos(0, 0);
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (a[i][j] != -1) {
            if (min_val > a[i][j]) {
              min_val = a[i][j];
              pos = {i, j};
            }
          }
        }
      }

      for (int i = 1; i <= n; i++) {
        if (i == pos.first) {
          res[i][it] = a[i][pos.second];
          a[i][pos.second] = -1;
        } else {
          int p = 0;
          for (int j = 1; j <= m; j++) {
            if (a[i][j] == -1) continue;
            if (!p || a[i][p] < a[i][j]) p = j;
          }
          res[i][it] = a[i][p];
          a[i][p] = -1;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) cout << res[i][j] << ' ';
        cout << '\n';
    }
  }
  return 0;
}