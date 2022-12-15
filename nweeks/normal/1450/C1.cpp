#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbLig, nbCol;
  cin >> nbLig;
  nbCol = nbLig;
  int nbCases = 0;
  vector<array<int, 2>> cnt(3, {0, 0});

  vector<string> grid(nbLig);
  for (int iLig = 0; iLig < nbLig; ++iLig) {
    grid[iLig].resize(nbCol);
    for (int iCol = 0; iCol < nbCol; ++iCol) {
      cin >> grid[iLig][iCol];
      if (grid[iLig][iCol] == 'O')
        cnt[(iLig + iCol) % 3][0]++, nbCases++;
      else if (grid[iLig][iCol] == 'X')
        cnt[(iLig + iCol) % 3][1]++, nbCases++;
    }
  }

  for (int i(0); i < 3; ++i)
    for (int j(0); j < 3; ++j)
      if (i != j and cnt[i][0] + cnt[j][1] <= nbCases / 3) {
        for (int iLig = 0; iLig < nbLig; ++iLig) {
          for (int iCol(0); iCol < nbCol; ++iCol) {
            char c = grid[iLig][iCol];
            if ((iLig + iCol) % 3 == i and c == 'O')
              c = 'X';
            if ((iLig + iCol) % 3 == j and c == 'X')
              c = 'O';
            cout << c;
          }
          cout << endl;
        }
        return;
      }
  assert(false);
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}