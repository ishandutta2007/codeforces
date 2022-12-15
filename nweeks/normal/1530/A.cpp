#include <bits/stdc++.h>
#include <limits>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int ret = 0;
  while (n) {
    ret = max(ret, n % 10);
    n /= 10;
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