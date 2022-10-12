#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, x;
int a[N];

int solve() {
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  sort(a, a + n, greater<int>());

  int ans = 0;
  long long excess = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > x) {
      excess += a[i] - x;
      ++ans;
    } else if (excess >= x - a[i]) {
      excess -= x - a[i];
      ++ans;
    }
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}