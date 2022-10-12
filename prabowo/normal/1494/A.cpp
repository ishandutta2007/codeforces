#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n;
char s[N];

int solve() {
  scanf("%s", s);
  int n = strlen(s);

  for (int i = 0; i < 8; ++i) {
    int cur = 0;
    bool can = true;
    for (int j = 0; j < n; ++j) {
      if (i >> (s[j] - 'A') & 1) {
        --cur;
      } else {
        ++cur;
      }

      if (cur < 0) can = false;
    }

    if (cur == 0 && can) return 0 * printf("YES\n");
  }

  printf("NO\n");
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