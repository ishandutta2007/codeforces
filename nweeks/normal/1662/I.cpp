#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbHuts, nbMagasins;
  cin >> nbHuts >> nbMagasins;

  vector<int> nbPersonnes(nbHuts);
  for (int &x : nbPersonnes)
    cin >> x;
  vector<int> prefSum(nbHuts + 1);
  for (int i = 0; i < nbHuts; ++i)
    prefSum[i + 1] = prefSum[i] + nbPersonnes[i];
  vector<int> posMagasins(nbMagasins);
  for (int &x : posMagasins)
    cin >> x;

  posMagasins.push_back(-1e9);
  posMagasins.push_back(2e9);
  sort(posMagasins.begin(), posMagasins.end());
  nbMagasins += 2;

  int sol = 0;

  for (int deb = 0; deb < nbHuts; ++deb) {
    int magAvant =
        upper_bound(posMagasins.begin(), posMagasins.end(), 100 * deb) -
        posMagasins.begin() - 1;
    assert(magAvant >= 0);
    if (posMagasins[magAvant] == 100 * deb)
      continue;

    int magApres =
        lower_bound(posMagasins.begin(), posMagasins.end(), 100 * deb) -
        posMagasins.begin();

    assert(magApres < nbMagasins);

    int pos = min(200 * deb - posMagasins[magAvant], posMagasins[magApres]);

    int fin = (posMagasins[magApres] + pos) / 200;
    if (200 * fin == pos + posMagasins[magApres])
      --fin;
    if (100 * fin < pos)
      fin = pos / 100;
    fin = min(fin, nbHuts - 1);
    sol = max(sol, prefSum[fin + 1] - prefSum[deb]);
  }
  cout << sol << endl;
}