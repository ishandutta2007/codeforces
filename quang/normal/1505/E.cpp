#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto &u : s) cin >> u;
  int x = 0, y = 0;
  int res = 0;
  while (1) {
    //cerr << x << ' ' << y << endl;
    res += s[x][y] == '*';
    int xx = -1, yy = 0;
    int dist = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (x <= i && y <= j && (x != i || y != j) && s[i][j] == '*') {
          if (xx == -1) {
            xx = i;
            yy = j;
            dist = abs(x - i) + abs(y - j);
          } else {
            int cur_dist = abs(x - i) + abs(y - j);
            if (cur_dist < dist) {
              xx = i;
              yy = j;
              dist = cur_dist;
            } 
          }
        }
      }
    }
    if (xx == -1) break;
    x = xx;
    y = yy;
    //cout << dist << endl;
  }
  cout << res << endl;
  return 0;
}