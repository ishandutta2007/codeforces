#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int nbPer, nbClefs, posOffice;
  cin >> nbPer >> nbClefs >> posOffice;

  vector<int> posPer(nbPer);
  for (int iPer = 0; iPer < nbPer; ++iPer) {
    cin >> posPer[iPer];
  }
  vector<int> posClefs(nbClefs);
  for (int iClef = 0; iClef < nbClefs; ++iClef) {
    cin >> posClefs[iClef];
  }
  sort(posPer.begin(), posPer.end());
  sort(posClefs.begin(), posClefs.end());
  vector<vector<int>> dp(nbPer + 1, vector<int>(nbClefs + 1, 1e18));
  for (int i = 0; i <= nbClefs; ++i) {
    dp[nbPer][i] = 0;
  }

  for (int iPer(nbPer - 1); iPer >= 0; --iPer)
    for (int iClef(nbClefs); iClef >= 0; --iClef) {
      int &cur = dp[iPer][iClef];
      if (iClef == nbClefs)
        continue;
      cur = min(cur, dp[iPer][iClef + 1]);
      cur = min(cur, max(dp[iPer + 1][iClef + 1],
                         abs(posPer[iPer] - posClefs[iClef]) +
                             abs(posClefs[iClef] - posOffice)));
    }
  cout << dp[0][0] << endl;
}