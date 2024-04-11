#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
 
int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  // n = unique(a, a + n) - a;

  long long ans = 0;
  int maxi = 0;
  for (int i = 1; i < n; ++i) {
    ans += abs(a[i] - a[i - 1]);
    maxi = max(maxi, abs(a[i] - a[i - 1]) + (i > 1 ? abs(a[i - 1] - a[i - 2]) - abs(a[i] - a[i - 2]) : 0));
  }
  if (n >= 2) maxi = max(maxi, abs(a[n - 1] - a[n - 2]));


  printf("%lld\n", ans - maxi);
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