#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &v : arr)
    cin >> v;

  vector<tuple<int, int, int>> ops;
  for (int i(0); i < n; i += 2) {
    for (int k(0); k < 2; ++k) {
      ops.emplace_back(2, i + 1, i + 2);
      ops.emplace_back(1, i + 1, i + 2);
      ops.emplace_back(2, i + 1, i + 2);
    }
  }
  cout << ops.size() << endl;
  for (auto [a, b, c] : ops)
    cout << a << ' ' << b << ' ' << c << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}