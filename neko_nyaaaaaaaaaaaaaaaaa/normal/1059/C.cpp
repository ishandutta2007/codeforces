#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> ans;
      int left = n;
      for (int i = 1; i <= n; i *= 2) {
            if (left == 3) {
                  ans.push_back(i);
                  ans.push_back(i);
                  ans.push_back(i*3);

                  break;
            }

            for (int j = i; j <= n; j += i*2) {
                  ans.push_back(i);
                  left--;
            }
      }

      for (int i: ans) cout << i << " ";

	return 0;
}