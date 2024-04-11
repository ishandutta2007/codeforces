#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n;
  long long l, r;
  scanf("%d", &n);
  scanf("%lld %lld", &l, &r);

  long long cur = 0;
  int idx = 0;
  for (idx = 0; idx < n; ++idx) {
    if (cur + (n-idx-1)*2 >= l) break;
    cur += (n - idx - 1) * 2;
  }

  while (idx < n) {
    for (int i = idx+1; i < n; ++i) {
      if (++cur > r) break;
      if (cur >= l) {
        printf("%d", idx+1);
        if (cur == r) printf("\n"); else printf(" ");
      }
      if (++cur > r) break;
      if (cur >= l) {
        printf("%d", i+1);
        if (cur == r) printf("\n"); else printf(" ");
      }
    }

    ++idx;
    if (cur > r) break;
  }

  if (++cur <= r) printf("1\n");
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();  
  return 0;
}