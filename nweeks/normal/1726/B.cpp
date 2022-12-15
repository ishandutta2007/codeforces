#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  if (n > m) {
    cout << "No\n";
    return;
  }
  if (n % 2 == 0) {
    if (m % 2) {
      cout << "No\n";
      return;
    }
    cout << "Yes\n";
    for (int i = 0; i < n - 2; ++i)
      cout << 1 << ' ';
    cout << (m - (n - 2)) / 2 << ' ' << (m - (n - 2)) / 2 << '\n';
  } else {
    cout << "Yes\n";
    for (int i = 0; i < n - 1; ++i)
      cout << 1 << ' ';
    cout << (m - (n - 1)) << '\n';
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