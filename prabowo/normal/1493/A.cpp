#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;

int solve() {
  scanf("%d %d", &n, &k);
  vector<int> ans;
  for (int i = 1; i < k; ++i) {
    if (i*2 >= k) ans.push_back(i);
  }
  for (int i = k + 1; i <= n; ++i) ans.push_back(i);

  printf("%d\n", (int) ans.size());
  for (int u : ans) printf("%d ", u); printf("\n");
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