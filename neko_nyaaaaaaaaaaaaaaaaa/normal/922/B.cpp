#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll ans = 0;
	ll n;
	cin >> n;
	for (ll a = 1; a <= n; a++) {
		for (ll b = a; b <= n; b++) {
			ll c = a^b;
			if (c <= n && c < (a+b) && c > a && c > b) {ans++;}
		}
	}
	cout << ans;
	
	
	return 0;
}