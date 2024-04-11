#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll n, ll x, ll y) {
      if (n == 1) return x;
      if (n == 0) return 0;

      if (n % 2) {
            ll ans = x + solve(n-1, x, y);
            ans = min(ans, x + solve(n+1, x, y));
            return ans;
      }

      ll ans = min(x*(n/2), y);
      return ans + solve(n/2, x, y);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      ll n, x, y; cin >> n >> x >> y;
      cout << solve(n, x, y);

	return 0;
}