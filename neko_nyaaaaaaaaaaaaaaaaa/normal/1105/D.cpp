#include <bits/stdc++.h>
using namespace std;

#define int long long
int M = 1e9+7;

int n, m, p, cs;
int speed[9];
set<pair<int, int>> s[9];
char c[1001][1001];

void expand(int pl, int sp) {
      queue<tuple<int, int, int>> q;
      for (auto u: s[pl]) {
            q.push(make_tuple(u.first, u.second, 0));
      }
      s[pl].clear();

      while (q.size()) {
            auto [x, y, d] = q.front();
            q.pop();

            c[x][y] = char(pl + '1');
            if (d >= sp) {
                  s[pl].insert({x, y});
                  continue;
            }

            if (c[x-1][y] == '.') {q.push(make_tuple(x-1, y, d+1)); cs = 1;}
            if (c[x+1][y] == '.') {q.push(make_tuple(x+1, y, d+1)); cs = 1;}
            if (c[x][y+1] == '.') {q.push(make_tuple(x, y+1, d+1)); cs = 1;}
            if (c[x][y-1] == '.') {q.push(make_tuple(x, y-1, d+1)); cs = 1;}
      }
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);
      memset(c, '#', sizeof(c));

      cin >> n >> m >> p;
      for (int i = 0; i < p; i++) {
            cin >> speed[i];
      }
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  cin >> c[i][j];
                  for (char k = '1'; k <= '9'; k++) {
                        if (c[i][j] == k) {
                              s[k - '1'].insert({i, j});
                        }
                  }
            }
      }

      while (1) {
            cs = 0;
            for (int i = 0; i < p; i++) {
                  expand(i, speed[i]);
            }

            if (cs == 0) break;
      }

      vector<int> ans(9);
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  for (char k = '1'; k <= '9'; k++) {
                        if (c[i][j] == k) {
                              ans[k - '1']++;
                        }
                  }
            }
      }

      for (int i = 0; i < p; i++) cout << ans[i] << ' ';

      return 0;
}