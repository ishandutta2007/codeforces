#include <bits/stdc++.h>
using namespace std;

const int LN = 18;
const int N = 100005;

int n;
int x[N];
long long y[N];

long long cross(int i, int j, int k) {
  return 1LL * (x[j] - x[i]) * (y[k] - y[j]) - 1LL * (x[k] - x[j]) * (y[j] - y[i]);
}

int depth[N];
int par[LN][N];

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  while (depth[u] != depth[v]) u = par[__builtin_ctz(depth[u] - depth[v])][u];

  if (u == v) return u;

  for (int i = LN-1; i >= 0; --i) {
    if (par[i][u] == par[i][v]) continue;
    u = par[i][u];
    v = par[i][v];
  }

  return par[0][u];
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %lld", &x[i], &y[i]);
  }

  vector<int> v;
  for (int i = n-1; i >= 0; --i) {
    while (v.size() >= 2 && cross(i, v.back(), v[v.size() - 2]) > 0) {
      v.pop_back();
    }

    if (v.size() > 0) {
      par[0][i] = v.back();
      depth[i] = depth[par[0][i]] + 1;
    } else {
      par[0][i] = i;
      depth[i] = 0;
    }

    v.push_back(i);

    // cerr << par[0][i] << endl;
  }

  for (int i = 1; i < LN; ++i) {
    for (int j = 0; j < n; ++j) {
      par[i][j] = par[i-1][par[i-1][j]];
    }
  }

  int m;
  scanf("%d", &m);
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    printf("%d ", lca(u, v) + 1);
  }
  printf("\n");

  return 0;
}

int main() {
  int t = 1;
  // cin >> t;
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}