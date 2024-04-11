#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
int a[N][N];
char res[N];

void go(int u, int sign) {
  res[u] = (sign ? 'a' : 'c');
  for (int i = 1; i <= n; i++) {
    if (res[i]) {
      continue;
    }
    if (a[u][i]) {
      go(i, sign);
    } else {
      go(i, sign ^ 1);
    }
  }
}

void check() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        continue;
      }
      int edge = abs((int)res[i] - res[j]) <= 1;
      if (edge != a[i][j]) {
        puts("No");
        exit(0);
      }
    }
  }
}

int main() {
  scanf("%d  %d", &n, &m);
  for (int i =1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u][v] = a[v][u] = 1;
  }
  for (int i = 1; i <= n; i++) {
    int f = 0;
    for (int j = 1; j <= n; j++) {
      if (j == i || !a[i][j]) {
        continue;
      }
      for (int k = 1; k <= n; k++) {
        if (k == j || k == i || !a[i][k]) {
          continue;
        }
        if (!a[j][k]) {
          f = 1;
          break;
        }
      }
    }
    if (f) {
      res[i] = 'b';
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!res[i]) {
      go(i, 0);
    }
  }
  check();
  puts("Yes");
  printf("%s", res + 1);
  return 0;
}