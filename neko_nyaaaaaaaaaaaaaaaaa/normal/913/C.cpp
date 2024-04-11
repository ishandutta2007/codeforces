#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	ll n, l;
	cin >> n >> l;
	vector<ll> c(n);
	for (int i = 0; i < n; i++) {
	      cin >> c[i];
	}
	for (int i = 1; i < n; i++) {
	      c[i] = min(c[i], 2*c[i-1]);
	}
	ll ans = 2e18;
      long long sum = 0;
      for (int i = n - 1; i >= 0; i--) {
            int need = l/(1 << i);
            sum += (long long) need * c[i];
            l -= need << i;
            ans = min(ans, sum + (l > 0) * c[i]);
      }
      cout << ans << endl;
      return 0;
      
}