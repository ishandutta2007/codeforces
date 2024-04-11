#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int w, l;
  cin >> w >> l;

  set<int> sol;

  auto ajouteDiviseurs = [](int D) -> set<int> {
    set<int> ret;
    for (int d = 1; d * d <= D; ++d)
      if (D % d == 0) {
        ret.insert(d);
        ret.insert(D / d);
      }
    return ret;
  };

  for (int mask = 0; mask < (1 << 4); ++mask) {
    array<int, 4> coins = {w - 2, w - 2, l - 2, l - 2};
    if (mask & 1)
      coins[0]++;
    else
      coins[2]++;
    if (mask & 2)
      coins[0]++;
    else
      coins[3]++;
    if (mask & 4)
      coins[3]++;
    else
      coins[1]++;
    if (mask & 8)
      coins[1]++;
    else
      coins[2]++;
    array<set<int>, 4> possibles;
    for (int i = 0; i < 4; ++i)
      possibles[i] = ajouteDiviseurs(coins[i]);
    for (int x : possibles[0]) {
      bool ok = true;
      for (int i = 1; i < 4; ++i)
        if (ok)
          ok &= possibles[i].count(x);
      if (ok)
        sol.insert(x);
    }
  }
  cout << sol.size() << ' ';
  for (int d : sol)
    cout << d << ' ';
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