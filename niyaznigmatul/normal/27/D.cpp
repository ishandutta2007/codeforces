#include <cstdio>
#include <algorithm>

int const N = 333;

int a[N], b[N], has[N][N], color[N], q[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", a + i, b + i);
    --a[i];
    --b[i];
  }
  for (int i = 0; i < m; i++) {
    int x = a[i];
    int y = b[i];
    if (x > y) std::swap(x, y);
    for (int j = i + 1; j < m; j++) {
      if (x == a[j] || x == b[j] || y == a[j] || y == b[j]) continue;
      if ((a[j] > x && a[j] < y) != (b[j] > x && b[j] < y)) {
        has[i][j] = has[j][i] = true;
      } 
    }
  }
  std::fill(color, color + m, -1);
  for (int start = 0; start < m; start++) {
    if (color[start] >= 0) continue;
    color[start] = 0;
    int head = 0;
    int tail = 0;
    q[tail++] = start;
    while (head < tail) {
      int v = q[head++];
      for (int i = 0; i < m; i++) {
        if (!has[v][i]) continue;
        if (color[i] >= 0) {
          if (color[i] != (color[v] ^ 1)) {
            puts("Impossible");
            return 0;
          }
        } else {
          color[i] = color[v] ^ 1;
          q[tail++] = i;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) putchar("io"[color[i]]);
  puts("");
}