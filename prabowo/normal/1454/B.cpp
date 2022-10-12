#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
pair<int, int> a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }

  sort(a, a + n);

  for (int i = 0; i < n; ++i) {
    int t = 0;
    if (i == 0 || a[i].first != a[i-1].first) ++t;
    if (i == n-1 || a[i].first != a[i+1].first) ++t;
    if (t == 2) return 0 * printf("%d\n", a[i].second + 1);
  }
  printf("-1\n");
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