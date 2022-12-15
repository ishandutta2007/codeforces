#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbCases;
  cin >> nbCases;
  vector<int> prefSum[2];
  for (int i = 0; i < 2; ++i) {
    prefSum[i].resize(nbCases + 1);
    for (int j = 0; j < nbCases; ++j) {
      cin >> prefSum[i][j + 1];
      prefSum[i][j + 1] += prefSum[i][j];
    }
  }
  int ret = 1e18;

  for (int takeL = 1; takeL <= nbCases; ++takeL) {
    ret = min(ret, max(prefSum[1][takeL - 1],
                       prefSum[0][nbCases] - prefSum[0][takeL]));
  }
  cout << ret << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}