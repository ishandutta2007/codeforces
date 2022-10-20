#include <bits/stdc++.h>

using namespace std;

const int N = 1510;

struct point {
  int x, y, id;
};

int n, res[N];
point root;
vector <int> a[N];
int cnt[N];
point b[N];

void dfs(int u, int p) {
  cnt[u] = 1;
  for (int v : a[u]) {
    if (v== p) {
      continue;
    }
    dfs(v, u);
    cnt[u] += cnt[v];
  }
}

bool cmp(point u, point v) {
  int x1 = u.x - root.x;
  int y1 = u.y - root.y;
  int x2 = v.x - u.x;
  int y2 = v.y - u.y;
  return 1ll * x1 * y2 - 1ll * x2 * y1 < 0;
}

void go(int u, int p, int l, int r) {
  if (l == r) {
    res[b[l].id] = u;
    return;
  }
  int pos = l;
  for (int i = l + 1; i <= r; i++) {
    if (b[pos].x > b[i].x || (b[pos].x == b[i].x && b[pos].y > b[i].y)) {
      pos = i;
    }
  }
  swap(b[pos], b[l]);
  res[b[l].id] = u;
  root = b[l];
  sort(b + l + 1, b + r + 1, cmp);
  int cur = l;
  for (int v : a[u]) {
    if (p == v) {
      continue;
    }
    go(v, u, cur + 1, cur + cnt[v]);
    cur += cnt[v];
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &b[i].x, &b[i].y);
    b[i].id = i;
  }
  dfs(1, 0);
  go(1, 0, 1, n);
  for (int i = 1; i <= n; i++) {
    printf("%d ", res[i]);
  }
  return 0;
}