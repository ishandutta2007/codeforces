#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
int e[N];

int deg[N];
vector<int> edges[N];

queue<int> q[2];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &e[i]);
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &v, &u);

    edges[u].push_back(v);
    ++deg[v];
  }

  for (int i = 0; i < n; ++i) {
    if (deg[i] > 0) continue;
    q[e[i]].push(i);
  }

  int cur = 0;
  int ans = 0;
  while (q[0].size() > 0 || q[1].size() > 0) {
    if (q[cur].size() == 0) {
      cur ^= 1;
      ans += cur;
    }

    int u = q[cur].front();
    q[cur].pop();

    for (int v: edges[u]) {
      if (--deg[v] == 0) {
        q[e[v]].push(v);
      }
    }
  }

  printf("%d\n", ans);
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