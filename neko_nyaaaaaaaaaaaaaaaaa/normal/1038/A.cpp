#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      map<char, int> m;
      int n, k; cin >> n >> k;
      string s; cin >> s;
      for (int i = 0; i < n; i++) {
            m[s[i]]++;
      }

      int ans = n;
      for (int i = 'A'; i < 'A' + k; i++) {
            ans = min(ans, m[i]);
      }

      cout << ans*k;

	return 0;
}