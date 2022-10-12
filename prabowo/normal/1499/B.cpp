#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

char s[N];

int solve() {
  scanf("%s", s);
  int n = strlen(s);

  int zero = -1, one = n + 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == '0' && s[i - 1] == '0') {
      zero = i;
    }

    if (s[i] == '1' && s[i - 1] == '1') {
      one = min(one, i);
    }
  }

  printf(zero < one ? "YES\n" : "NO\n");
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