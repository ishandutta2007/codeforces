#include <bits/stdc++.h>
using namespace std;

const int NK = 200005;

int n, k;
int a[NK];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n*k; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n*k, greater<int>());

  int median = n/2;

  int cur = 0;
  long long ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += a[cur + median];
    cur += median + 1;
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