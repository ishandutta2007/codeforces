#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
pair<int, int> a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }

  sort(a, a + n);

  int ans;
  if (a[0].first != a[1].first) ans = a[0].second;
  else ans = a[n - 1].second;

  printf("%d\n", ans + 1);
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