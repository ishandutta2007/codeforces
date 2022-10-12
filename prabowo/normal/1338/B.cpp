#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
vector<int> edges[N];

int mini;
void dfsmin(int u, int p, int val) {
  for (int v: edges[u]) {
    if (v == p) continue;
    if (edges[v].size() == 1) {
      if (val == 0) mini = 3;
    } else {
      dfsmin(v, u, val ^ 1);
    }
  }
}

int maks;
void dfsmax(int u, int p, int d) {
  bool hasLeaf = false;
  for (int v: edges[u]) {
    if (v == p) continue;
    if (edges[v].size() == 1) {
      hasLeaf = true;
    } else {
      ++maks;
      dfsmax(v, u, d+1);
    }
  }

  if (hasLeaf && d != 1) ++maks; 
}

int solve() {
  scanf("%d", &n);
  int u, v;
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int root = -1;
  for (int i = 0; i < n; ++i) {
    if (edges[i].size() == 1) {
      root = i;
      break;
    }
  }

  mini = 1, maks = 0;
  dfsmin(root, root, 0);
  dfsmax(root, root, 0);

  printf("%d %d\n", mini, maks);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}