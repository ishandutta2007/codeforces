#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  bool res = false;
  __int128 cur = 1;
  while (cur <= n) {
    if ((n - cur) % b == 0)
      res = true;
    cur *= a;
    if (a == 1)
      break;
  }
  cout << (res ? "Yes" : "No") << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}