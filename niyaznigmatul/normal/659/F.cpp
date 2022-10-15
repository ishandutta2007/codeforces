#include <bits/stdc++.h>

int const N = 1234;

int a[N][N], ans[N][N], id[N * N], p[N * N], sz[N * N];
int need;

int get(int x) {
  return x == p[x] ? x : (p[x] = get(p[x]));
}

int n, m;

void dfs(int x, int y, int val) {
  if (need == 0) return;
  --need;
  a[x][y] = -1;
  ans[x][y] = val;
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) if (dx * dx + dy * dy == 1) {
      int nx = x + dx;
      int ny = y + dy;
      if (nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] < val) {
        continue;
      }
      dfs(nx, ny, val);
    }
  }
}

int main() {
  long long k;
  scanf("%d%d%lld", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", a[i] + j);
    }
  }
  for (int i = 0; i < n * m; i++) {
    p[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < n * m; i++) id[i] = i;
  std::sort(id, id + n * m, [&](int i, int j) {
    return a[i / m][i % m] < a[j / m][j % m];
  });
  for (int it = n * m - 1; it >= 0; it--) {
    int v = id[it];
    int cx = v / m;
    int cy = v % m;
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) if (dx * dx + dy * dy == 1) {
        int nx = cx + dx;
        int ny = cy + dy;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        int nv = nx * m + ny;
        if (a[nx][ny] >= a[cx][cy]) {
          if (get(v) != get(nv)) {
            sz[get(nv)] += sz[get(v)];
            p[get(v)] = get(nv);
          }
        }
      }
    }
    if (k % a[cx][cy] != 0) {
      continue;
    }
    if (sz[get(v)] >= k / a[cx][cy]) {
      need = (int) (k / a[cx][cy]);
      dfs(cx, cy, a[cx][cy]);
      puts("YES");
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (j > 0) putchar(' ');
          printf("%d", ans[i][j]);
        }
        puts("");
      }
      return 0;
    }
  }  
  puts("NO");
}