/*
      https://codeforces.com/contest/478/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int r, g, h, M = 1e9+7;
      cin >> r >> g;
      if (r < g) swap(r, g);

      for (h = 1000; h*(h+1)/2 > r+g; h--);

      vector<int> dp(r+1, 0);
      dp[0] = dp[1] = 1;

      for (int i = 1; i < h; i++) {
            vector<int> tmp = dp;

            for (int j = i+1; j <= r; j++) {
                  tmp[j] = (tmp[j] + dp[j - i - 1]) % M;
            }

            swap(dp, tmp);
      }

      int ans = 0;
      for (int i = max(0, h*(h+1)/2 - g); i <= r; i++) {
            ans = (ans + dp[i]) % M;
      }
      cout << ans;

      return 0;
}