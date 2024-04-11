#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int dirU[] = {0, 1, 0, -1};
const int dirV[] = {1, 0, -1, 0};

int n, m;
long long k;
int a[N][N], used[N][N], res[N][N];
pair<int, pair<int, int> > b[N * N];
int tot;
int root[N * N];
pair<int, int> q[N * N];
int top;

void bfs(int x, int y, int need) {
  used[x][y] = 1;
  top = 1;
  q[0] = make_pair(x, y);
  int lim = a[x][y];
  for (int i = 0; i < top && top < need; i++) {
    int u = q[i].first, v = q[i].second;
    for (int j = 0; j < 4; j++) {
      int nu = dirU[j] + u;
      int nv = dirV[j] + v;
      if (nu < 0 || nu >= n || nv < 0 || nv >= m) {
        continue;
      }
      if (a[nu][nv] < lim || used[nu][nv]) {
        continue;
      }
      used[nu][nv] = 1;
      q[top++] = make_pair(nu, nv);
    }
  }
  for (int i = 0; i < need; i++) {
    int u = q[i].first, v = q[i].second;
    res[u][v] = lim;
  }
  puts("YES");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
}

int getVal(int u, int v) {
  return u * m + v;
}

int getRoot(int u) {
  return root[u] < 0 ? u : root[u] = getRoot(root[u]);
}

void join(int u, int v) {
  u = getRoot(u);
  v = getRoot(v);
  if (u == v) {
    return;
  }
  root[u] += root[v];
  root[v] = u;
}

int main() {
  scanf("%d %d %I64d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      b[++tot] = make_pair(a[i][j], make_pair(i, j));
      root[getVal(i, j)] = -1;
    }
  }
  sort(b + 1, b + tot + 1, greater<pair<int, pair<int, int> > > ());
  for (int i = 1; i <= tot; i++) {
    int u = b[i].second.first, v = b[i].second.second, val = b[i].first;
    for (int j = 0; j < 4; j++) {
      int nu = dirU[j] + u;
      int nv = dirV[j] + v;
      if (nu < 0 || nu >= n || nv < 0 || nv >= m) {
        continue;
      }
      if (used[nu][nv]) {
        join(getVal(u, v), getVal(nu, nv));
      }
    }
    used[u][v] = 1;
    if (k % val) {
      continue;
    }
    int r = getRoot(getVal(u, v));
    long long need = k / val;
    if (-root[r] < need) {
      continue;
    }
    memset(used, 0, sizeof used);
    bfs(u, v, need);
    return 0;
  }
  puts("NO");
  return 0;
}