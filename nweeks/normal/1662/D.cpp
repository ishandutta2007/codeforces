#include <bits/stdc++.h>
#define int long long
using namespace std;

string normalize(string s) {
  int cntB = 0;
  vector<char> cur;
  for (char c : s) {
    if (c != 'B')
      cur.push_back(c);
    else
      cntB ^= 1;
  }
  if (cntB)
    cur.push_back('B');
  int sz = cur.size();
  while (true) {
    bool change = false;
    for (int i = 0; i < sz - 1; ++i) {
      if (cur[i] == cur[i + 1]) {
        change = true;
        cur.erase(cur.begin() + i, cur.begin() + i + 2);
        sz -= 2;
        break;
      }
    }
    if (!change)
      break;
  }
  return string(cur.begin(), cur.end());
}

void solve() {
  string u, v;
  cin >> u >> v;
  u = normalize(u), v = normalize(v);
  cout << (u == v ? "YES" : "NO") << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}