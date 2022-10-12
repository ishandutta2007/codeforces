#include <bits/stdc++.h>
using namespace std;
 
const int N = 5005;

int n, m, k;
int tag[N];
int s[N];

long long dp[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tag[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i]);
  }
  for (int i = 0; i < n; ++i) {
    dp[i] = 0;
  }

  for (int i = 1; i < n; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (tag[i] == tag[j]) continue;
      int add = abs(s[i] - s[j]);
      long long ndpi = dp[j] + add;
      long long ndpj = dp[i] + add;
      dp[i] = max(dp[i], ndpi);
      dp[j] = max(dp[j], ndpj);
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, dp[i]);
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