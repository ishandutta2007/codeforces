#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct node {
  int u, v, c, used;

  node(int _u = 0, int _v = 0, int _c = 0) {
    u = _u;
    v = _v;
    c = _c;
    used = 0;
  }
};

struct dsu {
  int root[1010];

  dsu() {
    for (int i = 1; i <= 1000; i++) {
      root[i] = i;
    }
  }

  int groot(int x) {
    return root[x] == x ? x : root[x] = groot(root[x]);
  }

  bool connect(int u, int v) {
    int p1 = groot(u), p2 = groot(v);
    if (p1 == p2) {
      return 0;
    }
    root[p1] = p2;
    return 1;
  }
} S, M;

int n, m, need;
node a[N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].u >> a[i].v;
    char c;
    cin >> c;
    a[i].c = (c == 'S');
    if (a[i].c) {
      S.connect(a[i].u, a[i].v);
    }
  }
  if (n % 2 == 0) {
    cout << -1;
    return 0;
  }
  int cnt = 0;
  need = (n - 1) / 2;
  for (int i = 1; i <= m; i++) {
    if (!a[i].c) {
      if (S.connect(a[i].u, a[i].v)) {
        a[i].used = 1;
        cnt++;
      }
    }
  }
  if (cnt > need) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    if (a[i].used == 1) {
      M.connect(a[i].u, a[i].v);
    }
  }
  for (int i = 1; i <= m && cnt < need; i++) {
    if (!a[i].used && !a[i].c) {
      if (M.connect(a[i].u, a[i].v)) {
        a[i].used = 1;
        cnt++;
      }
    }
  }
  if (cnt != need) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= m && cnt < n - 1; i++) {
    if (a[i].c) {
      if (M.connect(a[i].u, a[i].v)) {
        a[i].used = 1;
        cnt++;
      }
    }
  }
  cout << n - 1 << endl;
  for (int i = 1; i <= m; i++) {
    if (a[i].used) {
      cout << i << " ";
    }
  }
  return 0;
}