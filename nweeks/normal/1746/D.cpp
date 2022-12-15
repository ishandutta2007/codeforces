#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> fils;
vector<int> scores;
int sol;

int solve(int u, int nbChemins) {
  sol += nbChemins * scores[u];
  if (fils[u].empty()) {
    return scores[u];
  }

  vector<int> possibles;
  int cheminsFils = nbChemins / fils[u].size();
  int aDonner = nbChemins % fils[u].size();
  for (int v : fils[u])
    possibles.push_back(solve(v, cheminsFils));
  sort(possibles.begin(), possibles.end());
  while (aDonner) {
    sol += possibles.back();
    possibles.pop_back();
    --aDonner;
  }
  return possibles.back() + scores[u];
}

void solve() {
  int nbSommets, nbChemins;
  cin >> nbSommets >> nbChemins;
  fils = vector<vector<int>>(nbSommets);
  scores.resize(nbSommets);
  for (int i = 1; i < nbSommets; ++i) {
    int p;
    cin >> p;
    fils[p - 1].push_back(i);
  }
  for (int &s : scores)
    cin >> s;
  sol = 0;
  solve(0, nbChemins);
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