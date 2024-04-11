#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m;
vector <int> a[N];
long long len, maxlen;
int best = 1e9;
int used[N], d[N], lv[N];
int maxlv[N];

long long dfs(int u, int p) {
  lv[u] = lv[p] + 1;
  long long sum = 0;
  maxlv[u] = 0;
  if (d[u]) {
    maxlv[u] = u;
  }
  for (auto v : a[u]) {
    if (v == p) {
      continue;
    }
    sum += dfs(v, u);
    if (maxlv[u] && maxlv[v]) {
      if (maxlen == lv[maxlv[u]] + lv[maxlv[v]] - 2 * lv[u]) {
        best = min(best, maxlv[u]);
        best = min(best, maxlv[v]);
      }
      if (maxlen < lv[maxlv[u]] + lv[maxlv[v]] - 2 * lv[u]) {
        maxlen = lv[maxlv[u]] + lv[maxlv[v]] - 2 * lv[u];
        best = 1e9;
        best = min(best, maxlv[u]);
        best = min(best, maxlv[v]);
      }
    }
    if (lv[maxlv[u]] == lv[maxlv[v]]) {
      maxlv[u] = min(maxlv[u], maxlv[v]);
    }
    if (lv[maxlv[u]] < lv[maxlv[v]]) {
      maxlv[u] = maxlv[v];
    }
    used[u] |= used[v];
  }
  used[u] |= d[u];
  if (used[u]) {
    return sum + 1;
  }
  return 0;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  int root;
  for (int i = 1; i <= m; i++) {
    int u;
    scanf("%d", &u);
    root = u;
    d[u] = 1;
  }
  if (m == 1) {
    cout << root << endl << 0 << endl;
    return 0;
  }
  len = (dfs(root, 0) - 1) * 2;
  cout << best << endl << len - maxlen << endl;
  return 0;
}