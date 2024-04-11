#include <bits/stdc++.h>
using namespace std;
 
const int N = 2005;

int n;
int a[N][N];

int salaries[N];
vector<pair<int, int>> edges;

int sz;
int dfs(vector<int> nodes) {
  if (nodes.size() == 1) {
    salaries[nodes[0]] = a[nodes[0]][nodes[0]];
    return nodes[0];
  }

  int cur = sz++;

  int maxi = 0;
  for (int u : nodes) {
    maxi = max(maxi, a[nodes[0]][u]);
  }

  vector<vector<int>> nnodes;

  while (nodes.size() > 0) {
    vector<int> lnodes, rnodes;
    lnodes.push_back(nodes[0]);
    for (int i = 1; i < nodes.size(); ++i) {
      if (a[nodes[0]][nodes[i]] == maxi) {
        rnodes.push_back(nodes[i]);
      } else {
        lnodes.push_back(nodes[i]);
      }
    }

    nnodes.push_back(lnodes);
    nodes = rnodes;
  }

  salaries[cur] = maxi;

  for (vector<int> nn : nnodes) {
    edges.emplace_back(dfs(nn), cur);
  }

  return cur;
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  vector<int> nodes(n);
  for (int i = 0; i < n; ++i) {
    nodes[i] = i;
  }

  sz = n;

  int root = dfs(nodes);

  printf("%d\n", sz);
  for (int i = 0; i < sz; ++i) printf("%d ", salaries[i]);
  printf("\n");

  printf("%d\n", root + 1);
  for (pair<int, int> edge : edges) {
    printf("%d %d\n", edge.first + 1, edge.second + 1);
  }
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