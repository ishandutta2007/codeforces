#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, x, y;

char s[N];

int solve() {
  scanf("%d %d %d %d", &n, &m, &x, &y);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    for (int i = 0; i < m; ++i) {
      if (s[i] == '*') continue;
      if (x*2 < y) {
        ans += x;
      } else {
        if (i+1 < m && s[i+1] == '.') {
          ans += y;
          ++i;
        } else {
          ans += x;
        }
      }
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