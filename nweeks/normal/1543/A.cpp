#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << "0 0\n";
  } else {
    if (a > b)
      swap(a, b);
    int sol = b - a;
    // k * (b-a) >= a
    int k1 = (a + b - a - 1) / (b - a);
    int minDiff = k1 * (b - a) - a;
    if (k1 > 0)
      minDiff = min(minDiff, a - (k1 - 1) * (b - a));
    cout << sol << ' ' << minDiff << '\n';
  }
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}