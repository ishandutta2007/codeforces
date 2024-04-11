#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, k;
int a[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  vector<int> ans;
  while (true) {
    int fall = -1;
    for (int i = 1; i < n; ++i) {
      if (a[i - 1] < a[i]) {
        fall = i - 1;
        ++a[i - 1];
        break;
      }
    }

    if (fall == -1) break;

    ans.push_back(fall);
  }

  if (k - 1 < ans.size()) printf("%d\n", ans[k - 1] + 1);
  else printf("-1\n");
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