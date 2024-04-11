#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int MOD = 1000000007;

int solve() {
  int n;
  scanf("%d", &n);

  int two = 1, per = n;
  for (int i = 1; i < n; ++i) {
    two = 2LL * two % MOD;
    per = 1LL * per * i % MOD;
  }

  int ans = (per - two + MOD) % MOD;
  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}