#include <bits/stdc++.h>
#define int long long
using namespace std;

int nbSommets;

vector<int> query(int u) {
  cout << "? " << u + 1 << endl;
  vector<int> dis(nbSommets);
  for (int i = 0; i < nbSommets; ++i) {
    cin >> dis[i];
  }
  return dis;
}

signed main(void) {
  cin >> nbSommets;

  vector<vector<int>> queries(nbSommets);
  vector<int> depth = query(0);
  queries[0] = depth;
  vector<pair<int, int>> edges;

  int cntSide[2] = {0, 0};
  for (int i = 0; i < nbSommets; ++i) {
    cntSide[depth[i] % 2]++;
  }

  int side = 0;
  if (cntSide[1] < cntSide[0])
    side = 1;

  for (int i = 0; i < nbSommets; ++i) {
    if (depth[i] % 2 != side)
      continue;

    if (queries[i].empty())
      queries[i] = query(i);
    for (int j = 0; j < nbSommets; ++j)
      if (queries[i][j] == 1)
        edges.emplace_back(i, j);
  }

  cout << "!\n";
  for (auto [u, v] : edges)
    cout << u + 1 << ' ' << v + 1 << endl;
  return 0;
}