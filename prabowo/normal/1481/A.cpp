#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m;
int a[N];
char s[N];

int solve() {
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  int len = strlen(s);
  int x = 0, y = 0;
  for (int i = 0; i < len; ++i) {
    if (s[i] == 'R' && n > 0) ++x;
    if (s[i] == 'L' && n < 0) --x;
    if (s[i] == 'U' && m > 0) ++y;
    if (s[i] == 'D' && m < 0) --y;
  }

  if (!(n > 0 && x >= n || n <= 0 && x <= n)) return 0 * printf("NO\n");
  if (!(m > 0 && y >= m || m <= 0 && y <= m)) return 0 * printf("NO\n");

  printf("YES\n");
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