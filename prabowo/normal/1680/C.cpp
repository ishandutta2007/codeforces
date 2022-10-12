#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
char s[N];

int solve() {
  // scanf("%d", &n);
  scanf("%s", s);
  n = strlen(s);

  int cnt1R = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') ++cnt1R;
  }
  int cnt0 = 0;

  int ans = cnt1R;

  int r = 0;
  int cnt1L = 0;
  for (int l = 0; l < n; ++l) {
    while (r < l || (r < n && cnt1L + cnt1R > cnt0)) {
      if (s[r] == '1') --cnt1R;
      if (s[r] == '0') ++cnt0;
      ++r;
    }
    ans = min(ans, max(cnt1L + cnt1R, cnt0));

    // cerr << l << " " << r << endl;
    if (s[l] == '1') ++cnt1L;
    if (s[l] == '0') --cnt0;
  }
  // cerr << endl;

  printf("%d\n", ans);
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