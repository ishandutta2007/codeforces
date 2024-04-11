#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int add[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int i = 1; i < n - 1; ++i) {
    add[i] = max(0, max(a[i - 1], a[i + 1]) - a[i] + 1);
  }

  long long ans = 0;
  if (n & 1) {
    for (int i = 1; i < n; i += 2) ans += add[i];
  } else {
    vector<long long> pre(n);
    pre[1] = add[1];
    for (int i = 3; i < n; i += 2) {
      pre[i] = pre[i - 2] + add[i];
    }

    long long suf = 0;
    ans = 1e18;
    for (int i = n - 2; i >= 0; i -= 2) {
      ans = min(ans, suf + (i > 0 ? pre[i - 1] : 0));
      // cerr << pre[i - 1] << " " << suf << endl;
      suf += add[i];
    }
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}