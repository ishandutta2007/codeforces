#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[2][2];

int solve() {
  int sum = 0;
  for (int i = 0; i < 4; ++i) {
    int a;
    scanf("%d", &a);
    sum += a;
  }

  int ans = 0;
  if (sum > 0) ans = 1;
  if (sum == 4) ans = 2;
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