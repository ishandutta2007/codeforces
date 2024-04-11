#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, p;
int a[N];

bool check(int x, int t) {
  int idx = 0, cur = 0;
  for (int i = 0; i < n; ++i) {
    while (idx < n && a[idx] <= x + i) ++idx, ++cur;

    if (t == 0) {
      if (cur <= 0) return false;
    } else if (t == 1) {
      if (cur >= p) return false;
    }
    --cur;
  }

  return true;
}

int solve() {
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);

  int l = a[0], r = a[n-1];
  int ans1 = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid, 0)) {
      ans1 = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  l = a[0], r = a[n-1];
  int ans2 = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid, 1)) {
      ans2 = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  // cerr << ans1 << " " << ans2 << endl;
  if (ans1 == -1 || ans2 == -1 || ans1 > ans2) {
    return 0 * printf("0\n\n");
  }

  printf("%d\n", ans2 - ans1 + 1);
  for (int i = ans1; i <= ans2; ++i) printf("%d ", i);
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}