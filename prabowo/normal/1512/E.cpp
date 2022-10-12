#include <bits/stdc++.h>
using namespace std;
 
const int N = 505;

int ans[N];

int solve() {
  int n, l, r, s;
  scanf("%d %d %d %d", &n, &l, &r, &s);

  vector<int> ans(n);
  vector<bool> vis(n);

  int len = r - l + 1;

  int cur = 0;
  for (int i = 0; i < len; ++i) {
    int prv = cur;
    while ((len - i) * (len - i + 1) / 2 <= s) {
      s -= len - i;
      ++cur;
    }
    // cerr << cur << " ";
    if (cur == prv) return 0 * printf("-1\n");
    ans[i] = cur;
    vis[cur - 1] = true;
  }
  if (cur > n) return 0 * printf("-1\n");
  // cerr << endl;

  int j = 0;
  for (int i = len; i < n; ++i) {
    while (vis[j]) ++j;
    vis[j] = true;
    ans[i] = j + 1;
  }

  rotate(ans.begin(), ans.begin() + (n - l + 1) % n, ans.end());

  for (int u : ans) printf("%d ", u);
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