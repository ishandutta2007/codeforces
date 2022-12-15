#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  map<int, int> seen;
  seen[0] = 0;
  int curS = 0;
  for (int i = 0; i < n; ++i) {
    curS += (s[i] == 'a' ? 1 : -1);
    if (seen.count(curS)) {
      cout << seen[curS] + 1 << ' ' << i + 1 << '\n';
      return;
    }
    seen[curS] = i + 1;
  }
  cout << -1 << ' ' << -1 << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}