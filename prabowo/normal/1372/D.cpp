#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int a[N];

int ans[N];
long long pre[N], suf[N];

int solve() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    pre[i] = (i >= 2 ? pre[i-2] + a[i] : a[i]);
  }

  for (int i = n-1; i >= 0; --i) {
    suf[i] = suf[i+2] + a[i];
  }

  long long ans = suf[0];
  for (int i = 1; i < n; ++i) {
    ans = max(ans, pre[i-1] + suf[i]);
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}