#include <bits/stdc++.h>
using namespace std;
 
const int N = 2005;
 
int n;
char s[N][N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }

  vector<int> ans(10);

  for (int k = 0; k < 2; ++k) {
    vector<int> lo[10], hi[10];
    for (int d = 0; d < 10; ++d) lo[d] = vector<int>(n, n), hi[d] = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int d = s[i][j] - '0';
        lo[d][i] = hi[d][i] = i;
      }
    }
    for (int d = 0; d < 10; ++d) {
      for (int i = 1; i < n; ++i) lo[d][i] = min(lo[d][i], lo[d][i - 1]);
      for (int i = n - 2; i >= 0; --i) hi[d][i] = max(hi[d][i], hi[d][i + 1]);
    }

    for (int i = 0; i < n; ++i) {
      vector<int> lft(10, n), rgt(10, -1);
      for (int j = 0; j < n; ++j) {
        int d = s[i][j] - '0';
        lft[d] = min(lft[d], j);
        rgt[d] = max(rgt[d], j);
      }

      int h = max(i, n - i - 1);
      for (int d = 0; d < 10; ++d) {
        ans[d] = max(ans[d], max(0, rgt[d] - lft[d]) * h);
        ans[d] = max(ans[d], max(0, max(n - 1 - lft[d], rgt[d])) * max(0, max(i - lo[d][i], hi[d][i] - i)));
      }
    }

    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(s[i][j], s[j][i]);
  }

  for (int i = 0; i < 10; ++i) printf("%d ", ans[i]); printf("\n");
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