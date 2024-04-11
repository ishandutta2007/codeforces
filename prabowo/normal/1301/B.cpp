#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int ans = 0;
  int maxi = -1, mini = 2e9;
  for (int i = 1; i < n; ++i) {
    if (a[i] >= 0 && a[i-1] >= 0) {
      ans = max(ans, abs(a[i] - a[i-1]));
    } else if ((a[i] < 0 && a[i-1] >= 0) || (a[i-1] < 0 && a[i] >= 0)) {
      if (a[i] >= 0) maxi = max(maxi, a[i]), mini = min(mini, a[i]);
      if (a[i-1] >= 0) maxi = max(maxi, a[i-1]), mini = min(mini, a[i-1]);
    }
  }

  if (maxi < 0) {
    if (a[0] == -1) return 0 * printf("0 0\n");
    return 0 * printf("%d 0\n", ans);
  }

  int diff = (maxi - mini + 1) / 2;
  ans = max(ans, diff);
  printf("%d %d\n", ans, mini + diff);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}