#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int indeg[N];
vector<int> edges[N];
vector<int> redges[N];
bool closed[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    indeg[i] = 0;
    edges[i].clear();
    redges[i].clear();
    closed[i] = false;
  }

  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;

    edges[x].push_back(y);
    redges[y].push_back(x);
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (closed[i]) continue;
    if (indeg[i] > 0) {
      for (int j: edges[i]) closed[j] = true;
    } else {
      for (int j: edges[i]) ++indeg[j];
    }
  }

  for (int i = 0; i < n; ++i) {
    if (closed[i]) ans.push_back(i);
  }

  printf("%d\n", (int) ans.size());
  for (int u: ans) printf("%d ", u+1);
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}