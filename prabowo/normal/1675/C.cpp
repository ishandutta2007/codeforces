#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
char s[N];

bool hasZero[N], hasOne[N];

int solve() {
  scanf("%s", s);
  n = strlen(s);


  for (int i = 1; i < n; ++i) {
    hasZero[i] = (hasZero[i - 1] || s[i - 1] == '0');
  }

  hasOne[n - 1] = false;
  for (int i = n - 2; i >= 0; --i) {
    hasOne[i] = (hasOne[i + 1] || s[i + 1] == '1');
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (hasZero[i] || hasOne[i]) continue;
    ++ans;
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
}