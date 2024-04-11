#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int sumWanted;
  cin >> sumWanted;
  int sz = sqrt(sumWanted);
  if (sz * sz != sumWanted)
    sz++;
  cout << sz << '\n';
  return;

  if (sumWanted == 1) {
    cout << 1 << '\n';
  } else if (sumWanted <= 3)
    cout << 2 << '\n';
  else {
    sumWanted -= 1;
    int lst = 3;
    int sz = 1;
    while (sumWanted > lst) {
      sumWanted -= lst;
      lst += 2;
      sz++;
    }
    if (sumWanted)
      sz++;
    cout << sz << '\n';
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