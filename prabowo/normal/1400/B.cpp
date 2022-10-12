#include <bits/stdc++.h>
using namespace std;

int p, f;
int cs, cw;
int s, w;

int solve() {
  scanf("%d %d", &p, &f);
  scanf("%d %d", &cs, &cw);
  scanf("%d %d", &s, &w);

  if (w < s) {
    swap(s, w);
    swap(cs, cw);
  }

  int ans = 0;
  for (int i = 0; i <= cs; ++i) {
    if (i * s > p) break;
    
    int cs = ::cs, cw = ::cw, p = ::p, f = ::f;

    int t = i;

    int take = min(cw, (p - (i * s)) / w);
    cw -= take;
    t += take;

    take = min(cs-i, f / s);
    t += take;
    f -= take * s;

    t += min(cw, f / w);

    ans = max(ans, t);
  }

  printf("%d\n", ans);
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