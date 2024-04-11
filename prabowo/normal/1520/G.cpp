#include <bits/stdc++.h>
using namespace std;
 
const int N = 2005;
const long long INF = 1e18;

int n, m, w;
int a[N][N];

bool visS[N][N];
long long distS[N][N];

bool visE[N][N];
long long distE[N][N];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y, long long dist[N][N], bool vis[N][N]) {
  queue<pair<int, int>> q;
  q.emplace(x, y);
  vis[x][y] = true;
  dist[x][y] = 0;
  while (q.size()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();

    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k], ny = y + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny] || a[nx][ny] == -1) continue;
      vis[nx][ny] = true;
      dist[nx][ny] = dist[x][y] + w;
      q.emplace(nx, ny);
    }
  }

  // for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) printf("%d ", dist[i][j]); printf("\n"); }
  // for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) printf("%d ", dist[i][j]); printf("\n"); }
}

int solve() {
  scanf("%d %d %d", &n, &m, &w);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  bfs(0, 0, distS, visS);
  bfs(n - 1, m - 1, distE, visE);

  long long ans = INF;

  if (visS[n - 1][m - 1]) {
    ans = min(ans, distS[n - 1][m - 1]);
  }

  long long miniStart = INF, miniEnd = INF;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (visS[i][j] && a[i][j] > 0) {
        miniStart = min(miniStart, distS[i][j] + a[i][j]);
      }
      if (visE[i][j] && a[i][j] > 0) {
        miniEnd = min(miniEnd, distE[i][j] + a[i][j]);
      }
    }
  }

  ans = min(ans, miniStart + miniEnd);

  printf("%lld\n", ans >= INF ? -1LL : ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}