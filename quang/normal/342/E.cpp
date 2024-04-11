#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
vector <int> a[N], b, c;
int pos[N], lv[N], d[N], q[N], top;
vector <int> rmq[20];

void dfs(int u, int p) {
  lv[u] = lv[p] + 1;
  if (a[u].size() == 1 && u != 1) {
    b.push_back(u);
    pos[u] = b.size() - 1;
    return;
  }
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) {
      continue;
    }
    dfs(v, u);
    b.push_back(u);
    pos[u] = b.size() - 1;
  }
}

void build() {
  for (int i = 0; i < 20; i++) {
    rmq[i].resize(b.size());
  }
  for (int i = 0; i < b.size(); i++) {
    rmq[0][i] = b[i];
  }
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j <= (int)b.size() - (1 << i); j++) {
      int p1 = rmq[i - 1][j];
      int p2 = rmq[i - 1][j + (1 << (i - 1))];
      if (lv[p1] < lv[p2]) {
        rmq[i][j] = p1;
      } else {
        rmq[i][j] = p2;
      }
    }
  }
}

void refresh() {
  top = 0;
  for (int i = 0; i < c.size(); i++) {
    q[top++] = c[i];
    d[c[i]] = 0;
  }
  for (int i = 0; i < top; i++) {
    int u = q[i];
    for (int i = 0; i < a[u].size(); i++) {
      int v = a[u][i];
      if (d[u] + 1 < d[v]) {
        d[v] = d[u] + 1;
        q[top++] = v;
      }
    }
  }
}

int get(int u, int v) {
  int u1 = pos[u];
  int v1 = pos[v];
  if (u1 > v1) {
    swap(u1, v1);
  }
  int l = log2(v1 - u1 + 1);
  int p1 = rmq[l][u1];
  int p2 = rmq[l][v1 - (1 << l) + 1];
  return lv[u] + lv[v] - min(lv[p1], lv[p2]) * 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  memset(d, 60, sizeof d);
  dfs(1, 0);
  build();
  c.push_back(1);
  while (m--) {
    int type, u;
    cin >> type >> u;
    if (m % 317 == 0) {
      refresh();
      c.clear();
    }
    if (type == 1) {
      c.push_back(u);
    } else {
      int res = d[u];
      for (int i = 0; i < c.size(); i++) {
        res = min(res, get(u, c[i]));
      }
      cout << res << endl;
    }
  }
  return 0;
}