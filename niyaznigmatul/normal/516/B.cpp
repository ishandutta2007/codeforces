#include <bits/stdc++.h>

int const N = 2222;

int deg[N][N];
char s[N][N];
int q[N * N];
int n, m;
int DX[] = {1, 0, -1, 0};
int DY[] = {0, 1, 0, -1};

void mark(int x1, int y1, int x2, int y2) {
  if (x1 == x2) {
    if (y1 > y2) std::swap(y1, y2);
    s[x1][y1] = '<';
    s[x2][y2] = '>';
  } else {
    if (x1 > x2) std::swap(x1, x2);
    s[x1][y1] = '^';
    s[x2][y2] = 'v';
  }
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
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*') continue;
      for (int dir = 0; dir < 4; dir++) {
        int x = i + DX[dir];
        int y = j + DY[dir];
        if (x < 0 || y < 0 || x >= n || y >= m || s[x][y] == '*') continue;
        deg[i][j]++;
      }
    }
  }
  int head = 0;
  int tail = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (deg[i][j] == 1) {
        q[tail++] = i * m + j;
      }
    }
  }
  while (head < tail) {
    int v = q[head++];
    int cx = v / m;
    int cy = v % m;
    if (s[cx][cy] != '.') continue;
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + DX[dir];
      int ny = cy + DY[dir];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] != '.') continue;
      mark(cx, cy, nx, ny);
      for (int dd = 0; dd < 4; dd++) {
        int x = nx + DX[dd];
        int y = ny + DY[dd];
        if (x < 0 || y < 0 || x >= n || y >= m || s[x][y] == '.') {
          deg[x][y]--;
          if (deg[x][y] == 1) {
            q[tail++] = x * m + y;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) if (s[i][j] == '.') {
      puts("Not unique");
      return 0;
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      putchar(s[i][j]);
    }
    puts("");
  }
}