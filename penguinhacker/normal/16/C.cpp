#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int gcd(int x, int y) {
	if (x<y)
		swap(x, y);
	if (x%y==0)
		return y;
	return gcd(y, x%y);
}

int a, b, x, y;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> x >> y;
	int k=gcd(x, y);
	x/=k, y/=k;
	ll l=0, r=2e9+5;
	while (l<r) {
		ll mid=(l+r+1)/2;
		if (a>=mid*x&&b>=mid*y)
			l=mid;
		else
			r=mid-1;
	}
	cout << x*l << ' ' << y*l;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/