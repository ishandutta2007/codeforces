#include <bits/stdc++.h>

using namespace std;

const int N = 33, SZ = 155;

const int X[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int Y[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool used[8][N][SZ * 2][SZ * 2];
int t[N];

inline int qplus(int u, int v) {
  u += v;
  if (u >= 8) {
    u -= 8;
  }
  return u;
}

inline int qsub(int u, int v) {
  u -= v;
  if (u < 0) {
    u += 8;
  }
  return u;
}

pair<int, int> nxt[8][SZ * 2][SZ * 2];
bool ok[SZ * 2][SZ * 2];

pair<int, int> getNxt(int u, int v, int dir) {
  pair<int, int> foo = nxt[dir][u][v];
  if (ok[foo.first][foo.second]) {
    return nxt[dir][u][v] = getNxt(foo.first, foo.second, dir);
  } else {
    return foo;
  }
}

void add(int x, int y, int u, int dir) {
  int xx = x, yy = y;
  while (1) {
    pair<int, int> foo = getNxt(x, y, dir);
    if (abs(foo.first - xx) > u || abs(foo.second - yy) > u) {
      break;
    }
    x = foo.first;
    y = foo.second;
    ok[x][y] = 1;
  }
}


int n;
void go(int u, int v, int dir, int cur) {
  if (cur > n) {
    return;
  }
  if (used[dir][cur][u][v] == 0) {
    used[dir][cur][u][v] = 1;
  } else {
    return;
  }
  add(u, v, t[cur], dir);
  go(u + t[cur] * X[dir], v + t[cur] * Y[dir], qsub(dir, 1), cur + 1);
  go(u + t[cur] * X[dir], v + t[cur] * Y[dir], qplus(dir, 1), cur + 1);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", t + i);
  }
  for (int i = 0; i < SZ * 2; i++) {
    for (int j = 0; j < SZ * 2; j++) {
      for (int k = 0; k < 8; k++) {
        nxt[k][i][j] = make_pair(i + X[k], j + Y[k]);
      }
    }
  }
  go(SZ, SZ, 0, 1);
  int res = 0;
  for (int i = 0; i < SZ * 2; i++) {
    for (int j = 0; j < SZ * 2; j++) {
      res += ok[i][j];
    }
  }
  cout << res << endl;
  return 0;
}