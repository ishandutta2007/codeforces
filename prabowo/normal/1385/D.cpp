#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
char s[N];
int dp[N];

int solve() {
  scanf("%d", &n);
  scanf("%s", s);

  char hi = 'a' + __builtin_ctz(n);

  for (int k = 1; k <= n; k <<= 1) {
    for (int i = 0; i < n; i += k) {
      if (k == 1) {
        dp[i] = 0;
        if (s[i] != hi) dp[i] = 1;
      } else {
        int lft = 0, rgt = 0;
        for (int j = i; j < i+k/2; ++j) {
          if (s[j] != hi) ++lft;
        }

        for (int j = i + k/2; j < i+k; ++j) {
          if (s[j] != hi) ++rgt;
        }

        dp[i] = min(lft + dp[i + k/2], dp[i] + rgt);
      }
    }

    --hi;
  }

  printf("%d\n", dp[0]);
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