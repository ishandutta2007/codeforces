#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);
      srand(time(NULL));

      int n; cin >> n;
      string a, b; cin >> a >> b;
      a.push_back(' ');
      b.push_back(' ');
      int i = 0;
      int ans = 0;
      for (; i < n; i++) {
            if (a[i] != b[i]) {
                  ans++;
                  if (a[i] != a[i+1] && a[i+1] != b[i+1]) i++;
            }
      }
      cout << ans;

      return 0;
}