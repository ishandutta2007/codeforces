#include <bits/stdc++.h>
using namespace std;

vector<int> ordinary = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};

int solve() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int o : ordinary) {
    ans += min(n / o, 9);
  }
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