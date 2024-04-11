#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n, k;
int a[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  if (n == 1) return 0 * printf("0\n");

  multiset<pair<int, int>> ms;
  vector<vector<int>> nums(N);
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      nums[i].push_back(a[i] / j);
    }
  }
  for (int i = 0; i < N; ++i) {
    if (nums[i].size() > 0) ms.insert({nums[i].back(), i});
  }

  int ans = 1e9;
  while (true) {
    int u, i;
    tie(u, i) = *ms.begin();
    ms.erase(ms.begin());

    ans = min(ans, ms.rbegin()->first - u);

    nums[i].pop_back();
    if (nums[i].size() == 0) break;
    ms.insert({nums[i].back(), i});
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}