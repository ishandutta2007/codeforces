#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
pair<long long, long long> a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &a[i].first, &a[i].second);
  }
  sort(a, a + n, [](pair<long long, long long> p, pair<long long, long long> q) {
    return p.second < q.second;
  });

  long long ans = 0;
  long long bought = 0;
  for (int i = 0, j = n; i < j; ++i) {
    while (i < j && bought < a[i].second) {
      // cerr << i << " " << j << endl;
      --j;
      long long buy = max(0LL, min(a[i].second - bought, a[j].first));
      bought += buy;
      a[j].first -= buy;
      ans += buy * 2;
      if (a[j].first > 0) ++j;
    }

    if (i < j) {
      ans += a[i].first;
      bought += a[i].first;
    }
  }

  // cerr << "OK" << endl;

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