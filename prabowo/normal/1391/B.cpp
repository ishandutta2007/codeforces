#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
char s[N][N];

int solve() {
  scanf("%d %d", &n, &m);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    ans += s[i][m-1] == 'R';
  }

  for (int j = 0; j < m; ++j) {
    ans += s[n-1][j] == 'D';
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}