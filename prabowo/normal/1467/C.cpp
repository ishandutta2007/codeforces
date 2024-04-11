#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n[3];

int solve() {
  scanf("%d %d %d", &n[0], &n[1], &n[2]);
  long long mini[3];
  long long sum[3];
  long long ans = 0;
  for (int k = 0; k < 3; ++k) {
    sum[k] = 0;
    mini[k] = INF + 5;
    for (int i = 0; i < n[k]; ++i) {
      int a;
      scanf("%d", &a);
      sum[k] += a;
      mini[k] = min(mini[k], 1LL*a);
      ans += a;
    }
  }

  ans -= 2 * min( min(mini[0] + mini[1], min(mini[1] + mini[2], mini[0] + mini[2])), min(sum[0], min(sum[1], sum[2])) );

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}