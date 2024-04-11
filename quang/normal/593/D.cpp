#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m;
vector <pair<pair<int, int> , long long> > a[N];
long long b[N];
int in[N], out[N], cnt, f[N];
int pos[N];

void dfs(int u, int p) {
  f[u] = p;
  in[u] = ++cnt;
  for (auto x : a[u]) {
    int v = x.first.first;
    int id = x.first.second;
    long long len = x.second;
    if (v == p) {
      continue;
    }
    b[v] = len;
    pos[id] = v;
    dfs(v, u);
  }
  out[u] = cnt;
}

int next(int u) {
  if (b[u] == 1) {
    return f[u] = next(f[u]);
  }
  return u;
}

void go(int x, int y, long long &val) {
  if (x == 0 || val == 0) {
    return;
  }
  if (in[x] <= in[y] && out[y] <= out[x]) {
    return;
  }
  val /= b[x];
  go(f[x] = next(f[x]), y, val);
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; i++) {
    int u, v;
    long long w;
    scanf("%d %d %I64d", &u, &v, &w);
    a[u].push_back(make_pair(make_pair(v, i), w));
    a[v].push_back(make_pair(make_pair(u, i), w));
  }
  b[0] = 1e9;
  in[0] = 0;
  out[0] = n + 1;
  dfs(1, 0);
  while (m--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x, y;
      long long val;
      scanf("%d %d %I64d", &x, &y, &val);
      go(x, y, val);
      go(y, x, val);
      printf("%I64d\n", val);
    } else {
      int p;
      long long c;
      scanf("%d %I64d", &p, &c);
      b[pos[p]] = c;
    }
  }
  return 0;
}