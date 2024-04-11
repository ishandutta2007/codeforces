#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N], b[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }

  bool exact = false;
  int ans = -1;
  for (int i = 0; i < n; ++i) {
    if (b[i] > a[i]) return 0 * printf("NO\n");
    if (b[i] > 0) {
      exact = true;
      ans = a[i] - b[i];
    }
  }

  if (!exact) return 0 * printf("YES\n");

  for (int i = 0; i < n; ++i) {
    if (b[i] == 0) {
      if (a[i] > ans) return 0 * printf("NO\n");
    } else {
      if (a[i] - b[i] != ans) return 0 * printf("NO\n");
    }
  }

  printf("YES\n");
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