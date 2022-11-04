#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, k;
char f[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool vis[N][N];
int c[N][N];
int w[N * N];
int nw[N * N];
int curw[N * N];
int ptr;
int tmp[4 * N];
bool calced[N * N];

bool in_bounds(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < n && f[x][y] == '.';
}

void dfs(int x, int y) {
  vis[x][y] = 1;
  w[c[x][y]]++;
  
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (in_bounds(nx, ny) && !vis[nx][ny]) {
      c[nx][ny] = c[x][y];
      dfs(nx, ny);
    }
  }
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
  
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> f[i][j];
    }
  }
  
  int comps = 0;
  
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      if (!vis[x][y] && f[x][y] == '.') {
        c[x][y] = comps++;
        dfs(x, y);
      }
    }
  }
  
  int ans = 0;
  
  for (int i = 0; i + k - 1 < n; i++) {
    for (int j = 0; j < comps; j++) nw[j] = w[j];
        
    for (int x = i; x < i + k; x++) {
      for (int y = 0; y < k; y++) {
        if (in_bounds(x, y)) nw[c[x][y]]--;
      }
    }
    
    for (int j = 0; j + k - 1 < n; j++) {
      int cur = k * k;
      ptr = 0;
      
      for (int x = i; x < i + k; x++) {
        if (in_bounds(x, j - 1)) tmp[ptr++] = c[x][j - 1];
        if (in_bounds(x, j + k)) tmp[ptr++] = c[x][j + k];
      }
      
      for (int y = j; y < j + k; y++) {
        if (in_bounds(i - 1, y)) tmp[ptr++] = c[i - 1][y];
        if (in_bounds(i + k, y)) tmp[ptr++] = c[i + k][y];
      }
                  
      for (int t = 0; t < ptr; t++) {
        if (!calced[tmp[t]]) {
          cur += nw[tmp[t]];
          calced[tmp[t]] = 1;
        }
      }
      
      for (int t = 0; t < ptr; t++) {
        calced[tmp[t]] = 0;
      }
      
      for (int t = i; t < i + k; t++) {
        if (in_bounds(t, j)) nw[c[t][j]]++;
        if (in_bounds(t, j + k)) nw[c[t][j + k]]--;
      }
      
      ans = max(ans, cur);
    }
  }
  
  cout << ans << "\n";

	return 0;
}