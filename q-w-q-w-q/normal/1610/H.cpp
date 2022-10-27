#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 300005;
int n, m;
int l[N], r[N], cnt;
int d[N], up[N];
int f[N], g[N];
int a[N], b[N], tot;
vector<int> to[N];

void predfs(int i) {
  l[i] = ++cnt;
  for (int j : to[i])
    d[j] = d[i] + 1, predfs(j);
  r[i] = cnt;
}

void dfs(int i) {
  int cnt = 0;
  for (int j : to[i]) {
    dfs(j);
    if (f[j])
      cnt++, g[i] = g[j];
    f[i] += f[j];
  }

  if (cnt == 0)
    for (int j : to[i])
      g[i] = max(g[i], g[j]);
  if (cnt >= 2)
    g[i] = 0;

  if (g[i] == d[i])
    f[i]++, g[i] = 0;
  g[i] = max(g[i], up[i]);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    to[x].push_back(i);
  }

  d[1] = 1, predfs(1);

  while (m--) {
    int x, y;
    cin >> x >> y;
    if (l[x] > l[y])
      swap(x, y);
    if (r[x] >= l[y]) {
      if (d[y] == d[x] + 1) {
        cout << -1;
        return 0;
      }
      up[y] = max(up[y], d[x] + 1);
    } else {
      tot++;
      a[tot] = x, b[tot] = y;
    }
  }

  dfs(1);

  while (tot) {
    if (f[a[tot]] + f[b[tot]] == f[1]) {
      cout << f[1] + 1;
      return 0;
    }
    tot--;
  }

  cout << f[1];
}