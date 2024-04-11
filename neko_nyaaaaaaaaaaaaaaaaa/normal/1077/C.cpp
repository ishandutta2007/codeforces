#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<ll> a(n);
      multiset<ll> s;
      ll sum = 0;
      for (int i = 0; i < n; i++) {
            cin >> a[i]; s.insert(a[i]);
            sum += a[i];
      }

      vector<int> ans;
      for (int i = 0; i < n; i++) {
            s.erase(s.find(a[i]));
            sum -= a[i];

            if (*s.rbegin() == sum/2 && sum % 2 == 0) {
                  ans.push_back(i+1);
            }

            s.insert(a[i]);
            sum += a[i];
      }

      cout << ans.size() << '\n';
      for (int i: ans) cout << i << ' ';

      return 0;
}