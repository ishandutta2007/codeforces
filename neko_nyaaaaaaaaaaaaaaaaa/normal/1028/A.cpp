#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, m;
      cin >> n >> m;
      vector<vector<char>> c(200, vector<char>(200, 'W'));
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  cin >> c[i][j];
            }
      }

      int x1 = -1, y1 = -1;
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  if (c[i][j] == 'B') {x1 = i; y1 = j; break;}
            }
            if (x1 != -1) break;
      }
      int x2 = -1, y2 = -1;
      for (int i = n; i; i--) {
            for (int j = m; j; j--) {
                  if (c[i][j] == 'B') {x2 = i; y2 = j; break;}
            }
            if (x2 != -1) break;
      }

      cout << (x1 + x2)/2 << " " << (y1 + y2)/2;

      return 0;
}