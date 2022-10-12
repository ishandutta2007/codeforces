#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, k, l;
int d[N];

int solve() {
  scanf("%d %d %d", &n, &k, &l);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d[i]);
  }

  int cur = k, dir = -1;
  for (int i = 0; i < n; ++i) {
    if (d[i] + k <= l) {
      cur = k;
      dir = -1;
    } else {
      if (d[i] + cur > l) {
        if (dir == 1) return 0 * printf("No\n");
        cur = l - d[i];
        if (cur < 0) return 0 * printf("No\n");
      }

      if (cur == k || cur == 0) dir *= -1;
      cur += dir;
    }
  }

  printf("Yes\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}