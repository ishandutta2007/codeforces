#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
int cnt[N];

int solve() {
  scanf("%d %d", &n, &m);  
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i] % m];
  }

  int ans = 0;
  for (int i = 0; i <= m - i; ++i) {
    int l = cnt[i], r = cnt[(m - i) % m];
    if (l == 0 && r == 0) continue;

    // cerr << l << " " << r << endl;
    ans += max(0, max(l, r) - min(l, r) - 1);
    ++ans;
  }

  // cerr << endl;

  printf("%d\n", ans);

  for (int i = 0; i < n; ++i) cnt[a[i] % m] = 0;
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