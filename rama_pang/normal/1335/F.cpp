#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int n, m;
vector<string> color;
vector<string> direction;

int vis[1005 * 1005];
pair<int, int> ans;
int go[1005 * 1005][22];
pair<int, int> memo[1005 * 1005];

pair<int, int> dfs(int i, int j, int d) {
  if (vis[i * m + j] < 0) return memo[i * m + j];
  if (vis[i * m + j]) {
    return {d - vis[i * m + j], - (d - vis[i * m + j])};
  }

  vis[i * m + j] = d;
  pair<int, int> len;
  if (direction[i][j] == 'U') {
    len = dfs(i - 1, j, d + 1);
  }
  if (direction[i][j] == 'D') {
    len = dfs(i + 1, j, d + 1);
  }
  if (direction[i][j] == 'L') {
    len = dfs(i, j - 1, d + 1);
  }
  if (direction[i][j] == 'R') {
    len = dfs(i, j + 1, d + 1);
  }
  len.second++;

  if (len.second <= 0) { // in cycle
    ans.first++;
    vis[i * m + j] = -1;
    memo[i * m + j] = {len.first, 0};
    // cout << i << " " << j << " " << len.second << " cycle \n";
    if (color[i][j] == '0') ans.second++;
  } else {
    vis[i * m + j] = -2;
    memo[i * m + j] = len;
    int to = len.second + len.first - (len.second % len.first);
    int cur = i * m + j;
    for (int k = 21; k >= 0; k--) {
      if (to & (1 << k)) {
        cur = go[cur][k];
      }
    }
    int r = cur / m, c = cur % m;
    if (color[i][j] == '0' && color[r][c] == '1') {
      ans.second++;
      color[r][c] = '0';
    }
  }

  return len;
}

void Solve() {
  cin >> n >> m;
  color.resize(n);
  direction.resize(n);
  ans = {0, 0};
  for (int i = 0; i < n; i++) {
    cin >> color[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> direction[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vis[i * m + j] = 0;
      memo[i * m + j] = {0, 0};

      if (direction[i][j] == 'U') {
        go[i * m + j][0] = (i - 1) * m + j;
      }
      if (direction[i][j] == 'D') {
        go[i * m + j][0] = (i + 1) * m + j;
      }
      if (direction[i][j] == 'L') {
        go[i * m + j][0] = i * m + j - 1;
      }
      if (direction[i][j] == 'R') {
        go[i * m + j][0] = i * m + j + 1;
      } 
    }
  }
  for (int j = 1; j < 22; j++) {
    for (int i = 0; i < n * m; i++) {
      go[i][j] = go[go[i][j - 1]][j - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i * m + j] != 0) continue;
      dfs(i, j, 1).first;
    }
  }
  cout << ans.first << " " << ans.second << "\n";

  color.clear();
  direction.clear();
  color.shrink_to_fit();
  direction.shrink_to_fit();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    Solve();
  }

}