#include <bits/stdc++.h>
#include <numeric>
#define int long long
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbCartes;
  cin >> nbCartes;
  vector<int> small(nbCartes), large(nbCartes);
  vector<bool> flippedInitial(nbCartes);

  for (int iCarte = 0; iCarte < nbCartes; ++iCarte) {
    cin >> small[iCarte] >> large[iCarte];
    if (small[iCarte] > large[iCarte]) {
      swap(small[iCarte], large[iCarte]);
      flippedInitial[iCarte] = true;
    }
  }

  vector<int> bySmall(nbCartes);
  vector<int> byLarge(nbCartes);
  iota(byLarge.begin(), byLarge.end(), 0);
  iota(bySmall.begin(), bySmall.end(), 0);
  sort(bySmall.begin(), bySmall.end(),
       [&](int i, int j) { return small[i] > small[j]; });
  sort(byLarge.begin(), byLarge.end(),
       [&](int i, int j) { return large[i] < large[j]; });

  vector<bool> extracted(nbCartes);

  int sol = 0;
  while (!bySmall.empty()) {
    while (!bySmall.empty() and extracted[bySmall.back()])
      bySmall.pop_back();
    if (bySmall.empty())
      break;
    // cout << "New one !" << endl;
    int start = bySmall.back();
    bySmall.pop_back();
    extracted[start] = true;
    queue<pair<int, int>> q;
    q.emplace(start, 0);
    vector<int> side[2];
    while (!q.empty()) {
      auto [u, par] = q.front();
      // cout << u + 1 << ' ' << par << endl;
      q.pop();
      side[par].push_back(u);

      if (!par) { // Those with large too large ?
        while (!byLarge.empty() and large[byLarge.back()] > large[u]) {
          int v = byLarge.back();
          byLarge.pop_back();
          if (!extracted[v]) {
            extracted[v] = true;
            q.emplace(v, !par);
          }
        }
      } else {
        while (!bySmall.empty() and small[bySmall.back()] < small[u]) {
          int v = bySmall.back();
          bySmall.pop_back();
          if (!extracted[v]) {
            extracted[v] = true;
            q.emplace(v, !par);
          }
        }
      }
    }
    // cout << endl;

    sort(side[0].begin(), side[0].end(),
         [&](int i, int j) { return small[i] < small[j]; });
    sort(side[1].begin(), side[1].end(),
         [&](int i, int j) { return large[i] < large[j]; });
    for (int i = 1; i < (int)side[0].size(); ++i)
      if (large[side[0][i - 1]] < large[side[0][i]]) {
        cout << -1 << '\n';
        return 0;
      }
    for (int i = 1; i < (int)side[1].size(); ++i)
      if (small[side[1][i - 1]] < small[side[1][i]]) {
        cout << -1 << '\n';
        return 0;
      }
    if (!side[1].empty() and large[side[0].back()] < small[side[1][0]]) {
      cout << -1 << endl;
      return 0;
    }
    if (!side[1].empty() and small[side[1].back()] > large[side[0][0]]) {
      cout << -1 << endl;
      return 0;
    }
    int cntBad = 0;
    int cntTot = side[0].size() + side[1].size();
    for (int i : side[0])
      cntBad += flippedInitial[i];
    for (int i : side[1])
      cntBad += !flippedInitial[i];
    sol += min(cntBad, cntTot - cntBad);
  }
  cout << sol << endl;
}