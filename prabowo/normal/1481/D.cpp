#include <bits/stdc++.h>
using namespace std;
 
const int N = 1005;

int n, m;
char s[N][N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (s[i][j] == s[j][i] || (m & 1)) {
        printf("YES\n");
        for (int k = 0; k <= m; ++k) {
          if (k & 1) printf("%d ", j + 1);
          else printf("%d ", i + 1);
        }
        printf("\n");
        return 0;
      }
    }
  }

  if (n == 2) return 0 * printf("NO\n");

  if (s[0][1] == s[1][2] && s[1][2] == s[2][0]) {
    printf("YES\n");
    for (int i = 0; i <= m; ++i) {
      if (i % 3 == 0) printf("1 ");
      else if (i % 3 == 1) printf("2 ");
      else printf("3 ");
    }
    printf("\n");
    return 0;
  }

  int a, b;
  if (s[0][1] == s[1][2]) {
    a = 0, b = 2;
  } else if (s[1][2] == s[2][0]) {
    a = 1, b = 0;
  } else if (s[2][0] == s[0][1]) {
    a = 2, b = 1;
  } else {
    assert(0);
  }

  int mid = (3 ^ a ^ b);

  if (m % 4 == 2) {
    printf("YES\n");
    printf("%d ", a + 1);
    for (int i = 0; i < m/2 - 1; ++i) {
      if (i & 1) printf("%d ", a + 1);
      else printf("%d ", b + 1);
    }
    printf("%d %d ", mid + 1, b + 1);
    for (int i = 0; i < m/2 - 1; ++i) {
      if (i & 1) printf("%d ", b + 1);
      else printf("%d ", a + 1);
    }
    printf("\n");
  } else {
    printf("YES\n");
    printf("%d ", mid + 1);
    for (int i = 0; i < m/2; ++i) {
      if (i & 1) printf("%d ", mid + 1);
      else printf("%d ", a + 1);
    }
    for (int i = 0; i < m/2; ++i) {
      if (i & 1) printf("%d ", mid + 1);
      else printf("%d ", b + 1);
    }
  }
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