#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXP = 30;

int sol[MAXP];

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbSegments;
  cin >> nbSegments;
  vector<pair<int, int>> segments(nbSegments);

  for (auto &[deb, fin] : segments)
    cin >> deb >> fin;

  for (int bit = 0; bit < MAXP; ++bit) {
    int p = 1 << bit;

    vector<pair<int, int>> events;
    for (auto [deb, fin] : segments) {
      if (fin - deb + 1 >= p) {
        events.emplace_back(0, 1);
        events.emplace_back(p, -1);
        continue;
      }
      deb %= p;
      fin %= p;
      if (deb <= fin) {
        events.emplace_back(deb, 1);
        events.emplace_back(fin + 1, -1);
      } else {
        events.emplace_back(deb, 1);
        events.emplace_back(p, -1);
        events.emplace_back(0, 1);
        events.emplace_back(fin + 1, -1);
      }
    }
    sort(events.begin(), events.end());

    int cur = 0;
    for (auto [pos, delta] : events) {
      cur += delta;
      sol[bit] = max(sol[bit], cur);
    }
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int W;
    cin >> W;
    int bit = 0;
    while (!((1 << bit) & W))
      ++bit;
    cout << sol[bit] << '\n';
  }
}