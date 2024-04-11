#include <bits/stdc++.h>
#include <utility>
#define int long long
using namespace std;

void solve() {
  int nbPoints;
  cin >> nbPoints;
  vector<int> height(nbPoints);
  for (int iPoint = 0; iPoint < nbPoints; ++iPoint)
    cin >> height[iPoint];

  auto dis = [&](int a, int b) {
    return abs(a - b) + abs(height[a] - height[b]);
  };

  int ret = 0;
  for (int deb = 0; deb < nbPoints; ++deb) {
    for (int fin = deb; fin < deb + 5 and fin < nbPoints; ++fin) {
      bool ok = true;
      for (int i = deb; i < fin; ++i)
        for (int j = i + 1; j < fin; ++j)
          if (dis(i, j) + dis(j, fin) == dis(i, fin))
            ok = false;
      if (ok)
        ret++;
      else
        break;
    }
  }
  cout << ret << endl;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}