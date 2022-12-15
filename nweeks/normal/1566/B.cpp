#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.size();

  int ret = 2;
  if (s == string(n, '1'))
    ret = 0;
  else {
    int fst0 = 0;
    while (s[fst0] == '1')
      fst0++;
    int lst0 = n - 1;
    while (s[lst0] == '1')
      --lst0;
    bool ok = true;
    for (int i = fst0; i < lst0; ++i)
      ok &= s[i] == '0';
    if (ok)
      ret = 1;
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