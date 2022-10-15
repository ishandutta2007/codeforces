#include <cstdio>

const int N = 42;

int a[N][N], b[N][N], c[N][N][N][N];

int sum(int x1, int y1, int x2, int y2) {
  int ret = b[x2][y2];
  if (x1 > 0) ret -= b[x1 - 1][y2];
  if (y1 > 0) ret -= b[x2][y1 - 1];
  if (x1 > 0 && y1 > 0) ret += b[x1 - 1][y1 - 1];
  return ret;
}

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int c = getchar();
      while (c != '1' && c != '0') c = getchar();
      b[i][j] = a[i][j] = c - '0';
    }
  }
  for (int i = 1; i < n; i++)
    for (int j = 0; j < m; j++) b[i][j] += b[i - 1][j];
  for (int i = 0; i < n; i++)
    for (int j = 1; j < m; j++) b[i][j] += b[i][j - 1];
  for (int i1 = 0; i1 < n; i1++) {
    for (int i2 = i1; i2 < n; i2++) {
      for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = j1; j2 < m; j2++) {
          if (sum(i1, j1, i2, j2) == 0) {
            c[i1][j1][i2][j2]++;
          }
        }
      }
    }
  }
  for (int i1 = n - 2; i1 >= 0; i1--) {
    for (int i2 = 0; i2 < n; i2++) {
      for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
          c[i1][j1][i2][j2] += c[i1 + 1][j1][i2][j2];
        }
      }
    }
  }
  for (int i1 = n - 1; i1 >= 0; i1--) {
    for (int i2 = 0; i2 < n; i2++) {
      for (int j1 = m - 2; j1 >= 0; j1--) {
        for (int j2 = 0; j2 < m; j2++) {
          c[i1][j1][i2][j2] += c[i1][j1 + 1][i2][j2];
        }
      }
    }
  }
  for (int i1 = n - 1; i1 >= 0; i1--) {
    for (int i2 = 1; i2 < n; i2++) {
      for (int j1 = m - 1; j1 >= 0; j1--) {
        for (int j2 = 0; j2 < m; j2++) {
          c[i1][j1][i2][j2] += c[i1][j1][i2 - 1][j2];
        }
      }
    }
  }
  for (int i1 = n - 1; i1 >= 0; i1--) {
    for (int i2 = 0; i2 < n; i2++) {
      for (int j1 = m - 1; j1 >= 0; j1--) {
        for (int j2 = 1; j2 < m; j2++) {
          c[i1][j1][i2][j2] += c[i1][j1][i2][j2 - 1];
        }
      }
    }
  }
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    --x1;
    --y1;
    --x2;
    --y2;
    printf("%d\n", c[x1][y1][x2][y2]);
  }
}