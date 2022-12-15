#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbBouteilles, nbCritiques;
  cin >> nbBouteilles >> nbCritiques;

  vector<int> nbRouges(nbCritiques), nbBlancs(nbCritiques);
  for (int i = 0; i < nbCritiques; ++i)
    cin >> nbRouges[i] >> nbBlancs[i];
  int maxRed = *max_element(nbRouges.begin(), nbRouges.end());
  int maxBlue = *max_element(nbBlancs.begin(), nbBlancs.end());
  if (maxBlue + maxRed > nbBouteilles) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  cout << string(maxRed, 'R') + string(nbBouteilles - maxRed, 'W') << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}