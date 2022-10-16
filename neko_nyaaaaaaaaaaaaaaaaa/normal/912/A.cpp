#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll a, b, x, y, z;
	cin >> a >> b >> x >> y >> z;
	ll aneed = 2*x + y;
	ll bneed = 3*z + y;
	ll ans = 0;
	if (aneed > a) {ans += (aneed - a);}
	if (bneed > b) {ans += (bneed - b);}
	cout << ans;
	
	return 0;
}