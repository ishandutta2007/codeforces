#include <bits/stdc++.h>
using namespace std;

const int N = 5000005;

int n, m;
int a[N];

bool has[N];
int cnt[N];
int dp[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) cnt[i] = has[i] = 0;

  int maxi = -1, mini = N;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    has[a[i]] = true;
    maxi = max(maxi, a[i]);
    mini = min(mini, a[i]);
    cnt[a[i]] = 1;
  }

  iota(dp, dp + m + 1, 0);

  int cur = maxi;
  int ans = N;
  for (int i = maxi; i >= 1; --i) {
    for (long long j = 1LL * i * i; j <= maxi; j += i) {
      if (has[j]) {
        --cnt[dp[j]];
        ++cnt[dp[j] = min(dp[j], dp[j / i])];
      } else {
        dp[j] = min(dp[j], dp[j / i]);
      }
    }
    while (cnt[cur] == 0) --cur;
    if (i <= mini) ans = min(ans, cur - i);
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}