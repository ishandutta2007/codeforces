#include <bits/stdc++.h>
using namespace std;
 
int solve() {
  long long n;
  scanf("%lld", &n);
  while (n % 2 == 0) n /= 2;

  if (n == 1) printf("NO\n"); else printf("YES\n");
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