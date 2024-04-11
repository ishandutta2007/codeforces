#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, m;
char s[N][N];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool vis[N][N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);

    for (int j = 0; j < m; ++j) vis[i][j] = false;
  }

  int cntG = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'G') ++cntG;
      if (s[i][j] != 'B') continue;
      for (int k = 0; k < 4; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        if (s[nx][ny] == 'G') return 0 * printf("No\n");
        if (s[nx][ny] == 'B') continue;
        s[nx][ny] = '#';
      }
    }
  }

  queue<pair<int, int>> q;
  if (s[n-1][m-1] != '#') {
    q.push({n-1, m-1});
    vis[n-1][m-1] = true;
  }

  int foundG = 0;
  while (q.size()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();

    if (s[x][y] == 'G') ++foundG;

    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny]) continue;
      if (s[nx][ny] == '#') continue;

      vis[nx][ny] = true;
      q.push({nx, ny});
    }
  }

  if (foundG == cntG) printf("Yes\n");
  else printf("No\n");
  return 0;
}


int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}