#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k, r, c;
  cin >> n >> k >> r >> c;
  --r, --c;
  int x = (r + c) % k;
  for (int lig = 0; lig < n; ++lig) {
    for (int col = 0; col < n; ++col)
      cout << ((lig + col) % k == x ? 'X' : '.');
    cout << '\n';
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