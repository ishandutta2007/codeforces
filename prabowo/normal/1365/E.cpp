#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n;
long long a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, a[i]);
    for (int j = i+1; j < n; ++j) {
      ans = max(ans, a[i] | a[j]);
      for (int k = j+1; k < n; ++k) {
        ans = max(ans, a[i] | a[j] | a[k]);
      }
    }
  }

  printf("%lld\n", ans);
  return 0;
}


int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}