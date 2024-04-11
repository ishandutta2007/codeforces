#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k;
int a[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &a[i]);
  }

  int ans = max(a[0], n - a[k-1] + 1);
  for (int i = 1; i < k; ++i) {
    ans = max(ans, (a[i] - a[i-1]) / 2 + 1);
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