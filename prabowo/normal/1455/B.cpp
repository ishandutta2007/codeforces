#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
int n;

int solve() {
  scanf("%d", &n);
  int cur = 0;
  int ans = 0;
  while (cur < n) {
    cur += ++ans;
  }

  printf("%d\n", ans + (cur - n == 1 ? 1 : 0));
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