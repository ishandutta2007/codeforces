#include <bits/stdc++.h>

using namespace std;

const int N = 2510;

int n, m, k;
char a[N][N];
bool b[2][N][N];
long long res = 0;
int up[20][N], down[20][N];
int rangeup[20], rangedown[20];

int get(int u) {
  if (u <= k) {
    return rangedown[u + 1] - rangedown[u];
  }
  return 0;
}

void go(int u, int d, int l, int r, int dir) {
  if (d - u < r - l) {
    go(l, r, u, d, dir ^ 1);
    return;
  }
  int c = (u + d) >> 1;
  for (int i = l; i <= r; i++) {
    up[0][i] = c;
    int f = 0;
    for (int j = c; j >= u; j--) {
      if (b[dir][j][i]) {
        up[++f][i] = j;
      }
      if (f == k + 1) {
        break;
      }
    }
    for (int j = f + 1; j <= k + 1; j++) {
      up[j][i] = u - 1;
    }

    f = 0;
    down[0][i] = c;
    for (int j = c; j <= d; j++) {
      if (b[dir][j][i]) {
        down[++f][i] = j;
      }
      if (f == k + 1) {
        break;
      }
    }
    for (int j = f + 1; j <= k + 1; j++) {
      down[j][i] = d + 1;
    }
  }

  for (int i = l; i <= r; i++) {
    int num = 0;
    rangeup[0] = rangedown[0] = c;
    for (int j = 1; j <= k + 1; j++) {
      rangeup[j] = u - 1;
      rangedown[j] = d + 1;
    }
    for (int j = i; j <= r; j++) {
      num += b[dir][c][j];
      int fooup[20], foodown[20];
      for (int x = 0; x <= k + 1; x++) {
        fooup[x] = rangeup[x];
        foodown[x] = rangedown[x];
      }
      int cnt = 1, cur1 = 1, cur2 = 1;
      while (cnt <= k + 1) {
        if (fooup[cur1] > up[cur2][j]) {
          rangeup[cnt] = fooup[cur1++];
        } else {
          rangeup[cnt] = up[cur2++][j];
        }
        cnt++;
      }

      cnt = 1, cur1 = 1, cur2 = 1;
      while (cnt <= k + 1) {
        if (foodown[cur1] < down[cur2][j]) {
          rangedown[cnt] = foodown[cur1++];
        } else {
          rangedown[cnt] = down[cur2++][j];
        }
        cnt++;
      }

      for (int x = 0; x <= k; x++) {
        res += 1ll * (rangeup[x] - rangeup[x + 1]) * get(k + num - x);
      }
    }
  }
  if (u < c) {
    go(u, c - 1, l, r, dir);
  }
  if (c < d) {
    go(c + 1, d, l, r, dir);
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      b[0][i][j] = a[i][j] == '1';
      b[1][j][i] = a[i][j] == '1';
    }
  }
  go(1, n, 1, m, 0);
  printf("%I64d", res);
  return 0;
}