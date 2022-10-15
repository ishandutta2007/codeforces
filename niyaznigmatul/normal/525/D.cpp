#include <bits/stdc++.h>

int n, m;

int const N = 2222;

char s[N][N];
int q[N * N];
int was[N][N];

bool isalone(int x, int y) {
  if (x < 0 || y < 0 || x + 1 >= n || y + 1 >= m) return false;
  int cn = 0;
  for (int dx = 0; dx < 2; dx++)
    for (int dy = 0; dy < 2; dy++) if (s[x + dx][y + dy] == '*') ++cn;
  return cn == 1;
}

bool toremove(int x, int y) {
  if (s[x][y] != '*') return false;
  for (int dx = -1; dx <= 0; dx++) {
    for (int dy = -1; dy <= 0; dy++) if (isalone(x + dx, y + dy)) return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int c = getchar();
      while (c <= 32) c = getchar();
      s[i][j] = c;
    }
  }
  int head = 0;
  int tail = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) if (s[i][j] == '*') {
      if (toremove(i, j)) {
        q[tail++] = i * m + j;
        was[i][j] = true;
      }
    }
  }
  while (head < tail) {
    int v = q[head++];
    int cx = v / m;
    int cy = v % m;
    s[cx][cy] = '.';
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        int nx = cx + dx;
        int ny = cy + dy;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || was[nx][ny] || !toremove(nx, ny)) continue;
        was[nx][ny] = true;
        q[tail++] = nx * m + ny;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) putchar(s[i][j]);
    puts("");
  }
}