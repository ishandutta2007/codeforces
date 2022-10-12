#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%d %d", &n, &m);

  long long maxi = 0, sum = 0;
  vector<pair<long long, int>> maxs;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
    if (sum > maxi) {
      maxs.push_back(make_pair(sum, i));
      maxi = sum;
    }
  }

  while (m--) {
    long long x;
    scanf("%lld", &x);
    int idx = lower_bound(maxs.begin(), maxs.end(), make_pair(x, -1)) - maxs.begin();
    if (idx < 0 || idx >= maxs.size()) {
      if (sum <= 0) {
        printf("-1 ");
      } else {
        long long ans = (x - maxs.back().first + sum - 1) / sum;
        // cerr << "a" << ans << endl;
        x -= ans * sum;
        ans *= n;

        ans += maxs[lower_bound(maxs.begin(), maxs.end(), make_pair(x, -1)) - maxs.begin()].second;
        printf("%lld ", ans);
      }
    } else {
      printf("%d ", maxs[idx].second);
    }
  }
  printf("\n");
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