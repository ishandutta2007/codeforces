#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;

int n;
int a[N];

int solve() {
  scanf("%d", &n);

  long long sum = 0;
  long long suf[2] = {0LL, 0LL};
  long long maxi = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (i & 1) sum += a[i];

    if ((i % 2 == 0) && i > 1) {
      long long term = a[i] - a[i-1];
      suf[0] = max(suf[0] + term, term);
      maxi = max(maxi, suf[0]);
    } else if (i & 1) {
      long long term = -a[i] + a[i-1];
      suf[1] = max(suf[1] + term, term);
      maxi = max(maxi, suf[1]);
    }
  }

  sum = max(sum, sum + maxi);
  printf("%lld\n", sum);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}