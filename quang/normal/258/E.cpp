#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, m, cnt;
int in[N], out[N], res[N];
vector <int> a[N], b[N];
int t[N * 4], p[N * 4];

void dfs(int u, int p) {
  in[u] = ++cnt;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v != p) {
      dfs(v, u);
    }
  }
  out[u] = cnt;
}

void setup(int node, int l, int r) {
  if (p[node]) {
   t[node] = r - l + 1;
  } else {
    if (l == r) {
      t[node] = 0;
    } else {
      t[node] = t[node * 2] + t[node * 2 + 1];
    }
  }
}

void add(int node, int l, int r, int x, int y, int val) {
  if (x > r || y < l) {
    return;
  }
  if (x <= l && r <= y) {
    p[node] += val;
    setup(node, l, r);
    return;
  }
  int m = (l + r) >> 1;
  add(node * 2, l, m, x, y, val);
  add(node * 2 + 1, m + 1, r, x, y, val);
  setup(node, l, r);
}

void redfs(int u, int p) {
  for (int i = 0; i < b[u].size(); i++) {
    int v = b[u][i];
    add(1, 1, n, in[v], out[v], 1);
  }
  res[u] = max(0, t[1] - 1);
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v != p) {
      redfs(v, u);
    }
  }
  for (int i = 0; i < b[u].size(); i++) {
    int v = b[u][i];
    add(1, 1, n, in[v], out[v], -1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (in[u] > in[v]) {
      swap(u, v);
    }
    if (out[u] >= out[v]) {
      b[u].push_back(u);
    } else {
      b[u].push_back(u);
      b[u].push_back(v);
      b[v].push_back(u);
      b[v].push_back(v);
    }
  }
  redfs(1, 0);
  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
  return 0;
}