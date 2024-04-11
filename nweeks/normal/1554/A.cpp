#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int ret = 0;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 1; i < n; ++i)
    ret = max(ret, a[i - 1] * a[i]);
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