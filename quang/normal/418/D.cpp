#include <bits/stdc++.h>

#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100010;

int n, m;
vector <int> a[N];
int hmax[N], dp[2][N][20], h[N], pa[N][20];
pair <int, int> d[N][3];

void DFS(int u, int lv, int p) {
  h[u] = hmax[u] = lv;
  d[u][0] = make_pair(hmax[u], u);
  pa[u][0] = p;
  for (int i = 1; i < 20; i++) {
    pa[u][i] = pa[pa[u][i - 1]][i - 1];
  }
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) {
      continue;
    }
    DFS(v, lv + 1, u);
    hmax[u] = max(hmax[u], hmax[v]);
    pair <int, int> foo = make_pair(hmax[v], v);
    for (int i = 0; i < 3; i++) {
      if (foo > d[u][i]) {
        swap(foo, d[u][i]);
      }
    }
  }
}

void Make_LCA() {
  for (int i = 1; i <= n; i++) {
    int p = pa[i][0];
    if (d[p][0].second == i) {
      dp[0][i][0] = d[p][1].first;
      dp[1][i][0] = d[p][1].first - h[p] * 2;
    } else {
      dp[0][i][0] = d[p][0].first;
      dp[1][i][0] = d[p][0].first - h[p] * 2;
    }
  }
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= n; i++) {
      dp[0][i][j] = max(dp[0][i][j - 1], dp[0][pa[i][j - 1]][j - 1]);
      dp[1][i][j] = max(dp[1][i][j - 1], dp[1][pa[i][j - 1]][j - 1]);
    }
  }
}

int Find(int u, int dis) {
  for (int i = 19; i >= 0; i--) {
    if (dis & (1 << i)) {
      u = pa[u][i];
    }
  }
  return u;
}

int LCA(int u, int v) {
  v = Find(v, h[v] - h[u]);
  if (u == v) {
    return u;
  }
  for (int i = 19; i >= 0; i--) {
    if (pa[u][i] != pa[v][i]) {
      u = pa[u][i];
      v = pa[v][i];
    }
  }
  return pa[u][0];
}

int Get(int u, int dis, int flag) {
  int ans = -123456789;
  for (int i = 19; i >= 0; i--) {
    if (dis & (1 << i)) {
      ans = max(ans, dp[flag][u][i]);
      u = pa[u][i];
    }
  }
  return ans;
}

int main() {
  //fi;
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  DFS(1, 0, 0);
  Make_LCA();
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (h[u] > h[v]) {
      swap(u, v);
    }
    int w = LCA(u, v);
    int hu = h[u] - h[w];
    int hv = h[v] - h[w];
    int g = Find(v, (hu + hv - 1) / 2);
    int res = max(hmax[v] - h[v], Get(v, h[v] - h[g], 1) + h[v]);
    res = max(res, Get(w, h[w], 1) + h[u]);
    if (u == w) {
      res = max(res, Get(g, h[g] - h[u], 0) - h[u]);
    } else {
      res = max(res, hmax[u] - h[u]);
      res = max(res, Get(u, h[u] - h[w] - 1, 1) + h[u]);
      res = max(res, Get(g, h[g] - h[w] - 1, 0) + h[u] - h[w] * 2);
      int conu = Find(u, h[u] - h[w] - 1);
      int cong = Find(g, h[g] - h[w] - 1);
      int foo = -1;
      for (int i = 0; i < 3; i++) {
        if (d[w][i].second != conu && d[w][i].second != cong) {
          foo = max(foo, d[w][i].first);
        }
      }
      res = max(res, foo + h[u] - h[w] * 2);
    }
    cout << res << endl;
  }
  return 0;
}