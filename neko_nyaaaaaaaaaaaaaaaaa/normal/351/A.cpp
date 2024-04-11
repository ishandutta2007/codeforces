#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int clc(string &s) {
      int c = 0;
      reverse(s.begin(), s.end());
      for (int i = 2; i >= 0; i--) {
            int t = s[i] - '0';
            c = c*10 + t;
      }
      return c;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, z = 0; cin >> n;
      vector<int> a;

      for (int i = 0; i < 2*n; i++) {
            string x; cin >> x;
            int k = clc(x);
            k %= 1000;

            if (k == 0) z++;
            else a.push_back(k);
      }
      sort(a.begin(), a.end());

      int ans = 1e9;
      for (int i = 0; i <= z && i <= n; ++i) {
		int tmp = 1000*(n-i);
		for (int j = 0; j < a.size(); ++j) {
			tmp -= a[j];
		}
		ans = min(ans, abs(tmp));
	}

      cout << fixed << setprecision(3) << (double)ans/1000;

      return 0;
}