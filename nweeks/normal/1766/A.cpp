#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string s;
  cin >> s;

  int cnt = (s.size() - 1) * 9 + s[0] - '0';
  cout << cnt << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}