#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
int l[N], r[N];
pair<int, int> p[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &l[i], &r[i]);
    p[i] = {l[i], r[i]};
  }
  sort(l, l + n);
  sort(r, r + n);

  int ans = n;
  for (int i = 0; i < n; ++i) {
    int t = 0;
    t += lower_bound(r, r + n, p[i].first) - r;
    t += n - (upper_bound(l, l + n, p[i].second) - l);
    ans = min(ans, t);
  }

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