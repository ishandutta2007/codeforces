#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  set<int> neverMid;
  for (int i = 0; i < n; ++i)
    neverMid.insert(i);
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    neverMid.erase(b - 1);
  }
  int center = *neverMid.begin();
  for (int i = 0; i < n; ++i)
    if (i != center)
      cout << i + 1 << ' ' << center + 1 << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}