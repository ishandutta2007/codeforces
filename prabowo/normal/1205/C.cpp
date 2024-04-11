#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n;
int grid[N][N];

int ask(int x, int y, int xx, int yy) {
  if (x > xx) swap(x, xx);
  if (y > yy) swap(y, yy);
  printf("? %d %d %d %d\n", x+1, y+1, xx+1, yy+1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

int dx[6] = {-2, 0, 1, 2, -1, 0};
int dy[6] = {0, 2, 1, 0, -1, -2};
void bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});
  
  while (q.size()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();
    
    for (int i = 0; i < 6; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (grid[nx][ny] != -1) continue;
      
      grid[nx][ny] = ask(x, y, nx, ny) ^ grid[x][y] ^ 1;
      q.push({nx, ny});
    }
  }
}

void answer() {
  printf("!\n");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d", grid[i][j]);
    }
    printf("\n");
  }
  fflush(stdout);
  exit(0);
}

int main() {
  scanf("%d", &n);
  memset(grid, -1, sizeof grid);
  grid[0][0] = 1;
  grid[n-1][n-1] = 0;
  
  bfs(0, 0);
  
  // row
  for (int i = 2; i < n-1; ++i) {
    if ((grid[i-2][0] == grid[i][0]) != (grid[i][0] == grid[i+2][0])) {
      if (ask(i-1, 0, i+1, 0)) {
        if (grid[i-2][0] == grid[i][0]) {
          if (ask(i-2, 0, i+1, 0)) {
            grid[i-1][0] = grid[i+1][0] = grid[i][0];
          } else {
            grid[i-1][0] = grid[i+1][0] = grid[i][0] ^ 1;
          }
        } else {
          if (ask(i-1, 0, i+2, 0)) {
            grid[i-1][0] = grid[i+1][0] = grid[i][0];
          } else {
            grid[i-1][0] = grid[i+1][0] = grid[i][0] ^ 1;
          }
        }
      } else {
        if (grid[i-2][0] != grid[i][0]) {
          if (ask(i-2, 0, i+1, 0)) {
            grid[i-1][0] = grid[i][0];
            grid[i+1][0] = grid[i-2][0];
          } else {
            grid[i-1][0] = grid[i][0] ^ 1;
            grid[i+1][0] = grid[i-2][0] ^ 1;
          }
        } else {
          if (ask(i-1, 0, i+2, 0)) {
            grid[i-1][0] = grid[i+2][0];
            grid[i+1][0] = grid[i][0];
          } else {
            grid[i-1][0] = grid[i+2][0] ^ 1;
            grid[i+1][0] = grid[i][0] ^ 1;
          }
        }
      }
      
      bfs(i-1, 0);
      answer();
    }
  }

  // col
  for (int j = 2; j < n-1; ++j) {
    if ((grid[n-1][j-2] == grid[n-1][j]) != (grid[n-1][j] == grid[n-1][j+2])) {
      if (ask(n-1, j-1, n-1, j+1)) {
        if (grid[n-1][j-2] == grid[n-1][j]) {
          if (ask(n-1, j-2, n-1, j+1)) {
            grid[n-1][j-1] = grid[n-1][j+1] = grid[n-1][j];
          } else {
            grid[n-1][j-1] = grid[n-1][j+1] = grid[n-1][j] ^ 1;
          }
        } else {
          if (ask(n-1, j-1, n-1, j+2)) {
            grid[n-1][j-1] = grid[n-1][j+1] = grid[n-1][j];
          } else {
            grid[n-1][j-1] = grid[n-1][j+1] = grid[n-1][j] ^ 1;
          }
        }
      } else {
        if (grid[n-1][j-2] != grid[n-1][j]) {
          if (ask(n-1, j-2, n-1, j+1)) {
            grid[n-1][j-1] = grid[n-1][j];
            grid[n-1][j+1] = grid[n-1][j-2];
          } else {
            grid[n-1][j-1] = grid[n-1][j] ^ 1;
            grid[n-1][j+1] = grid[n-1][j-2] ^ 1;
          }
        } else {
          if (ask(n-1, j-1, n-1, j+2)) {
            grid[n-1][j-1] = grid[n-1][j+2];
            grid[n-1][j+1] = grid[n-1][j];
          } else {
            grid[n-1][j-1] = grid[n-1][j+2] ^ 1;
            grid[n-1][j+1] = grid[n-1][j] ^ 1;
          }
        }
      }
      
      bfs(n-1, j-1);
      answer();
    }
  }
  
  if (ask(n-2, 0, n-1, 1)) {
    if (grid[n-1][0] == grid[n-3][0]) {
      if (ask(n-3, 0, n-1, 1)) {
        grid[n-2][0] = grid[n-1][1] = grid[n-1][0];
      } else {
        grid[n-2][0] = grid[n-1][1] = grid[n-1][0] ^ 1;
      }
    } else {
      if (ask(n-2, 0, n-1, 2)) {
        grid[n-2][0] = grid[n-1][1] = grid[n-1][0];
      } else {
        grid[n-2][0] = grid[n-1][1] = grid[n-1][0] ^ 1;
      }
    }
  } else {
    if (grid[n-3][0] != grid[n-1][0]) {
      if (ask(n-3, 0, n-1, 1)) {
        grid[n-2][0] = grid[n-1][0];
        grid[n-1][1] = grid[n-3][0];
      } else {
        grid[n-2][0] = grid[n-1][0] ^ 1;
        grid[n-1][1] = grid[n-3][0] ^ 1;
      }
    } else {
      if (ask(n-2, 0, n-1, 2)) {
        grid[n-2][0] = grid[n-1][2];
        grid[n-1][1] = grid[n-1][0];
      } else {
        grid[n-2][0] = grid[n-1][2] ^ 1;
        grid[n-1][1] = grid[n-1][0] ^ 1;
      }
    }
  }
  
  bfs(n-2, 0);
  answer();
  return 0;
}