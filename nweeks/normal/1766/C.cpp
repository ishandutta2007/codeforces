#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbCol;
  cin >> nbCol;
  vector<array<int, 2>> needCol(nbCol);
  for (int lig = 0; lig < 2; ++lig)
    for (int col = 0; col < nbCol; ++col) {
      char c;
      cin >> c;
      needCol[col][lig] = c == 'B';
    }

  for (int deb = 0; deb < 2; ++deb)
    if (needCol[0][deb]) {
      vector<array<bool, 2>> seen(nbCol);
      for (int iCol = 0; iCol < nbCol; ++iCol)
        seen[iCol].fill(0);

      int curLig = deb, curCol = 0;
      while (curCol < nbCol) {
        seen[curCol][curLig] = true;
        if (!seen[curCol][!curLig] and needCol[curCol][!curLig]) {
          curLig ^= 1;
        } else
          curCol++;
      }
      bool ok = true;
      for (int col = 0; col < nbCol; ++col)
        for (int lig = 0; lig < 2; ++lig)
          ok &= seen[col][lig] == needCol[col][lig];
      if (ok) {
        cout << "YES\n";
        return;
      }
    }
  cout << "NO\n";
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}