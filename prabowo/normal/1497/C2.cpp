#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m - 3; ++i) printf("1 ");
  n -= (m - 3);

  for (int two = 2; ; two *= 2) {
    if (n == two) return 0 * printf("%d %d %d\n", n/2, n/4, n/4);
    if (n % two == two / 2) {
      printf("%d %d %d\n", (n - two/2) / 2, (n - two/2) / 2, two/2);
      return 0;
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