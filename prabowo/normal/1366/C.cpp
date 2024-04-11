#include <bits/stdc++.h>
using namespace std;

const int N = 33;

int n, m;
int a[N][N];

int cnt[N*2][2];

int solve() {
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n+m; ++i) cnt[i][0] = cnt[i][1] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int r = min(i+j, n+m-2-i-j);
      int a;
      scanf("%d", &a);
      ++cnt[r][a];
    }
  }

  int ans = 0;
  for (int i = 0; ; ++i) {
    if (n+m-2-i <= i) break;
    // cerr << min(cnt[i][0], cnt[i][1]) << endl;
    ans += min(cnt[i][0], cnt[i][1]);
  }

  printf("%d\n", ans);
  return 0;
}


int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}