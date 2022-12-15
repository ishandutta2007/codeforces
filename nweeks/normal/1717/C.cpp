#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      cout << "NO\n";
      return;
    }
    if (a[i] != b[i] and b[i] > b[(i + 1) % n] + 1) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}