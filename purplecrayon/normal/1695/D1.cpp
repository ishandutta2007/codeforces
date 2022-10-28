/**
 *    author:  tourist
 *    created: 03.02.2018 17:42:14       
**/
#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;
const int N = 400010;

vector<int> g[N];
int f[N][2][3];

inline void update(int &a, int b) {
  a = min(a, b);
}

void dfs(int v, int pr) {
  vector<int> children;
  for (int u : g[v]) {
    if (u == pr) {
      continue;
    }
    dfs(u, v);
    children.push_back(u);
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      f[v][i][j] = inf;
    }
  }
  if (children.empty()) {
    f[v][0][0] = 0;
    f[v][1][0] = 1;
    return;
  }
  if ((int) children.size() == 1) {
    int u = children[0];
    update(f[v][0][1], f[u][0][0]);
    update(f[v][0][2], f[u][0][1]);
    update(f[v][0][2], f[u][0][2]);
    update(f[v][1][1], 1 + f[u][0][0]);
    update(f[v][1][2], 1 + f[u][0][1]);
    update(f[v][1][2], f[u][1][1]);
    update(f[v][1][2], f[u][1][2]);
    update(f[v][1][0], f[u][1][0]);
    update(f[v][1][0], 1 + f[u][1][1]);
    return;
  }
  {
    // take = 1
    int sum = 1;
    for (int u : children) {
      sum += min({f[u][1][0], f[u][1][1], f[u][1][2]});
    }
    update(f[v][1][0], sum);
    for (int u : children) {
      sum -= min({f[u][1][0], f[u][1][1], f[u][1][2]});
      update(f[v][1][1], sum + f[u][0][0]);
      update(f[v][1][1], sum + f[u][0][1]);
      update(f[v][1][1], sum + f[u][0][2]);
      sum += min({f[u][1][0], f[u][1][1], f[u][1][2]});
    }
  }
  {
    // take = 0
    int sum = 0;
    for (int u : children) {
      sum += min({f[u][1][0], f[u][1][1], f[u][1][2]});
    }
    update(f[v][1][0], sum);
    if ((int) children.size() > 2) {
      for (int u : children) {
        sum -= min({f[u][1][0], f[u][1][1], f[u][1][2]});
        update(f[v][1][1], sum + f[u][0][0]);
        update(f[v][1][1], sum + f[u][0][1]);
        update(f[v][1][1], sum + f[u][0][2]);
        sum += min({f[u][1][0], f[u][1][1], f[u][1][2]});
      }
    } else {
      for (int u : children) {
        int w = children[0] + children[1] - u;
        sum = min({f[u][0][0], f[u][0][1], f[u][0][2]});
        update(f[v][1][1], sum + f[w][1][0]);
        update(f[v][1][2], sum + f[w][1][1]);
        update(f[v][1][2], sum + f[w][1][2]);
      }
    }
  }
}

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) g[i].clear();
  for (int i = 0; i <= n; i++) for (int a = 0; a < 2; a++) for (int b = 0; b < 3; b++)
      f[i][a][b] = 0;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (n == 1) {
      printf("%d\n", 0);
      return;
  }
  dfs(0, -1);
  printf("%d\n", min(f[0][1][0], f[0][1][1]));
//  for (int i = 0; i < n; i++) {
  //  cerr << i << " -> " << f[i][0][0] << " " << f[i][0][1] << " " << f[i][0][2] << " " << f[i][1][0] << " " << f[i][1][1] << " " << f[i][1][2] << endl;
//  }
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}