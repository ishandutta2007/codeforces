#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  vector<int> pos1(n);

  int ret = 0;
  int lst[2][2] = {{-1, -1}, {-1, -1}};
  for (int i = 0; i < n; ++i) {
    int toAdd = 0;
    int p = i % 2;
    for (int b = 0; b < 2; ++b) {
      if (s[i] != '?' and s[i] - '0' != b)
        continue;
      int bef = max(lst[b][!p], lst[!b][p]);
      toAdd = max(toAdd, i - bef);
    }
    ret += toAdd;
    if (s[i] != '?')
      lst[s[i] - '0'][i % 2] = i;
  }
  cout << ret << endl;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}