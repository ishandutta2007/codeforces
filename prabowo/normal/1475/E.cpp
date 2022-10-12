#include <bits/stdc++.h>
using namespace std;
 
const int N = 1005;
const int MOD = 1000000007;

int n, k;
int a[N];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

int C(int n, int k) {
  int ret = 1;
  for (int i = 0; i < k; ++i) {
    ret = 1LL * ret * (n - i) % MOD * power(i + 1, MOD - 2) % MOD;
  }
  return ret;
}

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n, greater<int>());

  int l = k - 1, r = k - 1;
  while (l > 0 && a[l - 1] == a[k - 1]) --l;
  while (r < n - 1 && a[r + 1] == a[k - 1]) ++r;

  int ans = C(r - l + 1, k - l);

  printf("%d\n", ans);
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