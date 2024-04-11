#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;

int n;
int ten[N];

int solve() {
  scanf("%d", &n);
  ten[0] = 1; for (int i = 1; i <= n; ++i) ten[i] = 10LL * ten[i-1] % MOD;

  for (int i = 1; i <= n; ++i) {
    int ans = 0;
    if (i <= n-2) {
      ans = (ans + 810LL * ten[n-2-i] * (n-1-i)) % MOD;
    }

    if (i <= n-1) {
      ans = (ans + 180LL * ten[n-1-i]) % MOD;
    }

    if (i == n) ans = (ans + 10) % MOD;

    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}