#include <bits/stdc++.h>
using namespace std;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, m; cin >> n >> m;
      vector<vector<char>> a(2008, vector<char>(2008));
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  cin >> a[i][j];
            }
      }

      vector<vector<int>> deg(2008, vector<int>(2008));
      stack<pair<int, int>> q;
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  deg[i][j] += a[i-1][j] == '.';
                  deg[i][j] += a[i+1][j] == '.';
                  deg[i][j] += a[i][j-1] == '.';
                  deg[i][j] += a[i][j+1] == '.';
                  if (deg[i][j] == 1) {q.push({i, j});}
            }
      }

      while (q.size()) {
            int i = q.top().first;
            int j = q.top().second;
            q.pop();
            if (a[i][j] != '.') continue;
            deg[i][j] = 0;

            if (a[i-1][j] == '.') {
                  a[i][j] = 'v';
                  a[i-1][j] = '^';
                  deg[i-1][j] = 0;

                  int k = i-1;
                  if (deg[k-1][j]) deg[k-1][j]--;
                  if (deg[k+1][j]) deg[k+1][j]--;
                  if (deg[k][j-1]) deg[k][j-1]--;
                  if (deg[k][j+1]) deg[k][j+1]--;

                  if (deg[k-1][j] == 1) q.push({k-1, j});
                  if (deg[k+1][j] == 1) q.push({k+1, j});
                  if (deg[k][j-1] == 1) q.push({k, j-1});
                  if (deg[k][j+1] == 1) q.push({k, j+1});
            } else if (a[i+1][j] == '.') {
                  a[i][j] = '^';
                  a[i+1][j] = 'v';
                  deg[i+1][j] = 0;

                  int k = i+1;
                  if (deg[k-1][j]) deg[k-1][j]--;
                  if (deg[k+1][j]) deg[k+1][j]--;
                  if (deg[k][j-1]) deg[k][j-1]--;
                  if (deg[k][j+1]) deg[k][j+1]--;

                  if (deg[k-1][j] == 1) q.push({k-1, j});
                  if (deg[k+1][j] == 1) q.push({k+1, j});
                  if (deg[k][j-1] == 1) q.push({k, j-1});
                  if (deg[k][j+1] == 1) q.push({k, j+1});
            } else if (a[i][j+1] == '.') {
                  a[i][j] = '<';
                  a[i][j+1] = '>';
                  deg[i][j+1] = 0;

                  int k = j+1;
                  if (deg[i][k-1]) deg[i][k-1]--;
                  if (deg[i][k+1]) deg[i][k+1]--;
                  if (deg[i-1][k]) deg[i-1][k]--;
                  if (deg[i+1][k]) deg[i+1][k]--;

                  if (deg[i][k-1] == 1) q.push({i, k-1});
                  if (deg[i][k+1] == 1) q.push({i, k+1});
                  if (deg[i-1][k] == 1) q.push({i-1, k});
                  if (deg[i+1][k] == 1) q.push({i+1, k});
            } else if (a[i][j-1] == '.') {
                  a[i][j] = '>';
                  a[i][j-1] = '<';
                  deg[i][j-1] = 0;

                  int k = j-1;
                  if (deg[i][k-1]) deg[i][k-1]--;
                  if (deg[i][k+1]) deg[i][k+1]--;
                  if (deg[i-1][k]) deg[i-1][k]--;
                  if (deg[i+1][k]) deg[i+1][k]--;

                  if (deg[i][k-1] == 1) q.push({i, k-1});
                  if (deg[i][k+1] == 1) q.push({i, k+1});
                  if (deg[i-1][k] == 1) q.push({i-1, k});
                  if (deg[i+1][k] == 1) q.push({i+1, k});
            } else {
                  cout << "Not unique"; return 0;
            }
      }

      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  if (a[i][j] == '.') {cout << "Not unique"; return 0;}
            }
      }

      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  cout << a[i][j];
            }
            cout << '\n';
      }

      return 0;
}