#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll M = 1e9+7;

vector<int> dv(int x, int n) {
      vector<int> ans;
      for (int i = 1; i <= n && i*i <= x; i++) {
            if (x % i == 0) {
                  int a = x/i;
                  int b = x/a;

                  if (a <= n) ans.push_back(a);
                  if (a != b && b <= n) ans.push_back(b);
            }
      }
      return ans;
}

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      vector<ll> dp(100001);
      int n; cin >> n;
      for (int i = 1; i <= n; i++) {
            int x; cin >> x;

            vector<int> c = dv(x, n);
            sort(c.begin(), c.end(), greater<int>());
            //cout << c << endl;
            for (int j: c) {
                  if (j == 1) {dp[j]++; continue;}
                  dp[j] += dp[j-1];
                  dp[j] %= M;
            }
      }

      ll ans = 0;
      for (ll i: dp) ans = (ans + i) % M;
      cout << ans;

      return 0;
}