#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbPierres, nbRequetes, iDebut, disJump;
  cin >> nbPierres >> nbRequetes >> iDebut >> disJump;

  --iDebut;
  vector<int> pos(nbPierres);
  for (int &x : pos)
    cin >> x;

  vector<int> lftLft(nbPierres), lftRgt(nbPierres), rgtLft(nbPierres),
      rgtRgt(nbPierres);
  for (int iPierre = 0; iPierre < nbPierres; ++iPierre) {
    int posLft = lower_bound(pos.begin(), pos.end(), pos[iPierre] - disJump) -
                 pos.begin();
    lftLft[iPierre] = posLft - 1;
    lftRgt[iPierre] = posLft;
    int posRgt = lower_bound(pos.begin(), pos.end(), pos[iPierre] + disJump) -
                 pos.begin();
    rgtRgt[iPierre] = posRgt;
    rgtLft[iPierre] = posRgt - 1;
  }
  set<int> alive;
  for (int i = 0; i < nbPierres; ++i)
    alive.insert(i);

  priority_queue<tuple<int, int, int>> pq;
  pq.emplace(0, iDebut, -1);

  vector<int> dis(nbPierres, INF);
  dis[iDebut] = 0;

  auto calcWeight = [&](int u, int v) {
    return abs(disJump - abs(pos[u] - pos[v]));
  };

  auto addEdges = [&](int iPierre) {
    auto it = alive.upper_bound(lftLft[iPierre]);
    if (it != alive.begin()) {
      it--;
      pq.emplace(-max(dis[iPierre], calcWeight(*it, iPierre)), *it, iPierre);
    }
    it = alive.lower_bound(lftRgt[iPierre]);
    if (it != alive.end()) {
      pq.emplace(-max(dis[iPierre], calcWeight(*it, iPierre)), *it, iPierre);
    }
    it = alive.lower_bound(rgtRgt[iPierre]);
    if (it != alive.end()) {
      pq.emplace(-max(dis[iPierre], calcWeight(*it, iPierre)), *it, iPierre);
    }
    it = alive.upper_bound(rgtLft[iPierre]);
    if (it != alive.begin()) {
      it--;
      pq.emplace(-max(dis[iPierre], calcWeight(*it, iPierre)), *it, iPierre);
    }
  };
  vector<bool> seen(nbPierres);
  set<pair<int, int>> seen2;

  while (!pq.empty()) {
    auto [d, iPierre, iAvant] = pq.top();
    pq.pop();
    // cout << "See " << iPierre << ' ' << -d << ' ' << iAvant << ' ' <<
    // pq.size()
    //<< endl;
    if (seen2.count({iPierre, iAvant}))
      continue;
    seen2.emplace(iPierre, iAvant);

    alive.erase(iPierre);
    d = -d;
    if (iAvant != -1)
      addEdges(iAvant);

    if (seen[iPierre])
      continue;
    dis[iPierre] = d;
    seen[iPierre] = true;
    addEdges(iPierre);
  }

  while (nbRequetes--) {
    int i, k;
    cin >> i >> k;
    cout << (dis[i - 1] <= k ? "Yes" : "No") << '\n';
  }
}