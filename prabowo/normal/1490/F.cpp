#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
int cnt[N], cs[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i) {
    cnt[i] = 0;
    cs[i] = 0;
  }
  vector<int> comp(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    comp[i] = a[i];
  }
  sort(comp.begin(), comp.end());

  for (int i = 0; i < n; ++i) {
    ++cnt[lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin()];
  }

  for (int i = 0; i <= n; ++i) {
    ++cs[cnt[i]];
  }

  int pre = 0, suf = 0, csuf = 0;
  for (int i = 0; i <= n; ++i) {
    pre += cs[i] * i;
  }

  int ans = 1e9;
  for (int i = n; i >= 0; --i) {
    pre -= cs[i] * i;
    ans = min(ans, pre + suf);
    csuf += cs[i];
    suf += csuf;
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