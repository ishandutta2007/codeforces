#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, a, b, t;
char s[N];
long long cost[N], revCost[N];

int main() {
  scanf("%d %d %d %d", &n, &a, &b, &t);
  scanf("%s", s + 1);
  if (b * (s[1] == 'w') + 1 > t) {
    cout << 0 << endl;
    return 0;
  }
  t -= b * (s[1] == 'w') + 1;
  int res = 1;
  for (int i = 2; i <= n; i++) {
    cost[i] = cost[i - 1] + b * (s[i] == 'w') + a + 1;
    if (cost[i] <= t) {
      res = max(res, i);
    }
  }
  for (int i = n; i > 1; i--) {
    revCost[i] = revCost[i + 1] + b * (s[i] == 'w') + a + 1;
    if (revCost[i] <= t) {
      res = max(res, n - i + 2);
    }
  }
  for (int i = 2; i <= n; i++) {
    long long rest = 1ll * t - cost[i] - 1ll * (i - 1) * a;
    if (rest < 0) {
      continue;
    }
    int l = 1, r = n + 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (revCost[m] <= rest) {
        r = m;
      } else {
        l = m;
      }
    }
    res = max(res, i + n - r + 1);
  }
  for (int i = n; i > 1; i--) {
    long long rest = 1ll * t - revCost[i] - 1ll * (n - i + 1) * a;
    if (rest < 0) {
      continue;
    }
    int l = 1, r = n + 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (cost[m] <= rest) {
        l = m;
      } else {
        r = m;
      }
    }
    res = max(res, n - i + 2 + l - 1);
  }
  res = min(res, n);
  cout << res << endl;
  return 0;
}