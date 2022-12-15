#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbPoints, nbSegs;
  cin >> nbPoints >> nbSegs;

  vector<pair<int, int>> segments(nbSegs);
  nbPoints *= 2;
  vector<bool> libre(nbPoints, true);
  for (auto &[l, r] : segments) {
    cin >> l >> r;
    --l, --r;
    if (l > r)
      swap(l, r);
    libre[l] = libre[r] = false;
  }

  vector<int> restants;
  for (int i = 0; i < nbPoints; ++i)
    if (libre[i])
      restants.push_back(i);
  assert(restants.size() + 2 * segments.size() == libre.size());

  int nbRestants = restants.size() / 2;
  for (int k = 0; k < nbRestants; ++k)
    segments.emplace_back(restants[k], restants[k + nbRestants]);
  int nbInter = 0;
  nbSegs = segments.size();
  /*cerr << "===========\n";
  for (auto [l, r] : segments)
    cout << l << ' ' << r << endl;*/

  auto inclus = [](int deb1, int fin1, int deb2, int fin2) {
    return (deb1 <= deb2 and fin2 <= fin1) or deb2 > fin1;
  };

  for (int i = 0; i < nbSegs; ++i)
    for (int j = i + 1; j < nbSegs; ++j) {
      auto [deb1, fin1] = segments[i];
      auto [deb2, fin2] = segments[j];
      if ((!inclus(deb1, fin1, deb2, fin2) and
           !inclus(deb2, fin2, deb1, fin1))) {
        // cout << "Inter : " << deb1 << ' ' << fin1 << ' ' << deb2 << ' ' <<
        // fin2
        //<< endl;
        nbInter++;
      }
    }
  cout << nbInter << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}