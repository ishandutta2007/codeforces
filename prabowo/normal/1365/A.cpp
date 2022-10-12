#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, m;
int a[N][N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  int row = 0, col = 0;
  for (int i = 0; i < n; ++i) {
    int ok = true;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] > 0) ok = false;
    }

    if (ok) ++row;
  }
  for (int j = 0; j < m; ++j) {
    int ok = true;
    for (int i = 0; i < n; ++i) {
      if (a[i][j] > 0) ok = false;
    }

    if (ok) ++col;
  }

  if (min(row, col) & 1) printf("Ashish\n");
  else printf("Vivek\n");
  return 0;
}


int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}