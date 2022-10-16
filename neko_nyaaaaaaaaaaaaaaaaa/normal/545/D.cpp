#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n;
	cin >> n; 
	vector<ll> t(n);
	for (ll i = 0; i < n; i++) {
	      cin >> t[i];
	}
	ll ans = 0;
	ll ti = 0;
	sort(t.begin(), t.end());
	for (ll i = 0; i < n; i++) {
	      if (t[i] >= ti) {
	            ans++;
	            ti += t[i];
	      }
	}
	cout << ans;
	
	return 0;
}