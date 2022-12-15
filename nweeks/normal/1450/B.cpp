#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve() {
  int nbPoints, dis;
  cin >> nbPoints >> dis;
  vector<pair<int, int>> points(nbPoints);
  for (auto &[x, y] : points)
    cin >> x >> y;
  sort(points.begin(), points.end());
  points.resize(unique(points.begin(), points.end()) - points.begin());
  nbPoints = points.size();
  if (nbPoints <= 1)
    return 0;

  for (int iPoint = 0; iPoint < nbPoints; ++iPoint) {
    bool ok = true;
    for (int i = 0; i < nbPoints; ++i) {
      ok &= abs(points[iPoint].first - points[i].first) +
                abs(points[iPoint].second - points[i].second) <=
            dis;
    }
    if (ok)
      return 1;
  }
  return -1;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    cout << solve() << '\n';
}