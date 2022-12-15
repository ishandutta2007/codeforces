#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbCol;
  cin >> nbCol;
  string top, bot;
  cin >> top >> bot;

  auto solve1 = [](string s) -> int {
    int lst = -1;
    int ret = 0;
    for (char c : s) {
      if (c == '0') {
        if (lst == 1)
          ret += 2, lst = -1;
        else
          ret++, lst = 0;
      } else {
        if (lst == 0)
          ret++, lst = -1;
        else
          lst = 1;
      }
    }
    return ret;
  };
  string prv = "";
  int ret = 0;

  for (int iCol = 0; iCol < nbCol; ++iCol) {
    if (top[iCol] == bot[iCol])
      prv += top[iCol];
    else {
      ret += solve1(prv);
      prv = "";
      ret += 2;
    }
  }
  cout << ret + solve1(prv) << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}