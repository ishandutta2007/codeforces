#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
int b[N];

int cntA[N], cntB[N];

int solve() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i) cntA[i] = 0;
  for (int i = 0; i < m; ++i) cntB[i] = 0;

  for (int i = 0; i < k; ++i) {
    scanf("%d", &a[i]);
    ++cntA[--a[i]];
  }
  for (int i = 0; i < k; ++i) {
    scanf("%d", &b[i]);
    ++cntB[--b[i]];
  }

  long long ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += k - (cntA[a[i]] + cntB[b[i]]) + 1;
  }

  printf("%lld\n", ans / 2);
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