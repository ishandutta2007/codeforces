#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

const int X[] = {0, 1, 0, -1};
const int Y[] = {1, 0, -1, 0};

int n, m;
vector<string> s;
vector<vector<bool>> used;
vector<pair<int, int>> order;

bool IsInside(int u, int v) {
  return u >= 0 && u < n && v >= 0 && v < m;
}

void Dfs(int u, int v, bool add = true) {
  used[u][v] = 1;
  if (s[u][v] == '#') {
    for (int i = 0; i < 4; i++) {
      int uu = u + X[i];
      int vv = v + Y[i];
      if (IsInside(uu, vv) && !used[uu][vv]) {
        Dfs(uu, vv, add);
      }
    }
  } else {
    int uu = u + 1;
    int vv = v;
    if (IsInside(uu, vv) && !used[uu][vv]) {
      Dfs(uu, vv, add);
    }
  }
  if (add) order.push_back({u, v});
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  s = vector<string>(n);
  used = vector<vector<bool>>(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  order.reserve(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!used[i][j] && s[i][j] == '#') {
        Dfs(i, j);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      used[i][j] = false;
    }
  }
  reverse(order.begin(), order.end());
  for (auto [u, v] : order) {
    if (!used[u][v] && s[u][v] == '#') {
      res++;
      Dfs(u, v, false);
    }
  }
  cout << res << endl;
  return 0;
}