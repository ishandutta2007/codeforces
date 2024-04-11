#include <bits/stdc++.h>
using namespace std;
 
const int N = 205;

int n;
char s[N];

int solve() {
  scanf("%d", &n);
  scanf("%s", s);

  string t = "2020";
  for (int i = 0; i <= 4; ++i) {
    bool okay = true;
    int cur = 0;
    for (int j = 0; j < i; ++j) {
      if (s[j] != t[cur++]) okay = false;
    }
    for (int j = n - 4 + i; j < n; ++j) {
      if (s[j] != t[cur++]) okay = false;
    }

    if (okay) return 0 * printf("YES\n");
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