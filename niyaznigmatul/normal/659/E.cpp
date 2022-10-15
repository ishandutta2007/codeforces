#include <bits/stdc++.h>

int const N = 123456;
using namespace std;

int was[N];

vector<int> edges[N];

int dfs(int v, int pv) {
  was[v] = 1;
  for (int to : edges[v]) {
    if (to == pv) continue;
    if (was[to] == 1) {
      return v;
    }
    int got = dfs(to, v);
    if (got >= 0) {
      return got;
    }    
  }
  return -1;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    edges[v].push_back(u);
    edges[u].push_back(v);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int v = dfs(i, -1);
    if (v < 0) {
      v = i;
      ans++;
    }    
  }
  printf("%d\n", ans);
}