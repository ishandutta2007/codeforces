#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int solve() {
  scanf("%d %d %d", &n, &m, &k);
  string ans = "";
  for (int i = 1; i < n; ++i) ans += 'U';
  for (int i = 1; i < m; ++i) ans += 'L';

  for (int i = 0; i < n; ++i) {
    if (i & 1) for (int j = 1; j < m; ++j) ans += 'L';
    else for (int j = 1; j < m; ++j) ans += 'R';
    if (i < n-1) ans += 'D';
  }

  printf("%d\n", (int) ans.size());
  for (char c: ans) printf("%c", c);
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}