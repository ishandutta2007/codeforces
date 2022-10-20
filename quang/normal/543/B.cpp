#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const int MAX = 1000000000;

int n, m;
vector <int> a[N];
int d[N][N], used[N];

void go(int x) {
  for (int i = 1; i <= n; i++) {
    d[x][i] = MAX;
    used[i] = 0;
  }
  d[x][x] = 0;
  priority_queue <pair<int, int> > p;
  p.push(make_pair(0, x));
  while (!p.empty()) {
    int u = p.top().second;
    p.pop();
    if (used[u]) {
      continue;
    }
    used[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
      int v = a[u][i];
      if (d[x][v] > d[x][u] + 1) {
        d[x][v] = d[x][u] + 1;
        p.push(make_pair(-d[x][v], v));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    go(i);
  }
  int s1, t1, l1, s2, t2, l2;
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
  int res = -1;
  if (d[s1][t1] > l1 || d[s2][t2] > l2) {
    cout << -1;
    return 0;
  }
  res = m - d[s1][t1] - d[s2][t2];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (d[s1][i] + d[i][j] + d[j][t1] > l1 || d[s2][i] + d[i][j] + d[j][t2] > l2) {
        continue;
      }
      res = max(res, m - d[i][j] - d[s1][i] - d[s2][i] - d[j][t1] - d[j][t2]);
    }
  }
  swap(t1, s1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (d[s1][i] + d[i][j] + d[j][t1] > l1 || d[s2][i] + d[i][j] + d[j][t2] > l2) {
        continue;
      }
      res = max(res, m - d[i][j] - d[s1][i] - d[s2][i] - d[j][t1] - d[j][t2]);
    }
  }
  cout << res << endl;
  return 0;
}