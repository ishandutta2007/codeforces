#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://github.com/nweeks1/UltiSnips
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int lb, int ub) {
  return uniform_int_distribution<int>(lb, ub)(rng);
}

void solve() {
  int nbPersonnes;
  cin >> nbPersonnes;
  vector<int> target(nbPersonnes);
  for (auto &v : target) {
    cin >> v;
    --v;
  }

  vector<vector<int>> antec(nbPersonnes);
  for (int i = 0; i < nbPersonnes; ++i)
    antec[target[i]].push_back(i);

  vector<int> ret(nbPersonnes);
  vector<int> nonPris, aChoisir;
  int sol = 0;
  for (int i = 0; i < nbPersonnes; ++i) {
    if (!antec[i].empty()) {
      int j = antec[i].back();
      ret[j] = i;
      sol++;
      antec[i].pop_back();
      for (auto v : antec[i])
        aChoisir.push_back(v);
    } else
      nonPris.push_back(i);
  }
  sort(aChoisir.begin(), aChoisir.end());
  sort(nonPris.begin(), nonPris.end());
  int nbRestant = aChoisir.size();
  assert((int)nonPris.size() == nbRestant);
  vector<int> perm(nbRestant);
  for (int i = 0; i < nbRestant; ++i)
    perm[i] = i;
  if (nbRestant != 1 or aChoisir[0] != nonPris[0]) {
    do {
      bool ok = true;
      for (int i = 0; i < nbRestant; ++i)
        if (aChoisir[i] == nonPris[perm[i]])
          ok = false;
      if (ok) {
        for (int i = 0; i < nbRestant; ++i)
          ret[aChoisir[i]] = nonPris[perm[i]];
        break;
      }
      shuffle(perm.begin(), perm.end(), rng);
    } while (true);
  } else {
    int rest = aChoisir[0];
    for (int i = 0; i < nbPersonnes; ++i)
      if (target[i] == target[rest])
        ret[i] = rest;
    ret[rest] = target[rest];
  }

  cout << sol << '\n';
  for (auto v : ret)
    cout << v + 1 << ' ';
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