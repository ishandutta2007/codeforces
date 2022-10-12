#include <bits/stdc++.h>
using namespace std;

const int N = 1505;
const int MOD = 998244353;

int n;
int a[N][N];

tuple<int, int, int> edges[N*N];
vector<int> dp[N];

vector<int> multiply(vector<int> &a, vector<int> &b) {
  vector<int> c(a.size() + b.size() - 1);
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      c[i+j] = (1LL * a[i] * b[j] + c[i+j]) % MOD;
    }
  }
  return c;
}

int par[N], cnt[N], sz[N];
int root(int u) {
  if (u == par[u]) return u;
  return par[u] = root(par[u]);
}

int main() {
  scanf("%d", &n);
  int e = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      if (i < j) {
        edges[e++] = make_tuple(a[i][j], i, j);
      }
    }
  }

  sort(edges, edges + e);
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    cnt[i] = 0;
    sz[i] = 1;
    dp[i] = {0, 1};
  }

  for (int i = 0; i < e; ++i) {
    int w, u, v;
    tie(w, u, v) = edges[i];

    if (root(u) != root(v)) {
      cnt[par[u]] += cnt[par[v]];
      sz[par[u]] += sz[par[v]];
      dp[par[u]] = multiply(dp[par[u]], dp[par[v]]);

      par[par[v]] = par[u];
    }

    ++cnt[par[u]];
    if (sz[par[u]] * (sz[par[u]] - 1) / 2 == cnt[par[u]]) ++dp[par[u]][1];
  }

  for (int i = 1; i <= n; ++i) {
    printf("%d ", dp[root(0)][i] % MOD);
  }
  printf("\n");
  return 0;
}