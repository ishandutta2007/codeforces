#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
int cnt[N * 2];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i <= n * 2; ++i) cnt[i] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i] - i + n];
  }

  long long ans = 0;
  for (int i = 0; i <= n * 2; ++i) {
    ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
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