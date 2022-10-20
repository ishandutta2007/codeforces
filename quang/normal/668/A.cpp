#include <bits/stdc++.h>

using namespace std;

const int N = 110, M = 100010;

int  n, m;
int a[N][N];
int t[M], r[M], c[M], x[M];
int q;

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d", t + i);
    if (t[i] <= 2) {
      scanf("%d", x + i);
    } else {
      scanf("%d %d %d", r + i, c + i, x + i);
    }
  }
  for (int i = q; i; i--) {
    if (t[i] == 1) {
      int old = a[x[i]][m];
      for (int j = m; j > 1; j--) {
        a[x[i]][j] = a[x[i]][j - 1];
      }
      a[x[i]][1] = old;
    }
    if (t[i] == 2) {
      int old = a[n][x[i]];
      for (int j = n; j > 1; j--) {
        a[j][x[i]] = a[j - 1][x[i]];
      }
      a[1][x[i]] = old;
    }
    if (t[i] == 3) {
      a[r[i]][c[i]] = x[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}