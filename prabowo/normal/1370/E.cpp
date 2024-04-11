#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n;
char s[2][N];

int solve() {
  scanf("%d", &n);
  scanf("%s", s[0]);
  scanf("%s", s[1]);

  int cnt[2][2] = {{0, 0}, {0, 0}};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      ++cnt[j][s[j][i] - '0'];
    }
  }

  if (cnt[0][0] != cnt[1][0] || cnt[0][1] != cnt[1][1]) {
    return 0 * printf("-1\n");
  }

  int c[2] = {0, 0};
  for (int i = n-1; i >= 0; --i) {
    if (s[0][i] == s[1][i]) continue;

    if (s[0][i] == '0') {
      if (c[1] > 0) {
        --c[1];
        ++c[0];
      } else {
        ++c[0];
      }
    } else {
      if (c[0] > 0) {
        --c[0];
        ++c[1];
      } else {
        ++c[1];
      }
    }
  }

  printf("%d\n", c[0] + c[1]);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}