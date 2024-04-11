#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;

pair<int, int> a[N][N];

char ans[N][N];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int dir[4] = {'L', 'D', 'R', 'U'};

void bfs(pair<int, int> init, pair<int, int> target) {
  queue<pair<int, int>> q;
  q.push(init);
  ans[init.first][init.second] = 'X';
  
  while (q.size()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();
    
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      
      if (ans[nx][ny]) continue;
      if (a[nx][ny] != target) continue;
      ans[nx][ny] = dir[i];
      q.push({nx, ny});
    }
  }
}

int solve() {
  scanf("%d", &n);
  
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d %d", &a[i][j].first, &a[i][j].second);
      if (a[i][j].first > 0) --a[i][j].first, --a[i][j].second;
    }
  }
  
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    if (a[i][j] == make_pair(i, j)) {
      bfs(a[i][j], a[i][j]);
    }
  }
  
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    if (ans[i][j]) continue;
    if (a[i][j] != make_pair(-1, -1)) return 0 * printf("INVALID\n");
    
    bfs({i, j}, a[i][j]);
    
    for (int k = 0; k < 4; ++k) {
      int nx = i + dx[k];
      int ny = j + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (a[nx][ny] != make_pair(-1, -1)) continue;
      ans[i][j] = dir[(k+2) % 4];
      break;
    }
    
    if (ans[i][j] == 'X') return 0 * printf("INVALID\n");
  }
  
  printf("VALID\n");
  for (int i = 0; i < n; ++i) printf("%s\n", ans[i]);
  return 0;
}

int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}