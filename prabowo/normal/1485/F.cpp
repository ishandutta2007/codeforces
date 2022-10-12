#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  map<long long, int> dp;
  dp[0] = 1;
  long long sum = 1, pre = 0;
  for (int i = 0; i < n; ++i) {
    long long t = sum;
    sum = (sum * 2 - dp[pre]) % MOD;
    dp[pre] = t;
    pre += a[i];
  }
  if (sum < 0) sum += MOD;

  printf("%lld\n", sum);
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