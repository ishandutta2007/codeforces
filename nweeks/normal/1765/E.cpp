#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a <= b)
    cout << (n + a - 1) / a << '\n';
  else
    cout << 1 << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}