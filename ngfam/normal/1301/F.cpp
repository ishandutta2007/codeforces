#include<bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

const int MAXC = 41;
const int MAXN = 1005;

int n, m, k;
int a[MAXN][MAXN];

int mark[MAXC];
short f[MAXC][MAXN][MAXN];

int szque;
pair<int, int> que[MAXN * MAXN];

vector<pair<int, int>> cells[MAXC];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      cells[a[i][j]].emplace_back(i, j);
    }
  }

  for(int c = 1; c <= k; ++c) {
    memset(f[c], 60, sizeof f[c]);
    memset(mark, 0, sizeof mark);
    mark[c] = 1;

    szque = 0;
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
        if(a[i][j] == c) {
          f[c][i][j] = 0;
          que[szque++] = make_pair(i, j);
        }
      }
    }

    for(int t = 0; t < szque; ++t) {
      int x = que[t].first, y = que[t].second;

      if(!mark[a[x][y]]) {
        for(auto &p : cells[a[x][y]]) {
          int nx = p.first, ny = p.second;
          if(f[c][x][y] + 1 >= f[c][nx][ny]) continue;
          f[c][nx][ny] = f[c][x][y] + 1;
          que[szque++] = make_pair(nx, ny);


        }
        mark[a[x][y]] = 1;
      }

      for(int d = 0; d < 4; ++d) {
        int nx = x + dx[d], ny = y + dy[d];
        if(a[nx][ny] == 0 || f[c][x][y] + 1 >= f[c][nx][ny]) continue;
        f[c][nx][ny] = f[c][x][y] + 1;
        que[szque++] = make_pair(nx, ny);
      }
    }

  }


  int q; cin >> q;
  while(q--) {
    int x, y, sx, sy;
    cin >> x >> y >> sx >> sy;

    int ans = min(85, abs(sx - x) + abs(y - sy));

    for(int step = 0; step <= 40; ++step) {
      for(int i = 0; i <= step; ++i) {
        int j = step - i;
        for(int signx : {1, -1}){
          for(int signy : {1, -1}) {
            int nx = x + signx * i;
            int ny = y + signy * j;
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            ans = min(ans, step + 1 + f[a[nx][ny]][sx][sy]);
          }
        }
      }
    }

    cout << ans << "\n";
  }


  return 0;
}