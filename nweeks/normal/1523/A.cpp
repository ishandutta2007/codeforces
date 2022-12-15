#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string t = "0";
  t += s;
  t += '0';
  s = move(t);

  for (int j(0); j < m; ++j) {
    bool change = false;
    string nxt = s;
    for (int i(1); i <= n; ++i) {
      if (s[i] == '0' and (s[i - 1] != s[i + 1]))
        change = true, nxt[i] = '1';
    }
    s = move(nxt);
    if (!change)
      break;
  }
  cout << s.substr(1, n) << endl;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}