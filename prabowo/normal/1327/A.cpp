#include <bits/stdc++.h>
using namespace std;

int n, k;

int solve() {
  scanf("%d %d", &n, &k);
  if ((k & 1) != (n & 1)) return 0 * printf("NO\n");
  if (n < 1LL*k*k) return 0 * printf("NO\n");
  printf("YES\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}