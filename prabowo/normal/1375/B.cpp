#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int MOD = 998244353;

int n, m;
int a[N][N];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int d[N][N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      d[i][j] = 0;
      for (int k = 0; k < 4; ++k) {
        int nx = i + dx[k], ny = j + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        ++d[i][j];
      }

      if (d[i][j] < a[i][j]) return 0 * printf("NO\n");
    }
  }

  printf("YES\n");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d ", d[i][j]);
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