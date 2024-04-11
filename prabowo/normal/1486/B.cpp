#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int x[N], y[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }
  sort(x, x + n);
  sort(y, y + n);

  long long ans = 1;
  if ((n % 2) == 0) {
    ans *= x[n / 2] - x[n / 2 - 1] + 1;
    ans *= y[n / 2] - y[n / 2 - 1] + 1;
  }

  printf("%lld\n", ans);
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