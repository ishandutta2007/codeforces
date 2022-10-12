#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  long long ans = -1e18;
  for (int i = max(n - 102, 0); i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ans = max(ans, 1LL * (i + 1) * (j + 1) - 1LL * k * (a[i] | a[j]));
    }
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