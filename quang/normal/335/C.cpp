#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int r, n;
int f[N][3];
int mem[N][N][3][3];

int go(int l, int r, int m1, int m2) {
  if (mem[l][r][m1][m2] != -1) {
    return mem[l][r][m1][m2];
  }
  if (l > r) {
    return 0;
  }
  set<int> s;
  for (int i = l; i <= r; i++) {
    if (f[i][1] || f[i][2]) {
      continue;
    }
    for (int j = 1; j <= 2; j++) {
      if (i == l && j != m1 && m1) {
        continue;
      }
      if (i == r && j != m2 && m2) {
        continue;
      }
      if (i > l && f[i - 1][3 - j]) {
        continue;
      }
      if (i < r && f[i + 1][3 - j]) {
        continue;
      }
      s.insert(go(l, i - 1, m1, j) ^ go(i + 1, r, j, m2));
    }
  }
  int pos = 0;
  while (s.count(pos)) {
    pos++;
  }
  return mem[l][r][m1][m2] = pos;
}

int main() {
  memset(mem, -1, sizeof mem);
  scanf("%d %d", &r, &n);
  for (int i = 1; i <= n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    f[u][v] = 1;
  }
  printf("%s", go(1, r, 0, 0) ? "WIN" : "LOSE");
  return 0;
}