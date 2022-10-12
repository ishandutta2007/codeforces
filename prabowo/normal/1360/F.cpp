#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, m;
char s[N][N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }

  for (int k = 0; k < m; ++k) {
    for (int c = 0; c < 26; ++c) {
      int tmp = s[0][k];
      s[0][k] = c + 'a';

      bool can = true;
      for (int i = 1; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
          if (s[i][j] == s[0][j]) continue;
          ++cnt;
        }

        if (cnt > 1) {
          can = false;
          break;
        }
      }

      if (can) {
        printf("%s\n", s[0]);
        return 0;
      }

      s[0][k] = tmp;
    }
  }

  printf("-1\n");
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}