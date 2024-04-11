#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      string s; cin >> s;
      int e = 0;
      for (int i = 0; i < n; i++) {
            e += (s[i] == '8');
      }
      int ans = n/11;
      ans = min(ans, e);
      cout << ans;

      return 0;
}