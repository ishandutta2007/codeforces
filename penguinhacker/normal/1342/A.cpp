#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x<y)
			swap(x, y); //x>=y
		if (y==0)
			cout << 1ll*a*x << '\n';
		else
			cout << min(a*(x+y), b*y+(x-y)*a) << '\n';
	}
	return 0;
}