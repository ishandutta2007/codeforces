#include <bits/stdc++.h>
using namespace std;

char s[55];

int solve() {
  scanf("%s", s);
  int n = strlen(s);

  if (n < 3) return 0 * printf("YES\n");

  for (int i = 2; i < n; ++i) {
    int c = ((s[i - 2] - 'A') + (s[i - 1] - 'A')) % 26;
    if (c + 'A' != s[i]) return 0 * printf("NO\n");
  }

  printf("YES\n");
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