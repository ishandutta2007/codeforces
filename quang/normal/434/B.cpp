#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N];
int u[N][N], d[N][N], l[N][N], r[N][N];
int b[N], st[N], top;
int L[N], R[N];

int get(int u, int n) {
  st[0] = 0;
  top = 1;
  L[0] = 0;
  R[n + 1] = n + 1;
  for (int i = 1; i <= n + 1; i++) {
    while (top && b[i] < b[st[top - 1]]) {
      R[st[top - 1]] = i;
      top--;
    }
    if (top && b[i] == b[st[top - 1]]) {
      L[i] = L[st[top - 1]];
    } else {
      L[i] = st[top - 1];
    }
    st[top++] = i;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (!b[i]) {
      continue;
    }
    if (L[i] < u && R[i] > u) {
      res = max(res, b[i] * (R[i] - L[i] - 1));
    }
  }
  return res;
}

int main() {
  //ios_base::sync_with_stdio(0);
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        u[i][j] = u[i - 1][j] + 1;
        l[i][j] = l[i][j - 1] + 1;
      }
    }
  }
  for (int i = n; i; i--) {
    for (int j = m; j; j--) {
      if (a[i][j]) {
        d[i][j] = d[i + 1][j] + 1;
        r[i][j] = r[i][j + 1] + 1;
      }
    }
  }
  while (q--) {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);
    if (op == 1) {
      a[x][y] ^= 1;
      for (int i = 1; i <= n; i++) {
        if (a[i][y]) {
          u[i][y] = u[i - 1][y] + 1;
        } else {
          u[i][y] = 0;
        }
      }
      for (int i = n; i; i--) {
        if (a[i][y]) {
          d[i][y] = d[i + 1][y] + 1;
        } else {
          d[i][y] = 0;
        }
      }
      for (int i = 1; i <= m; i++) {
        if (a[x][i]) {
          l[x][i] = l[x][i - 1] + 1;
        } else {
          l[x][i] = 0;
        }
      }
      for (int i = m; i; i--) {
        if (a[x][i]) {
          r[x][i] = r[x][i + 1] + 1;
        } else {
          r[x][i] = 0;
        }
      }
    } else {
      int res = 0;
      if (!a[x][y]) {
        printf("%d\n", res);
        continue;
      }
      for (int i = 0; i <= m + 1; i++) {
        b[i] = u[x][i];
      }
      res = max(res, get(y, m));
      for (int i = 0; i <= m + 1; i++) {
        b[i] = d[x][i];
      }
      res = max(res, get(y, m));
      for (int i = 0; i <= n + 1; i++) {
        b[i] = l[i][y];
      }
      res = max(res, get(x, n));
      for (int i = 0; i <= n + 1; i++) {
        b[i] = r[i][y];
      }
      res = max(res, get(x, n));
      printf("%d\n", res);
    }
  }
  return 0;
}