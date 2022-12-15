#include <bits/stdc++.h>
using namespace std;

void solve() {
  int nbPersonnes;
  cin >> nbPersonnes;
  const int nbConcours = 5;

  vector<array<int, nbConcours>> rank(nbPersonnes);
  for (int i = 0; i < nbPersonnes; ++i)
    for (int j = 0; j < nbConcours; ++j)
      cin >> rank[i][j];

  auto estMeilleur = [&](int a, int b) { // a dominates b ?
    int cntBest = 0;
    for (int c = 0; c < nbConcours; ++c)
      cntBest += rank[a][c] < rank[b][c];
    return cntBest > 2;
  };

  int curBest = 0;
  for (int i = 1; i < nbPersonnes; ++i)
    if (estMeilleur(i, curBest))
      curBest = i;
  bool ok = true;
  for (int i = 0; i < nbPersonnes; ++i)
    if (i != curBest and !estMeilleur(curBest, i))
      ok = false;
  cout << (ok ? curBest + 1 : -1) << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}