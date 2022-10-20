#include <bits/stdc++.h>

using namespace std;

const int N = 200100;

int n;
int f[N][2], g[N][2], leaves[N];
vector <int> a[N];

void dfs(int u, int p) {
  if (u != 1 && a[u].size() == 1) {
    f[u][0] = f[u][1] = g[u][0] = g[u][1] = 1;
    leaves[u] = 1;
    return;
  }
  f[u][1] = f[u][0] = 0;
  g[u][1] = g[u][0] = 1000000000;
  int minval = 1000000000, sumval = 0;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) {
      continue;
    }
    dfs(v, u);
    leaves[u] += leaves[v];
    f[u][0] += g[v][1];
    g[u][1] = min(g[u][1], f[v][0]);
    minval = min(minval, leaves[v] - g[v][0]);
    sumval += (leaves[v] - f[v][1] + 1);
  }
  f[u][1] = leaves[u] - minval;
  g[u][0] = leaves[u] - sumval + 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    return 0;
  }
  dfs(1, 0);
  cout << f[1][1] << " " << f[1][0] << endl;
  return 0;
}