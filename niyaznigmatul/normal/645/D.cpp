#include <bits/stdc++.h>

using namespace std;

int const N = 1234567;

vector<int> edges[N];
int deg[N], to[N], from[N], q[N], where[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", from + i, to + i);
    --from[i];
    --to[i];
    edges[from[i]].push_back(to[i]);
    deg[to[i]]++;
  }
  int head = 0;
  int tail = 0;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      q[tail++] = i;
    }
  }
  while (head < tail) {
    int v = q[head++];
    for (int u : edges[v]) {
      --deg[u];
      if (deg[u] == 0) {
        q[tail++] = u;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    where[q[i]] = i;
  }
  int cn = 0;
  int ans = -1;
  for (int i = 0; i < m; i++) {
    if (where[from[i]] == where[to[i]] - 1) {
      ans = i;
      ++cn;
    }
  }
  if (cn < n - 1) {
    puts("-1");
  } else {
    printf("%d\n", ans + 1);
  }
}