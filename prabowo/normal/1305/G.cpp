#include <bits/stdc++.h>
using namespace std;

const int LN = 18;
const int N = 1 << LN;

int n;
int a[N];
int cnt[N];

int par[N];
int root(int u) {
  if (u == par[u]) return u;
  return par[u] = root(par[u]);
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i]];
  }
  ++cnt[0];

  for (int i = 0; i < N; ++i) par[i] = i;

  long long ans = 0;
  for (int mask = N-1; mask >= 0; --mask) {
    for (int u = mask; u > 0; u = (u-1 & mask)) {
      int v = mask ^ u;
      if (v > u) break;
      if (cnt[u] > 0 && cnt[v] > 0 && root(u) != root(v)) {
        ans += 1LL * (cnt[u] + cnt[v] - 1) * mask;
        cnt[u] = cnt[v] = 1;
        par[par[u]] = par[v];
      }
    }
  }

  for (int i = 0; i < n; ++i) ans -= a[i];
  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}