#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	ll n;
	cin >> n;
	vector<ll> u(n+1), v(n+1), a(n+1), b(n+1);
	for (ll i = 1; i <= n; i++) {
	      cin >> u[i];
	      v[i] = u[i];
	}
	sort(v.begin(), v.end());
	for (ll i = 1; i <= n; i++) {
	      a[i] = a[i-1] + u[i];
	      b[i] = b[i-1] + v[i];
	}
	ll m;
	cin >> m;
	while (m--) {
	      ll t, x, y;
	      cin >> t >> x >> y;
	      if (t == 1) {
	            cout << a[y] - a[x-1] << endl;
	      } else {
	            cout << b[y] - b[x-1] << endl;
	      }
	}
	
	return 0;
}