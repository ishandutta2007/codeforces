#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, x;
ll dp[5008][5008];
ll a[5008];

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> k >> x;
      if (n > k*(x+1) - 1) {cout << -1; return 0;}
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
      }

      for (int j = 1; j <= x; j++) {

            deque<ll> dq;
            for (int i = max(0, j - k); i < j; i++) {
                  while (!dq.empty() && dp[i][j-1] >= dp[dq.back()][j-1]) {
                        dq.pop_back();
                  }
                  dq.push_back(i);
            }

            for (int i = j; i <= min(n, j*k); i++) {
                  dp[i][j] = a[i] + dp[dq.front()][j-1];

                  while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
                  while (!dq.empty() && dp[i][j-1] >= dp[dq.back()][j-1]) dq.pop_back();

                  dq.push_back(i);
            }
      }

//      for (int i = 1; i <= x; i++) {
//            for (int j = 1; j <= n; j++) {
//                  cout << dp[j][i] << ' ';
//            }
//            cout << endl;
//      }

      ll ans = 0;
      int left = n-k+1;
      int right = min(n, x*k);

      for (int i = left; i <= right; i++) {
            ans = max(ans, dp[i][x]);
      }
      cout << ans;

      return 0;
}