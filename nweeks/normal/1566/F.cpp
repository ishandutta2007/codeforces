#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;

void solve() {
  int nbPoints, nbSegments;
  cin >> nbPoints >> nbSegments;

  vector<int> posPoints(nbPoints);
  vector<int> coords;
  for (int &x : posPoints)
    cin >> x;
  sort(posPoints.begin(), posPoints.end());
  vector<pair<int, int>> segments(nbSegments);
  for (auto &[l, r] : segments) {
    cin >> l >> r;
  }

  sort(segments.begin(), segments.end(), [&](auto l, auto r) {
    if (l.first == r.first)
      return l.second > r.second;
    return l.first < r.first;
  });

  priority_queue<pair<int, int>> pq;
  for (auto [l, r] : segments) {
    int i =
        lower_bound(posPoints.begin(), posPoints.end(), l) - posPoints.begin();
    if (i < nbPoints and posPoints[i] <= r)
      continue;
    while (!pq.empty() and pq.top().first >= r) {
      assert(pq.top().second <= l);
      pq.pop();
    }
    pq.emplace(r, l);
  }
  segments.clear();
  while (!pq.empty()) {
    auto [r, l] = pq.top();
    pq.pop();
    segments.emplace_back(l, r);
  }

  sort(segments.begin(), segments.end());
  nbSegments = segments.size();
  vector<int> bef(nbSegments), apres(nbSegments);
  for (int iSegment = 0; iSegment < nbSegments; ++iSegment) {
    auto [l, r] = segments[iSegment];
    bef[iSegment] = lower_bound(posPoints.begin(), posPoints.end(), l) -
                    posPoints.begin() - 1;
    apres[iSegment] =
        lower_bound(posPoints.begin(), posPoints.end(), r) - posPoints.begin();
  }

  vector<int> dpBef(1);

  int cur = 0;
  while (cur < nbSegments) {
    int i = cur;
    while (i < nbSegments and bef[i] == bef[cur])
      ++i;
    // [cur, i) : pas de points entre les deux

    int nbS = i - cur;
    vector<int> curDp(nbS + 1, INF);
    int minAvant = INF;
    for (int x : dpBef)
      minAvant = min(minAvant, x);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        hp;
    int meilleur = 1e18;
    priority_queue<pair<int, int>> hp2;
    if (bef[cur] >= 0)
      for (int prendAvant = 1; prendAvant < (int)dpBef.size(); ++prendAvant) {
        int diff = posPoints[bef[cur]] - segments[cur - prendAvant].second;
        hp.emplace(dpBef[prendAvant] + diff, diff);
        hp2.emplace(diff, prendAvant);
      }

    for (int prendDroite = 0; prendDroite <= nbS; ++prendDroite) {
      int prendGauche = nbS - prendDroite;
      if (prendDroite and apres[cur] == nbPoints)
        continue;
      if (prendGauche and bef[cur] == -1)
        continue;

      int costDroite = 0;
      if (prendDroite) {
        assert(posPoints[apres[cur]] >= segments[i - prendDroite].second);
        costDroite = posPoints[apres[cur]] - segments[i - prendDroite].second;
      }
      int costGauche = minAvant;
      if (prendGauche) {
        int diffDroite =
            segments[cur + prendGauche - 1].first - posPoints[bef[cur]];
        costGauche = dpBef[0] + diffDroite;
        if (!cur or bef[cur] != apres[cur - 1])
          costGauche = minAvant + diffDroite;
        else {
          while (!hp2.empty() and hp2.top().first >= diffDroite) {
            auto [x, i] = hp2.top();
            hp2.pop();
            meilleur = min(meilleur, dpBef[i]);
          }
          while (!hp.empty() and hp.top().second >= diffDroite)
            hp.pop();
          costGauche = min({costGauche, meilleur + 2 * diffDroite,
                            hp.empty() ? INF : diffDroite + hp.top().first});
        }
      }
      curDp[prendDroite] = costDroite + costGauche;
    }
    cur = i;
    dpBef = move(curDp);
  }

  int ret = INF;
  for (int x : dpBef)
    ret = min(ret, x);
  cout << ret << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}