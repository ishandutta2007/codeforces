#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n;
char s[N][N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }

  for (int i = n-1; i >= 0; --i) {
    for (int j = n-1; j >= 0; --j) {
      if (s[i][j] == '0') continue;

      if (i == n-1 || j == n-1 || s[i+1][j] == '1' || s[i][j+1] == '1');
      else return 0 * printf("NO\n");
    }
  }

  printf("YES\n");
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}