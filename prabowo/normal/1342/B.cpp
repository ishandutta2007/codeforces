#include <bits/stdc++.h>
using namespace std;

char s[105];

int solve() {
  scanf("%s", s);
  int n = strlen(s);

  bool allsame = true;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[0]) {
      allsame = false;
      break;
    }
  }

  if (allsame) return 0 * printf("%s\n", s);

  for (int i = 0; i < n; ++i) {
    printf("01");
  }
  printf("\n");
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