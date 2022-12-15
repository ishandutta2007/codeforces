#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int &v : x)
    cin >> v;

  int s = 0;
  for (int v : x)
    s += v;

  bool isComp = false;
  for (int d = 2; d < s; ++d)
    if (s % d == 0)
      isComp = true;

  if (isComp) {
    cout << n << '\n';
    for (int i = 0; i < n; ++i)
      cout << i + 1 << ' ';
    cout << '\n';
  } else {
    cout << n - 1 << '\n';
    bool found = false;
    for (int i = 0; i < n; ++i) {
      if (x[i] % 2 and !found) {
        found = true;
      } else
        cout << i + 1 << ' ';
    }
    cout << '\n';
    assert(found);
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