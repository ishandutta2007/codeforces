#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m, q;
int c[N];
vector <int> a[N], b[N];
vector <int> res;
vector <int> dp[17][N];
int anc[17][N], lv[N];

void getmin(vector <int> &a, const vector <int>&b, const vector <int> &c) {
  int k = min(10, (int)(b.size() + c.size()));
  a.resize(k);
  int curb = 0, curc = 0;
  for (int i = 0; i < k; i++) {
    if (curb >= (int)b.size()) {
      a[i] = c[curc++];
      continue;
    }
    if (curc >= (int)c.size()) {
      a[i] = b[curb++];
      continue;
    }
    if (b[curb] <= c[curc]) {
      a[i] = b[curb++];
    } else {
      a[i] = c[curc++];
    }
  }
}

void dfs(int u, int p) {
  lv[u] = lv[p] + 1;
  anc[0][u] = p;
  dp[0][u] = b[p];
  for (int i = 1; i < 17; i++) {
    anc[i][u] = anc[i - 1][anc[i - 1][u]];
    getmin(dp[i][u], dp[i - 1][u], dp[i - 1][anc[i - 1][u]]);
  }
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
  }
}

int lca(int u, int v) {
  int h = lv[v] - lv[u];
  for (int i = 16; i >= 0; i--) {
    if (h & (1 << i)) {
      v = anc[i][v];
    }
  }
  if (v == u) {
    return u;
  }
  for (int i = 16; i >= 0; i--) {
    if (anc[i][u] != anc[i][v]) {
      u = anc[i][u];
      v = anc[i][v];
    }
  }
  return anc[0][u];
}

int get(vector <int> &ans, int u, int h) {
  vector <int> foo;
  for (int i = 17; i >= 0; i--) {
    if (h & (1 << i)) {
      foo = ans;
      getmin(ans, foo, dp[i][u]);
      u = anc[i][u];
    }
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for (int i = 1; i <= m; i++) {
    int u;
    scanf("%d", &u);
    b[u].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    sort(b[i].begin(), b[i].end());
    while ((int)b[i].size() > 10) {
      b[i].pop_back();
    }
  }
  dfs(1, 0);
  while (q--) {
    int u, v, a;
    scanf("%d %d %d", &u, &v, &a);
    if (lv[u] > lv[v]) {
      swap(u, v);
    }
    int w = lca(u, v);
    res.clear();
    vector <int> foo;
    if (u != v) {
      foo = res;
      getmin(res, foo, b[u]);
      foo = res;
      getmin(res, foo, b[v]);
      if (w != u) {
        get(res, u, lv[u] - lv[w] - 1);
      }
      if (w != v) {
        get(res, v, lv[v] - lv[w] - 1);
      }
      if (w != u && w != v) {
        foo = res;
        getmin(res, foo, b[w]);
      }
    } else {
      getmin(res, foo, b[u]);
    }
    int k = min(a, (int) res.size());
    printf("%d ", k);
    for (int i = 0; i < k; i++) {
      printf("%d ", res[i]);
    }
    printf("\n");
  }
  return 0;
}