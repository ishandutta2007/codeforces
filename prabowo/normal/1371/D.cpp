#include <bits/stdc++.h>
using namespace std;

const int N = 303;

int n, k;
int a[N][N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = 0;
    }
  }

  int x = 0, y = 0;
  int col = 0;
  while (k > 0) {
    if (a[x][y] == 0) {
      a[x][y] = 1;
      ++x, ++y;
      --k;
    } else {
      x = 0, y = ++col;
    }

    if (x >= n) x = 0;
    if (y >= n) y = 0;
  }

  int maxiR = 0, miniR = n;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (a[i][j]) ++cnt;
    }
    maxiR = max(maxiR, cnt);
    miniR = min(miniR, cnt);
  }

  int maxiC = 0, miniC = n;
  for (int j = 0; j < n; ++j) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i][j]) ++cnt;
    }
    maxiC = max(maxiC, cnt);
    miniC = min(miniC, cnt);
  }

  printf("%d\n", (maxiR - miniR) * (maxiR - miniR) + (maxiC - miniC) * (maxiC - miniC));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}