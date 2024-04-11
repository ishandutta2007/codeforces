#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
vector<int> edges[N];
int deg[N];
bool leaf[N];
int leafCnt[N];
bool removed[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    edges[i].clear();
    deg[i] = 0;
    removed[i] = false;
    leaf[i] = false;
    leafCnt[i] = 0;
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
    ++deg[u]; ++deg[v];
  }

  if (m == 1) return 0 * printf("%d\n", n-1);

  for (int i = 0; i < n; ++i) {
    if (deg[i] == 1) leaf[i] = true;
    else leaf[i] = false;
  }

  queue<int> q;
  for (int i = 0; i < n; ++i) {
    leafCnt[i] = 0;
    for (int v: edges[i]) {
      if (leaf[v]) ++leafCnt[i];
    }

    if (leafCnt[i] >= m) {
      q.push(i);
    }
  }

  int ans = 0;
  while (q.size() > 0) {
    int u = q.front();
    q.pop();

    ans += leafCnt[u] / m;
    int rem = leafCnt[u] - leafCnt[u] % m;
    leafCnt[u] %= m;

    int bdeg = deg[u];

    for (int v: edges[u]) {
      if (leaf[v] && !removed[v] && rem > 0) {
        --deg[u];
        --rem;
        removed[v] = true;
      }
    }

    if (bdeg > 1 && deg[u] == 1) {
      leaf[u] = true;
      for (int v: edges[u]) {
        if (!removed[v]) {
          ++leafCnt[v];
          if (leafCnt[v] >= m) {
            q.push(v);
          }
        }
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}