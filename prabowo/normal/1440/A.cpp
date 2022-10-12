#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, c0, c1, h;
char s[N];

int solve() {
  scanf("%d %d %d %d", &n, &c0, &c1, &h);
  scanf("%s", s);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      ans += min(c0, c1 + h);
    } else {
      ans += min(c1, c0 + h);
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