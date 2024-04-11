#include<bits/stdc++.h>

using namespace std;

const int N = 505;

struct sum2d{
  int a[N][N];

  void set(int i, int j, int val) {
    a[i][j] = val;
  }

  void process() {
    for(int i = 1; i < N; ++i) {
      for(int j = 1; j < N; ++j) {
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
      }
    }
  }

  int get(int x, int y, int u, int v) {
    return a[u][v] - a[x - 1][v] - a[u][y - 1] + a[x - 1][y - 1];
  }
};

sum2d color[4];
sum2d recsize[255];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m, q;
  cin >> n >> m >> q;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      char c; cin >> c;
      if(c == 'R') color[0].set(i, j, 1);
      if(c == 'G') color[1].set(i, j, 1);
      if(c == 'Y') color[2].set(i, j, 1);
      if(c == 'B') color[3].set(i, j, 1);
    }
  }

  for(int i = 0; i < 4; ++i) color[i].process();

  int dx[4] = {0, 0, 1, 1};
  int dy[4] = {0, 1, 0, 1};

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j){
      for(int k = 1; k <= n; ++k) {
        if(i + 2 * k - 1 > n || j + 2 * k - 1 > m) break;
        int req = k * k, flag = 1;
        for(int t = 0; t < 4; ++t) {
          int x = i + dx[t] * k;
          int y = j + dy[t] * k;
          if(color[t].get(x, y, x + k - 1, y + k - 1) != req) {
            flag = 0;
          }
        }
        recsize[k].set(i, j, flag);
      }
    }
  }


  for(int i = 1; i <= n / 2; ++i) recsize[i].process();

  while(q--) {
    int x, y, u, v;
    cin >> x >> y >> u >> v;

    int ans = 0;
    for(int k = 250; k >= 1; --k) {
      int nx = u - k * 2 + 1, ny = v - k * 2 + 1;
      if(x > nx || y > ny) continue;
      if(recsize[k].get(x, y, nx, ny)) {
        ans = k;
        break;
      }
    }
    cout << (ans << 1) * (ans << 1) << "\n";
  }

  return 0;
}