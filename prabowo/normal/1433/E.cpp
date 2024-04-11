#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n;
int a[N];

int solve() {
  int n;
  scanf("%d", &n);

  long long ans = 1;
  for (int i = 1; i <= n/2 - 1; ++i) ans = ans * (n - i) / i;

  for (int i = 1; i <= n/2 - 1; ++i) ans = ans * i * i;

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}