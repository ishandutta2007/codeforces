#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

char s[N];

int solve() {
  scanf("%s", s);
  int n = strlen(s);

  int cur0 = 0, cur1 = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      ++cur0;
    } else if (s[i] == '[') {
      ++cur1;
    } else if (s[i] == ')') {
      if (cur0 > 0) {
        --cur0;
        ++ans;
      }
    } else if (s[i] == ']') {
      if (cur1 > 0) {
        --cur1;
        ++ans;
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
    solve();
  }
  return 0;
}