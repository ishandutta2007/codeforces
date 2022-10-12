#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
int a[N];

int solve() {
  int x;
  scanf("%d", &x);

  int ans = 0;
  for (int i = 1; i <= 9; ++i) {
    int num = 0;
    for (int k = 0; k < 4; ++k) {
      num = num * 10 + i;
      ans += k + 1;
      if (num == x) return 0 * printf("%d\n", ans);
    }
  }
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