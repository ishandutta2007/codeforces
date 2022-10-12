#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  long long sum = 0, maxi = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
    maxi = max(maxi, 1LL*a[i]);
  }

  long long ans = (maxi * (n - 1) < sum ? ((n-1) - sum % (n-1)) % (n-1) : maxi * (n-1) - sum);
  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}