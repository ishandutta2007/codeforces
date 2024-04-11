#include <bits/stdc++.h>
using namespace std;
 
const int N = 25;

int n, m;
char s[N][N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }

  int ans = 0;
  for (int x = 0, y = 0; x < n - 1 || y < m - 1; ) {
    // cerr << x << " " << y << endl;
    if (s[x][y] == '*') ++ans;
    if (y + 1 < m && s[x][y + 1] == '*') {
      ++y;
    } else if (x + 1 < n && s[x + 1][y] == '*') {
      ++x;
    } else if (y + 1 < m) {
      ++y;
    } else {
      ++x;
    }
  }

  if (s[n - 1][m - 1] == '*') ++ans;

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}