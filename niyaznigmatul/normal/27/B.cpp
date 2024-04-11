#include <cstdio>

int const N = 123;

int q[N], has[N][N], deg[N];
int n;

bool check() {
  int head = 0;
  int tail = 0;
  for (int i = 0; i < n; i++) deg[i] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) if (has[i][j]) deg[j]++;
  for (int i = 0; i < n; i++) if (deg[i] == 0) q[tail++] = i;
  while (head < tail) {
    int v = q[head++];
    for (int i = 0; i < n; i++) {
      if (has[v][i]) {
        --deg[i];
        if (deg[i] == 0) q[tail++] = i;
      }
    }
  }
  return head == n;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n * (n - 1) / 2 - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    --y;
    has[x][y] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!has[i][j] && !has[j][i]) {
        has[i][j] = true;
        if (check()) {
          printf("%d %d\n", i + 1, j + 1);
          return 0;
        }
        has[i][j] = false;
        has[j][i] = true;
        if (check()) {
          printf("%d %d\n", j + 1, i + 1);
          return 0;
        }
        has[j][i] = false;
      }
    }
  }
}