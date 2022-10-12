#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;

int n, m;
int a[N], w[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &w[i]);
  }

  sort(a, a + n);
  sort(w, w + m);

  long long ans = 0;
  int i = 0, j = n-1;
  for (; i < m && w[i] == 1; ++i) {
    ans += a[j--] * 2;
  }

  int l = 0;
  for (int k = m-1; k >= i; --k) {
    ans += a[j--];
    ans += a[l];
    l += w[k] - 1;
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}