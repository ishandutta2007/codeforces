#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;
int n;

void solve() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] < 0)
      a[i] = -a[i];
  }
  for (int mask = 1; mask < (1 << (2 * n)); ++mask) {
    bool ok = true;
    for (int i = 0; i < n; ++i)
      if (!((1 << (2 * i)) & mask) and ((1 << (2 * i + 1)) & mask))
        ok = false;
    if (!ok)
      continue;
    int s = 0;
    for (int i = 0; i < n; ++i)
      if ((1 << (2 * i) & mask)) {
        if ((1 << (2 * i + 1)) & mask)
          s += a[i];
        else
          s -= a[i];
      }
    if (!s) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}