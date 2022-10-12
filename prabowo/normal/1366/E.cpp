#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;

int n, m;
int a[N], b[N];

int premin[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

  premin[0] = a[0];
  for (int i = 1; i < n; ++i) {
    premin[i] = min(premin[i-1], a[i]);
  }

  int ans = 1, cur = n-1, mini = a[n-1];
  for (int i = m-1; i >= 0; --i) {
    if (cur < 0 || a[cur] < b[i]) return 0 * printf("0\n");
    int mini = a[cur];

    int cnt = (mini == b[i]);
    while (cur > 0 && a[cur-1] >= b[i]) {
      mini = min(mini, a[--cur]);
      if (mini == b[i]) ++cnt;
    }

    // cerr << i << " " << cur << " " << cnt << endl;
    --cur;

    if (i == 0) cnt = min(1, cnt);

    ans = 1LL * ans * cnt % MOD;
  }

  if (cur != -1) return 0 * printf("0\n");
  printf("%d\n", ans);
  return 0;
}


int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}