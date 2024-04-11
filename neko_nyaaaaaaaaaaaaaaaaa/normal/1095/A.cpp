#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      string s; cin >> s;
      for (int i = 0, j = 1; i < n; i += j, j++) {
            cout << s[i];
      }

	return 0;
}