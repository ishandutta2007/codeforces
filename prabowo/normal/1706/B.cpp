#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);

  vector<vector<int>> parities(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];

    parities[a[i]].push_back(i & 1);
  }

  for (int i = 0; i < n; ++i) {
    int dp[2] = {0, 0};
    for (int p : parities[i]) {
      dp[p] = dp[p ^ 1] + 1;
    }
    printf("%d ", max(dp[0], dp[1]));
  }
  printf("\n");
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