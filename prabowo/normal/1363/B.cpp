#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
char s[N];

int solve() {
  scanf("%s", s);
  n = strlen(s);

  int ans = N;
  int suf[2] = {0, 0};
  for (int i = n-1; i >= 0; --i) {
    ++suf[s[i] - '0'];
  }

  ans = min(ans, min(suf[0], suf[1]));

  int cnt[2] = {0, 0};
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i] - '0'];
    --suf[s[i] - '0'];

    ans = min(ans, min(suf[0] + cnt[1], suf[1] + cnt[0]));
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