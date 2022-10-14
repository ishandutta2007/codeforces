#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

void Main() {
  int n, m, q;
  cin >> n >> m >> q;
  lint answer = 0;
  vector<vector<int>> a(n, vector<int>(m));
  vector<vector<pair<int, int>>> ls(n + m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ls[m - 1 + i - j].emplace_back(i, j);
    }
  }
  const auto Is0 = [&](int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && a[x][y] == 0;
  };
  const auto Calc = [&](int pos, int sgn) {
    if (pos < 0 || pos >= n + m - 1) return;
    for (int rep = 0; rep < 2; rep++) {
      int dx, dy;
      if (rep == 0) {
        dx = 0, dy = 1;
      } else {
        dx = 1, dy = 0;
      }
      int len = 1;
      for (int i = 0; i < ls[pos].size(); i++) {
        auto [x, y] = ls[pos][i];
        if (a[x][y] == 1) {
          len = 0;
          continue;
        }
        len = max(len, 1);
        while (true) {
          if (len & 1) {
            if (Is0(x + len / 2 + dx, y + len / 2 + dy)) {
              len += 1;
            } else {
              break;
            }
          } else {
            if (Is0(x + len / 2, y + len / 2)) {
              len += 1;
            } else {
              break;
            }
          }
        }
        answer += (len - rep) * sgn;
        len -= 2;
      }
    }
  };
  for (int i = 0; i < n + m - 1; i++) {
    Calc(i, 1);
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    Calc(m - 1 + x - y - 1, -1);
    Calc(m - 1 + x - y, -1);
    Calc(m - 1 + x - y + 1, -1);
    a[x][y] ^= 1;
    Calc(m - 1 + x - y - 1, 1);
    Calc(m - 1 + x - y, 1);
    Calc(m - 1 + x - y + 1, 1);
    cout << answer << '\n';
  }
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}