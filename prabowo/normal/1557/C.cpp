#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;

int n, m, k;
int a[N];

int dpSame[N], dpLarge[N];

int solve() {
  scanf("%d %d", &n, &k);

  // 2^(n - 1)
  int two = 1;
  for (int i = 1; i < n; ++i) two = 2LL * two % MOD;

  dpSame[0] = 1; dpLarge[0] = 0;
  for (int i = 1; i <= k; ++i) {
    // Make it same = 0
    dpSame[i] = 1LL * (two - (n % 2 == 0)) * dpSame[i - 1] % MOD;
    // Make it same = 1
    dpSame[i] = (dpSame[i] + (n % 2 == 1) * dpSame[i - 1]) % MOD;

    // 1 vs 0
    dpLarge[i] = (n % 2 == 0) * dpSame[i - 1];

    dpLarge[i] = (dpLarge[i - 1] * 2LL * two + dpLarge[i]) % MOD;
  }

  int ans = (dpSame[k] + dpLarge[k]) % MOD;

  printf("%d\n", ans);
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