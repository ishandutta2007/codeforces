#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int l = a[0], r = a[0] + k;
  for (int i = 1; i < n; ++i) {
    l -= k - 1;
    r += k - 1;
    l = max(l, a[i]);
    r = min(r, a[i] + k-1 + k);
    // cerr << i << " " << l << " " << r << endl;
    if (r - l < k) return 0 * printf("NO\n");
  }

  if (l > a[n - 1]) return 0 * printf("NO\n");

  printf("YES\n");
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