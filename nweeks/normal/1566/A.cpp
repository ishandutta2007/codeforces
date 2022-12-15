#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, s;
  cin >> n >> s;
  int bef = (n + 1) / 2 - 1;
  int after = n - bef;
  cout << s / after << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}