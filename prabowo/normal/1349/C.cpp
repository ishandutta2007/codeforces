#include <bits/stdc++.h>
using namespace std;
 
const int N = 1005;
 
int n, m, t;
char s[N][N];
 
int dist[N][N];
 
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
bool ok(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(const vector<pair<int, int>> &starts) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dist[i][j] = -1;
    }
  }

  queue<pair<int, int>> q;
  for (pair<int, int> u: starts) {
    int x, y;
    tie(x, y) = u;
    q.push(u);
    dist[x][y] = 0;
  }
 
  while (q.size()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();
 
    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k], ny = y + dy[k];
      if (!ok(nx, ny)) continue;
 
      if (dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[x][y] + 1;
      q.push({nx, ny});
    }
  }
}
 
int solve() {
  scanf("%d %d %d", &n, &m, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
 
  vector<pair<int, int>> v;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      bool dif = false;
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (!ok(nx, ny)) continue;
 
        if (s[nx][ny] == s[x][y]) {
          dif = true;
          break;
        }
      }
      if (dif) v.emplace_back(x, y);
    }
  }

  bfs(v);
  
  while (t--) {
    int x, y; long long p;
    scanf("%d %d %lld", &x, &y, &p);
    --x, --y;
 
    if (dist[x][y] == -1 || dist[x][y] >= p) {
      printf("%c\n", s[x][y]);
    } else {
      int ans = (s[x][y] - '0') ^ (p - dist[x][y] & 1);
      printf("%d\n", ans);
    }
  }
  return 0;
}
 
int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}