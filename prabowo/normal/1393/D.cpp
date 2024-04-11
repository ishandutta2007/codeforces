#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, m;
char s[N][N];

int up[N][N], down[N][N];
int lft[N], rgt[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }

  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n;) {
      int nxt = i;
      while (nxt < n && s[nxt][j] == s[i][j]) ++nxt;

      for (int k = i; k < nxt; ++k) {
        up[k][j] = i;
        down[k][j] = nxt - 1;
      }

      i = nxt;
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur;
    for (int j = 0; j < m; ++j) {
      if (j == 0 || s[i][j] != s[i][j-1]) cur = 0;
      ++cur;

      cur = min(cur, down[i][j] - i + 1);
      cur = min(cur, i - up[i][j] + 1);
      lft[j] = cur;
    }

    for (int j = m-1; j >= 0; --j) {
      if (j == m-1 || s[i][j] != s[i][j+1]) cur = 0;
      ++cur;
      cur = min(cur, down[i][j] - i + 1);
      cur = min(cur, i - up[i][j] + 1);
      rgt[j] = cur;
    }

    for (int j = 0; j < m; ++j) {
      ans += min(lft[j], rgt[j]);
    }
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}