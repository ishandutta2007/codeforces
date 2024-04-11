#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
      ll n; cin >> n;
      ll ans = 0;
      for (ll i = 2; i <= n; i++) {
            ll k = n/i;
            ans += k*(k+1)/2 - 1;
      }
      cout << ans*4;
      
	return 0;
}