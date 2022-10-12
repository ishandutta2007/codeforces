#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int INF = 1e9;

int n, m;
int a[N], b[N];

int sa[N];
long long pre[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &a[i], &b[i]);
    sa[i] = a[i];
  }

  sort(sa, sa + m, greater<int>());
  pre[0] = sa[0];
  for (int i = 1; i < m; ++i) pre[i] = pre[i-1] + sa[i];

  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    int idx = upper_bound(sa, sa + m, b[i], greater<int>()) - sa;
    if (idx > n-1) idx = n-1;

    long long sum = 0;
    if (idx == 0) sum = a[i] + 1LL * (n - 1) * b[i];
    else {
      if (sa[idx-1] <= a[i]) {
        sum = pre[idx-1] + 1LL * (n-idx) * b[i];
        if (n-idx > 0 && idx < m && sa[idx] > b[i]) {
          sum -= b[i];
          sum += sa[idx];
        }
      }
      else sum = pre[idx-1] + a[i] + 1LL * (n-1-idx) * b[i];
    }

    ans = max(ans, sum);
  }

  printf("%lld\n", ans);
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