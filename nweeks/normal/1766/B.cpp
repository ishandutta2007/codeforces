#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int len;
  cin >> len;
  string s;
  cin >> s;
  set<pair<char, char>> seen;
  for (int i = 0; i < len - 1; ++i) {
    pair<char, char> p(s[i], s[i + 1]);
    if (seen.count(p)) {
      cout << "YES\n";
      return;
    }
    if (i)
      seen.emplace(s[i - 1], s[i]);
  }
  cout << "NO\n";
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}