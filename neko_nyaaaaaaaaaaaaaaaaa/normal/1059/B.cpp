#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n, m;
      cin >> n >> m;
      vector<vector<char>> c(1008, vector<char>(1008, '.'));
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  cin >> c[i][j];
            }
      }

      vector<vector<char>> a(1008, vector<char>(1008, '.'));
      for (int i = 2; i < n; i++) {
            for (int j = 2; j < m; j++) {
                  if (c[i-1][j-1] == '#' &&
                      c[i-1][j] == '#' &&
                      c[i-1][j+1] == '#' &&
                      c[i][j-1] == '#' &&
                      c[i][j+1] == '#' &&
                      c[i+1][j-1] == '#' &&
                      c[i+1][j] == '#' &&
                      c[i+1][j+1] == '#') {
                              a[i-1][j-1] = '#';
                              a[i-1][j] = '#';
                              a[i-1][j+1] = '#';
                              a[i][j-1] = '#';
                              a[i][j+1] = '#';
                              a[i+1][j-1] = '#';
                              a[i+1][j] = '#';
                              a[i+1][j+1] = '#';
                      }
            }
      }

      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  if (a[i][j] != c[i][j]) {cout << "NO"; return 0;}
            }
      }
      cout << "YES";

	return 0;
}