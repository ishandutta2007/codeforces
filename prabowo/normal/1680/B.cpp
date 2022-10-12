#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, m;
char s[N][N];

int solve() {
  scanf("%d %d", &n, &m);

  int minX = n, minY = m;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'R') {
        minX = min(minX, i);
        minY = min(minY, j);
      }
    }
  }

  if (s[minX][minY] == 'R') printf("YES\n");
  else printf("NO\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}