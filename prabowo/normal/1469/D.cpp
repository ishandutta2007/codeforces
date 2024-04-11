#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%d", &n);
  vector<pair<int, int>> ans;
  int an = n;
  for (int i = n - 1; i >= 3; --i) {
    if ((an + i - 1) / i >= i) {
      ans.emplace_back(n, i);
      an = (an + i - 1) / i;
    }
    ans.emplace_back(i, n);
  }
  while (an > 1) {
    ans.emplace_back(n, 2);
    an = (an + 1) / 2;
  }

  printf("%d\n", (int) ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  // cerr << ans.size() << endl;
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