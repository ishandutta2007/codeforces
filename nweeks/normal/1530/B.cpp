#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbLig, nbCol;
  cin >> nbLig >> nbCol;

  for (int iLig = 0; iLig < nbLig; ++iLig) {
    if (iLig == 0 or iLig == nbLig - 1) {
      for (int iCol = 0; iCol < nbCol; ++iCol)
        if (iCol % 2 == 0)
          cout << 1;
        else
          cout << 0;
    } else {
      if (iLig % 2 == 0 and iLig + 1 != nbLig - 1)
        cout << 1;
      else
        cout << 0;
      for (int iCol = 1; iCol < nbCol - 1; ++iCol)
        cout << 0;
      if (iLig % 2 == 0 and iLig + 1 != nbLig - 1)
        cout << 1;
      else
        cout << 0;
    }
    cout << '\n';
  }
  cout << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}