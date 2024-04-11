#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int root[N], f[N];

int getRoot(int u) {
  return root[u] ? root[u] = getRoot(root[u]) : u;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u = getRoot(u);
    v = getRoot(v);
    if (u == v) {
      f[u] = 1;
    } else {
      f[u] |= f[v];
      root[v] = u;
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (!root[i] && !f[i]) {
      res++;
    }
  }
  cout << res << endl;
  return 0;
}