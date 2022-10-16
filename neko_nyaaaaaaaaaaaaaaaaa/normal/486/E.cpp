#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }

      vector<int> lis;
      vector<int> dp(n);
      for (int i = 0; i < n; i++) {
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            if (it == lis.end()) {
                  lis.push_back(a[i]);
                  dp[i] = lis.size();
            } else {
                  *it = a[i];
                  dp[i] = it - lis.begin() + 1;
            }
      }

      lis.clear();
      for (int i = 0; i < n; i++) {
            a[i] *= -1;
      }
      vector<int> dp2(n);
      for (int i = n-1; i >= 0; i--) {
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            if (it == lis.end()) {
                  lis.push_back(a[i]);
                  dp2[i] = lis.size();
            } else {
                  *it = a[i];
                  dp2[i] = it - lis.begin() + 1;
            }
            dp[i] += dp2[i];
      }

      int k = *max_element(dp.begin(), dp.end());
      vector<int> freq(n+1);
      for (int i = 0; i < n; i++) {
            if (dp[i] == k) freq[dp2[i]]++;
      }

      for (int i = 0; i < n; i++) {
            if (dp[i] != k) cout << 1;
            else if (freq[dp2[i]] == 1) cout << 3;
            else cout << 2;
      }

	return 0;
}