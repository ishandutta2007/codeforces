#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int cnt[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    cnt[i+1] = 0;
  }
  int _n = unique(a, a + n) - a;

  for (int i = 0; i < _n; ++i) ++cnt[a[i]];

  int ans = n;
  for (int i = 1; i <= n; ++i) if (cnt[i] > 0) {
    int t = 0;
    if (a[0] == i) ++t;
    if (a[_n - 1] == i) ++t;
    ans = min(ans, cnt[i] + 1 - t);
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}