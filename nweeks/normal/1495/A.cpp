#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbPoints;
  cin >> nbPoints;
  vector<int> x, y;
  for (int i = 0; i < 2 * nbPoints; ++i) {
    int a, b;
    cin >> a >> b;
    a *= a, b *= b;
    if (a > 0)
      y.push_back(a);
    else
      x.push_back(b);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  double ret = 0;
  for (int i = 0; i < nbPoints; ++i) {
    ret += sqrt(x[i] + y[i]);
  }
  cout << setprecision(12) << fixed << ret << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}