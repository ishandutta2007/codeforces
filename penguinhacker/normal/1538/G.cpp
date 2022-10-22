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
		if (x>y)
			swap(x, y);
		if (a>b)
			swap(a, b);
		if (y*a>=x*b) {
			cout << x/a << "\n";
			continue;
		}
		int lb=0, rb=min(y/b, x/a);
		int ans=rb;
		auto Check=[&](ll t) {
			ll tx=x-t*a, ty=y-t*b;
			if (t<0||tx<0||ty<0)
				return -1;
			return (int)(t+min(tx/b, ty/a));
		};
		while(lb<rb) {
			int mid=(lb+rb)/2;
			ll nx=x-a*mid, ny=y-b*mid;
			if (nx*a>=ny*b)
				rb=mid;
			else
				lb=mid+1;
		}
		for (int i=-2; i<=2; ++i)
			ans=max(ans, Check(lb+i));
		cout << ans << "\n";
	}
	return 0;
}