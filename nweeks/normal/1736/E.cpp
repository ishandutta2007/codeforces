#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
const int MAXN = 501;

array<array<int, MAXN>, MAXN> oldDp, curDp, prefDp;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> vec(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> vec[i];

  for (int i = 0; i < MAXN; ++i)
    for (int j = 0; j < MAXN; ++j)
      oldDp[i][j] = -INF;
  oldDp[0][2] = vec[2];
  oldDp[1][1] = vec[1];
  for (int i = 2; i <= n; ++i) {
    for (int swaps = 0; swaps <= n; ++swaps) {
      prefDp[swaps][0] = oldDp[swaps][0];
      for (int x = 1; x <= n; ++x)
        prefDp[swaps][x] = max(prefDp[swaps][x - 1], oldDp[swaps][x]);
    }

    for (int swaps = 0; swaps <= n; ++swaps) {
      for (int lst = 0; lst <= n; ++lst) {
        int &cur = curDp[swaps][lst];
        cur = -INF;
        cur = max(cur, vec[lst] + oldDp[swaps][lst]);
        if (lst >= i and swaps + (lst - i) - 1 >= 0 and
            swaps + (lst - i) - 1 <= n)
          cur = max(cur, vec[lst] + prefDp[swaps + (lst - i) - 1][lst - 1]);
      }
    }
    for (int j = 0; j <= n; ++j)
      for (int k = 0; k <= n; ++k)
        oldDp[j][k] = curDp[j][k];
  }
  int ret = 0;
  for (int swaps = 0; swaps <= n; ++swaps)
    for (int lst = 0; lst <= n; ++lst)
      ret = max(ret, curDp[swaps][lst]);
  cout << ret << endl;
}