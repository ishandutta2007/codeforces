#include <bits/stdc++.h>
using namespace std;

void Main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(3, -2)));
  function<int(int, int, int)> DP = [&](int l, int r, int whichislast) {
    int last = whichislast == 0   ? 0
               : whichislast == 1 ? (s[l - 1] - 'a' + 1)
                                  : (s[r + 1] - 'a' + 1);
    if (l == r) {
      int val = s[l] - 'a' + 1;
      if (last > val)
        return 1;
      else if (last < val)
        return -1;
      else
        return 0;
    }
    if (dp[l][r][whichislast] != -2) {
      return dp[l][r][whichislast];
    }
    if (last != 0) {
      int z = -2;
      int val = s[l] - 'a' + 1;

      int one = DP(l + 1, r, 0);
      if (one == 0) {
        if (last > val)
          z = max(z, 1);
        else if (last < val)
          z = max(z, -1);
        else
          z = max(z, 0);
      } else {
        z = max(z, one);
      }

      val = s[r] - 'a' + 1;
      one = DP(l, r - 1, 0);
      if (one == 0) {
        if (last > val)
          z = max(z, 1);
        else if (last < val)
          z = max(z, -1);
        else
          z = max(z, 0);
      } else {
        z = max(z, one);
      }
      return dp[l][r][whichislast] = z;
    } else {
      return dp[l][r][whichislast] = min(DP(l + 1, r, 1), DP(l, r - 1, 2));
    }
  };
  int z = DP(0, n - 1, 0);
  if (z == 1)
    cout << "Bob\n";
  else if (z == -1)
    cout << "Alice\n";
  else
    cout << "Draw\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
}