#include <bits/stdc++.h>

using namespace std;

const int maxn = 1234;

int a[maxn], n, rec, ans = 0x3f3f3f3f;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int t = 1; t <= 100; t++) {
    int cur = 0;
    for (int i = 1; i <= n; i++) {
      int now = abs(a[i] - t);
      now = min(now, abs(a[i] - t - 1));
      now = min(now, abs(a[i] - t + 1));
      cur += now;
    }
    if (ans > cur) {
      ans = cur;
      rec = t;
    }
  }
  printf("%d %d", rec, ans);
}