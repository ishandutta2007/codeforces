#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int ret = 1e18;
  for (int a = 0; a < 4; ++a)
    for (int b = 0; b < 5; ++b) {
      int lft = n - 6 * a - 8 * b;
      int cst = a * 15 + b * 20;
      if (lft > 0)
        cst += ((lft + 9) / 10) * 25;
      ret = min(ret, cst);
    }
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