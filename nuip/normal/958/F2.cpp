#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int tot;
int ans;
int as[214514];
int ks[214514];
int cnt[214514];
map<int, int> req;

int main() {
  scanf("%d%d", &n, &m);
  for (int i=0; i<n; i++) {
    scanf("%d", &as[i]);
    as[i]--;
  }

  for (int i=0; i<m; i++) {
    scanf("%d", &ks[i]);
    if (ks[i] > 0) req[i] = ks[i];
    tot += ks[i];
  }

  int l = 0;
  int r = 0;
  ans = n+1;
  while (l < n) {
    while (r < n && !req.empty()) {
      if (req.count(as[r])) {
        --req[as[r]];
        if (req[as[r]] == 0) req.erase(as[r]);
      }
      cnt[as[r]]++;
      r++;
    }

    if (!req.empty()) break;
    ans = min(ans, r-l-tot);

    cnt[as[l]]--;
    if (cnt[as[l]] < ks[as[l]]) req[as[l]] = ks[as[l]] - cnt[as[l]];
    l++;
  }

  if (ans == n+1) puts("-1");
  else printf("%d\n", ans);
}