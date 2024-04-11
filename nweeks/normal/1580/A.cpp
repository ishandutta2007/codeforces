#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MINLIG = 5, MINCOL = 4;
const int INF = 1e18;
void solve() {
  int nbLig, nbCol;
  cin >> nbLig >> nbCol;
  vector<vector<int>> grid(nbLig, vector<int>(nbCol));
  for (int iLig = 0; iLig < nbLig; ++iLig)
    for (int iCol = 0; iCol < nbCol; ++iCol) {
      char c;
      cin >> c;
      grid[iLig][iCol] = c - '0';
    }

  vector<vector<int>> prefSum(nbLig, vector<int>(nbCol));

  for (int iLig = 0; iLig < nbLig; ++iLig)
    for (int iCol = 0; iCol < nbCol; ++iCol) {
      prefSum[iLig][iCol] =
          grid[iLig][iCol] + (iLig ? prefSum[iLig - 1][iCol] : 0);
    }

  int sol = INF;

  vector<int> costCol(nbCol);
  vector<int> accCost(nbCol);
  for (int ligBas = 0; ligBas < nbLig; ++ligBas)
    for (int ligHaut = ligBas + MINLIG - 1; ligHaut < nbLig; ++ligHaut) {
      for (int iCol = 0; iCol < nbCol; ++iCol) {
        costCol[iCol] = ligHaut - ligBas - 1 -
                        (prefSum[ligHaut - 1][iCol] - prefSum[ligBas][iCol]);
        accCost[iCol] = prefSum[ligHaut - 1][iCol] - prefSum[ligBas][iCol] +
                        !grid[ligHaut][iCol] + !grid[ligBas][iCol];
        assert(costCol[iCol] >= 0 and accCost[iCol] >= 0);
        if (iCol > 0)
          accCost[iCol] += accCost[iCol - 1];
      }

      int meilleur = INF;
      for (int iCol = MINCOL - 1; iCol < nbCol; ++iCol) {
        meilleur = min(meilleur,
                       costCol[iCol - MINCOL + 1] - accCost[iCol - MINCOL + 1]);
        sol = min(sol, meilleur + costCol[iCol] + accCost[iCol - 1]);
      }
    }
  cout << sol << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}