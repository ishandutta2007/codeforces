#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbLig, nbCol;
  cin >> nbLig >> nbCol;
  vector<string> grid(nbLig);
  for (int iLig = 0; iLig < nbLig; ++iLig) {
    cin >> grid[iLig];
  }

  bool hasRed[2] = {false, false}, hasWhite[2] = {false, false};

  for (int iLig = 0; iLig < nbLig; ++iLig)
    for (int iCol = 0; iCol < nbCol; ++iCol) {
      if (grid[iLig][iCol] == 'R')
        hasRed[(iLig + iCol) % 2] = true;
      if (grid[iLig][iCol] == 'W')
        hasWhite[(iLig + iCol) % 2] = true;
    }

  bool sideRed = false;
  if (hasRed[1] or hasWhite[0])
    sideRed = 1;
  if (hasRed[!sideRed] or hasWhite[sideRed]) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int iLig = 0; iLig < nbLig; ++iLig) {
    for (int iCol = 0; iCol < nbCol; ++iCol) {
      if (sideRed == (iLig + iCol) % 2)
        cout << "R";
      else
        cout << "W";
    }
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