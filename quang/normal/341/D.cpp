#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;

struct bit {
  int t[N][N];

  void add(int x, int y, int val) {
    while (x <= n) {
      int yy = y;
      while (yy <= n) {
        t[x][yy] ^= val;
        yy += (yy & -yy);
      }
      x += (x & -x);
    }
  }

  int get(int x, int y) {
    int res = 0;
    while (x) {
      int yy = y;
      while (yy) {
        res ^= t[x][yy];
        yy -= (yy & -yy);
      }
      x -= (x & -x);
    }
    return res;
  }
} t[2][2];

int get(int x, int y) {
  int xx = x & 1;
  int yy = y & 1;
  return t[xx][yy].get(x, y);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int op, x, y, X, Y, v;
    scanf("%d %d %d %d %d", &op, &x, &y, &X, &Y);
    if (op == 1) {
      int res = get(X, Y) ^ get(X, y - 1) ^ get(x - 1, Y) ^ get(x - 1, y - 1);
      printf("%d\n", res);
    } else {
      scanf("%d", &v);
      int xx = (X - x + 1) & 1;
      int yy = (Y - y + 1) & 1;
      int xxx = x & 1;
      int yyy = y & 1;
      if (xx && yy) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            t[i][j].add(X + 1, Y + 1, v);
          }
        }
      }
      if (xx) {
        for (int i = 0; i < 2; i++) {
          t[i][yyy].add(X + 1, y, v);
          t[i][yyy].add(X + 1, Y + 1, v);
        }
      }
      if (yy) {
        for (int i = 0; i < 2; i++) {
          t[xxx][i].add(x, Y + 1, v);
          t[xxx][i].add(X + 1, Y + 1, v);
        }
      }
      t[xxx][yyy].add(x, y, v);
      t[xxx][yyy].add(x, Y + 1, v);
      t[xxx][yyy].add(X + 1, y, v);
      t[xxx][yyy].add(X + 1, Y + 1, v);
    }
  }
  return 0;
}