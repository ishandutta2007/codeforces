#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int MOD = 1000000007;

int n;
char s[N];

int solve() {
  scanf("%s", s);
  n = strlen(s);

  vector<int> v;
  int suf0 = 0;
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j < n && s[j] == '0') ++j;
    if (j < n) v.push_back(j - i);
    else suf0 = j - i;
    i = j;
  }
  ++suf0;

  if (v.size() == 0) return 0 * printf("%d\n", n);

  vector<pair<int, int>> dp;
  int ans = suf0;
  while (v.size()) {
    int u = v.back() + 1;
    v.pop_back();

    int nans = ans;
    int lst = 0;
    while (dp.size() > 0 && u >= dp.back().first) {
      nans = (nans - 1LL * (dp.back().first - lst) * dp.back().second) % MOD;
      lst = dp.back().first;
      dp.pop_back();
    }

    if (dp.size() > 0) {
      nans = (nans - 1LL * (u - lst) * dp.back().second) % MOD;
    }

    nans = (nans + 1LL * u * ans) % MOD;

    dp.push_back({u, ans});
    ans = nans;

    // cerr << u << " " << ans << endl;
  }

  ans = 1LL * dp.back().first * dp.back().second % MOD;
  if (ans < 0) ans += MOD;

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}