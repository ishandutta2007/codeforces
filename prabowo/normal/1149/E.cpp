#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
vector<int> edges[N];

bool vis[N];
int mex[N];

int getMex(int u) {
  if (~mex[u]) return mex[u];
  vector<bool> vis(edges[u].size() + 1, false);
  for (int v : edges[u]) {
    vis[min(getMex(v), (int) edges[u].size())] = true;
  }
  mex[u] = 0;
  while (vis[mex[u]]) ++mex[u];
  return mex[u];
}

long long h[N];
long long x[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%lld", &h[i]);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    edges[--u].push_back(--v);
  }

  memset(mex, -1, sizeof mex);
  for (int i = 0; i < n; ++i) {
    x[getMex(i)] ^= h[i];
  }

  for (int i = n - 1; i >= 0; --i) {
    if (x[i] == 0) continue;
    printf("WIN\n");

    for (int j = 0; j < n; ++j) {
      if (getMex(j) != i) continue;
      if ((x[i] ^ h[j]) >= h[j]) continue;
      h[j] = (x[i] ^ h[j]);

      vector<bool> vis(i + 1, false);
      for (int v : edges[j]) {
        if (getMex(v) < i && !vis[getMex(v)]) {
          h[v] = (x[getMex(v)] ^ h[v]);
          vis[getMex(v)] = true;
        }
      }
      break;
    }

    for (int j = 0; j < n; ++j) printf("%lld ", h[j]);
    printf("\n");
    return 0;
  }

  printf("LOSE\n");
  return 0;
}