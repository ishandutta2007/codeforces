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

  if (nbCol % 3 != 1) {
    for (int iLig = 0; iLig < nbLig; ++iLig)
      for (int iCol = 1; iCol < nbCol; iCol += 3)
        grid[iLig][iCol] = 'X';

    for (int iCol = 1; iCol + 3 < nbCol; iCol += 3) {
      bool ok = false;
      for (int iLig = 0; iLig < nbLig; ++iLig) {
        if (grid[iLig][iCol + 1] == 'X' or grid[iLig][iCol + 2] == 'X') {
          grid[iLig][iCol + 1] = grid[iLig][iCol + 2] = 'X';
          ok = true;
          break;
        }
      }
      if (!ok)
        grid[0][iCol + 1] = grid[0][iCol + 2] = 'X';
    }
  } else {
    for (int iLig = 0; iLig < nbLig; ++iLig)
      for (int iCol = 0; iCol < nbCol; iCol += 3)
        grid[iLig][iCol] = 'X';
    for (int iCol = 0; iCol + 3 < nbCol; iCol += 3) {
      bool ok = false;
      for (int iLig = 0; iLig < nbLig; ++iLig) {
        if (grid[iLig][iCol + 1] == 'X' or grid[iLig][iCol + 2] == 'X') {
          grid[iLig][iCol + 1] = grid[iLig][iCol + 2] = 'X';
          ok = true;
          break;
        }
      }
      if (!ok)
        grid[0][iCol + 1] = grid[0][iCol + 2] = 'X';
    }
  }
  for (auto v : grid)
    cout << v << '\n';
  // cerr << "==============\n";
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}