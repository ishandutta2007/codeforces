#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  if (b >= 0) {
    cout << n * (a + b) << '\n';
    return;
  }

  int segs0 = 0, seg1 = 0;
  int cur = 0;
  while (cur < n) {
    int cnt = 0;
    while (cur + cnt < n and s[cur + cnt] == s[cur])
      ++cnt;
    if (s[cur] == '0')
      segs0++;
    else
      seg1++;
    cur += cnt;
  }
  cout << n * a + b * (1 + min(segs0, seg1)) << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}