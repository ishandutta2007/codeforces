#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      priority_queue<ll, vector<ll>, greater<ll>> pq;
      pq.push(100000000LL);

      ll ans = 0;
      while (n--) {
            ll x; cin >> x;
            if (pq.top() < x) {
                  ans -= pq.top();
                  ans += x;
                  pq.pop();
                  pq.push(x);
            }
            pq.push(x);
      }
      cout << ans;

      return 0;
}