#include <bits/stdc++.h>
#include <iomanip>
#define int long long
using namespace std;

void solve() {
  int W, H;
  cin >> W >> H;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int w, h;
  cin >> w >> h;
  bool ok = w + (x2 - x1) <= W or h + (y2 - y1) <= H;
  if (!ok) {
    cout << -1 << '\n';
    return;
  }

  int sol = 1e18;
  if (w + x2 - x1 <= W) {

    int minDx = 1e18;
    if (x1 >= w)
      minDx = 0;
    else
      minDx = w - x1;
    if (W - x2 >= w)
      minDx = 0;
    else
      minDx = min(minDx, abs(W - w - x2));
    sol = min(sol, minDx);
  }
  if (h + y2 - y1 <= H) {
    int minDy = 1e18;
    if (y1 >= h)
      minDy = 0;
    else
      minDy = h - y1;
    if (H - y2 >= h)
      minDy = 0;
    else
      minDy = min(minDy, abs(H - h - y2));
    sol = min(sol, minDy);
  }
  double ans = sol;
  cout << setprecision(12) << fixed << ans << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}