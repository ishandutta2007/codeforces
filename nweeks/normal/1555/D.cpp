#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  vector<int> cntOcc[3][3];
  for (int a = 0; a < 3; ++a)
    for (int b = 0; b < 3; ++b)
      cntOcc[a][b].resize(n);
  for (int i = 0; i < n; ++i) {
    if (i)
      for (int a = 0; a < 3; ++a)
        for (int j = 0; j < 3; ++j)
          cntOcc[a][j][i] = cntOcc[a][j][i - 1];
    cntOcc[i % 3][s[i] - 'a'][i]++;
  }

  while (m--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    vector<int> order = {0, 1, 2};
    int ret = 1e18;
    do {
      int cost = 0;
      for (int c = 0; c < 3; ++c)
        for (int d = 0; d < 3; ++d)
          if (order[c] != d)
            cost += cntOcc[c][d][r] - (l ? cntOcc[c][d][l - 1] : 0);
      ret = min(ret, cost);
    } while (next_permutation(order.begin(), order.end()));
    cout << ret << '\n';
  }
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests = 1;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}