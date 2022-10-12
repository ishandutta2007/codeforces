#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];
int sum[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  sum[n] = 0;
  for (int i = n-1; i >= 0; --i) {
    sum[i] = max(a[i], sum[i+1] - 1);
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i > 0) sum[i] = max(sum[i], sum[i-1]);
    ans += sum[i] - a[i];
  }

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