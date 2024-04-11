#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);

  int ans = a[1] - a[0];
  for (int i = 2; i < n; ++i) {
    ans = min(ans, a[i] - a[i-1]);
  }
  printf("%d\n", ans);
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}