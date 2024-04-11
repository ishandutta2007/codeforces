#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

long long a, b, n, m;

int solve() {
  scanf("%lld %lld %lld %lld", &a, &b, &n, &m);

  if (min(a, b) < m) return 0 * printf("No\n");
  if (a + b - m < n) return 0 * printf("No\n");
  printf("Yes\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}