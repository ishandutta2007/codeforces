#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, x;
int a[N];

int solve() {
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  sort(a, a + n, greater<int>());

  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ++cnt;
    if (1LL * cnt * a[i] >= x) {
      ++ans;
      cnt = 0;
    }
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