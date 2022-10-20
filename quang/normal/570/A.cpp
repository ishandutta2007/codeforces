#include <bits/stdc++.h>

using namespace std;

const int N = 200;

int n, m;
int cnt[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int res = 0;
    int tot = -1;
    for (int j = 1; j <= n; j++) {
      int u;
      scanf("%d", &u);
      if (u > tot) {
        tot = u;
        res = j;
      }
    }
    cnt[res]++;
  }
  int ans = 0, totans = -1;
  for (int i = 1; i <= n; i++) {
    if (totans < cnt[i]) {
      totans = cnt[i];
      ans = i;
    }
  }
  cout << ans << endl;
}