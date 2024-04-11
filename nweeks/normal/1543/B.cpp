#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    tot += a[i];
  }
  int res = tot % n;
  cout << res * (n - res) << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}