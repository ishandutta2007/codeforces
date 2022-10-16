#include <bits/stdc++.h>
using namespace std;

const int maxn = 112345;

int n;
long long a[maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  sort(a + 1, a + n + 1);
  long long ans = -1e18;
  for (int i = 0; i < 3; i++) {
    long long now = 1;
    for (int j = 0; j < i; j++) now *= a[2 * j + 1] * a[2 * j + 2];
    for (int j = 0; j < 5 - 2 * i; j++) now *= a[n - j];
    ans = max(ans, now);
  }
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}