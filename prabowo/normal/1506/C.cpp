#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

char a[N];
char b[N];

int solve() {
  scanf("%s", a);
  scanf("%s", b);
  int n = strlen(a), m = strlen(b);

  int ans = n + m;
  for (int len = 1; len <= min(n, m); ++len) {
    for (int i = 0; i <= n - len; ++i) for (int j = 0; j <= m - len; ++j) {
      bool same = true;
      for (int k = 0; k < len; ++k) {
        if (a[i + k] != b[j + k]) {
          same = false;
          break;
        }
      }

      if (same) ans = min(ans, n + m - len*2);
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