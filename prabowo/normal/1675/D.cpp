#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int p[N];

vector<int> adj[N];

vector<vector<int>> ans;

void dfs(int u, vector<int> &path) {
  path.push_back(u);
  for (int v : adj[u]) {
    dfs(v, path);
    path.clear();
  }

  if (adj[u].size() == 0) {
    // isLeaf
    ans.push_back(path);
  }
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) adj[i].clear();
  int root = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    if (--p[i] == i) {
      root = i;
    } else {
      adj[p[i]].push_back(i);
    }
  }

  vector<int> path;
  ans.clear();
  dfs(root, path);

  printf("%d\n", (int) ans.size());
  for (vector<int> &path : ans) {
    printf("%d\n", (int) path.size());
    for (int u : path) {
      printf("%d ", u + 1);
    }
    printf("\n");
  }

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
}