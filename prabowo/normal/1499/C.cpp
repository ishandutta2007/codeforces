#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int INF = 1e9;
const long long INFLL = 1LL * INF * INF;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int mini[2] = {INF, INF};
  long long sum[2] = {0LL, 0LL};
  int cnt[2] = {0, 0};

  long long ans = INFLL;

  for (int i = 0; i < n; ++i) {
    mini[i & 1] = min(mini[i & 1], a[i]);
    sum[i & 1] += a[i];
    ++cnt[i & 1];

    ans = min(ans, sum[0] + 1LL * (n - cnt[0]) * mini[0] + sum[1] + 1LL * (n - cnt[1]) * mini[1]);
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