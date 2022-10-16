#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll a, b, ans = 0;
	cin >> a >> b;
	ll dist = abs((b-a))/2;
	ll i;
	for (i = 1; i <= dist; i++) {
		ans += i*2;
	}
	if (abs(b-a)%2) {ans += i;}
	cout << ans;
	
	return 0;
}