#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
int n, m;

int solve() {
  scanf("%d %d", &n, &m);
  vector<int> row(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &row[i]);
  }
  vector<int> col(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &col[i]);
  }

  int ans = 0;
  for (int i = 0; i < m; ++i) if (binary_search(row.begin(), row.end(), col[i])) ++ans;
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