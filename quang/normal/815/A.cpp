#include <bits/stdc++.h>

using namespace std;

const int N = 110;

vector <int> row, col;
int n ,m;
int a[N][N], b[N][N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", a[i] + j);
      b[i][j] = a[i][j];
    }
  }
  int sw = 0;
  if (n > m) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        a[j][i] = b[i][j];
      }
    }
    swap(n, m);
    sw = 1;
  }
  for (int i = 1; i <= n; i++) {
    int mn = 1e9;
    for (int j = 1; j <= m; j++) {
      mn = min(mn, a[i][j]);
    }
    for (int j = 1; j <= m; j++) {
      a[i][j] -= mn;
    }
    for (int j = 1; j <= mn; j++) {
      row.push_back(i);
    }
  }
  for (int j = 1; j <= m; j++) {
    int mn = 1e9;
    for (int i = 1; i <= n; i++) {
      mn = min(mn, a[i][j]);
    }
    for (int i = 1; i <= n; i++) {
      a[i][j] -= mn;
    }
    for (int i = 1; i <= mn; i++) {
      col.push_back(j);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        puts("-1");
        return 0;
      }
    }
  }
  cout << row.size() + col.size() << endl;
  for (int u : row) {
    if (sw) {
      printf("col %d\n", u);
    } else {
      printf("row %d\n", u);
    }
  }
  for (int u : col) {
    if (!sw) {
      printf("col %d\n", u);
    } else {
      printf("row %d\n", u);
    }
  }
  return 0;
}