#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

ll a[3], ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	if (a[0]!=0&&a[2]<2*(a[0]+a[1])) {
		ll x = min(a[0], (2*(a[0]+a[1])-a[2]+2)/3);
		a[0] -= x;
		a[1] -= x;
		a[2] -= x;
		ans += x;
	}
	if (a[0]==0) {
		if (a[2] >= 2*a[1])
			ans += a[1];
		else
			ans += (a[1]+a[2])/3;
	}
	else
		ans += a[0]+a[1];
	cout << ans;
	return 0;
}