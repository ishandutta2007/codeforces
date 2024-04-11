#include <bits/stdc++.h>

using namespace std;

const int N = 100010, MOD = 1000000007;

int n;
vector <pair<int, int> > a[N];
int par[20][N], lv[N], in1[N], in2[N], out1[N], out2[N];
long long res = 0, sl1[N], sl2[N], Pow[N * 10];

long long qplus(long long u, long long v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

void dfs(int u, int p) {
  par[0][u] = p;
  lv[u] = lv[p] + 1;
  for (pair<int, int> v : a[u]) {
    if (v.first == p) {
      continue;
    }
    dfs(v.first, u);
  }
}

int lca(int u, int v) {
  if (lv[u] > lv[v]) {
    swap(u, v);
  }
  int l = lv[v] - lv[u];
  for (int i = 19; i >= 0; i--) {
    if (l & (1 << i)) {
      v = par[i][v];
    }
  }
  if (v == u) {
    return v;
  }
  for (int i = 19; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][u];
}

void dfs2(int u, int p) {
  for (pair<int, int> v : a[u]) {
    if (v.first == p) {
      continue;
    }
    dfs2(v.first, u);
    sl1[u] = qplus(sl1[u], sl1[v.first]);
    sl2[u] = qplus(sl2[u], sl2[v.first]);
    if (v.second == 1) {
      res = (res + Pow[sl1[v.first]] - 1 + MOD) % MOD;
    }
    if (v.second == 2) {
      res = (res + Pow[sl2[v.first]] - 1 + MOD) % MOD;
    }
  }
  sl1[u] += in1[u] - out1[u];
  sl2[u] += in2[u] - out2[u];
}

int main() {
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    if (c == 1) {
      a[u].push_back(make_pair(v, c));
      a[v].push_back(make_pair(u, c ^ 3));
    } else {
      a[u].push_back(make_pair(v, 0));
      a[v].push_back(make_pair(u, 0));
    }
  }
  dfs(1, 0);
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      par[i][j] = par[i - 1][par[i - 1][j]];
    }
  }
  int k;
  scanf("%d", &k);
  int cur = 1;
  for (int i = 1; i <= k; i++) {
    int next;
    scanf("%d", &next);
    int w = lca(cur, next);
    if (w != cur) {
      out1[w]++;
      in1[cur]++;
    }
    if (w != next) {
      out2[w]++;
      in2[next]++;
    }
    cur = next;
  }
  Pow[0] = 1;
  for (int i = 1; i < N * 10; i++) {
    Pow[i] = qplus(Pow[i - 1], Pow[i - 1]);
  }
  dfs2(1, 0);
  printf("%I64d", res);
  return 0;
}