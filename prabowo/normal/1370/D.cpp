#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k;
int a[N];

bool check(int x) {
  int cnt = 0;
  for (int i = 1; i < n - (k % 2 == 1); ++i) {
    if (a[i] <= x) {
      ++cnt;
      ++i;
    }
  }

  if (cnt >= k/2) return true;

  cnt = 0;
  for (int i = 0; i < n - (k % 2 == 0); ++i) {
    if (a[i] <= x) {
      ++cnt;
      ++i;
    }
  }

  if (cnt >= (k+1)/2) return true;
  return false;
}

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  int l = 1, r = 1000000000, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}