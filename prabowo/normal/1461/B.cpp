#include <bits/stdc++.h>
using namespace std;
 
const int N = 505;
 
int n, m;
char s[N][N];

bool sp[N][N], nsp[N][N];

int solve() {
  scanf("%d %d", &n, &m);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '*') {
        sp[i][j] = true;
        ++ans;
      } else {
        sp[i][j] = false;
        nsp[i][j] = false;
      }
    }
  }

  for (int it = 1; it * 2 + 1 <= m && it + 1 <= n; ++it) {
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 1; j < m - 1; ++j) {
        if (sp[i][j] && sp[i+1][j-1] && sp[i+1][j] && sp[i+1][j+1]) {
          ++ans;
          nsp[i][j] = true;
        } else {
          nsp[i][j] = false;
        }
      }
    }

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      sp[i][j] = nsp[i][j];
    }
  }

  printf("%d\n", ans);
  return 0;
}
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}