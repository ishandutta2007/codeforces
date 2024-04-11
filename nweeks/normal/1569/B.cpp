#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbJoueurs;
  cin >> nbJoueurs;
  string s;
  cin >> s;
  vector<int> doitGagner;
  for (int i = 0; i < nbJoueurs; ++i)
    if (s[i] == '2')
      doitGagner.push_back(i);
  if (!doitGagner.empty() and doitGagner.size() < 3) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector<vector<int>> ret(nbJoueurs, vector<int>(nbJoueurs));
  string mp = "X+-=";
  for (int i = 0; i < nbJoueurs; ++i) {
    for (int j = 0; j < nbJoueurs; ++j) {
      if (i == j)
        ret[i][j] = 0;
      else
        ret[i][j] = 3;
    }
  }
  for (int i = 0; i < (int)doitGagner.size(); ++i) {
    int j = (i + 1) % doitGagner.size();
    ret[doitGagner[i]][doitGagner[j]] = 1;
    ret[doitGagner[j]][doitGagner[i]] = 2;
  }
  for (int i = 0; i < nbJoueurs; ++i) {
    for (int j = 0; j < nbJoueurs; ++j)
      cout << mp[ret[i][j]];
    cout << '\n';
  }
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}