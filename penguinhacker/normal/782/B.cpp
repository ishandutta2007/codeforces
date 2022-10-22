#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
double x[60000], v[60000];
bool ok(double t) {
	double lb=-1e18, rb=1e18;
	for (int i=0; i<n; ++i)
		lb=max(lb, x[i]-t*v[i]), rb=min(rb, x[i]+t*v[i]);
	return lb<=rb;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x[i];
	for (int i=0; i<n; ++i)
		cin >> v[i];
	double l=0, r=1e9;
	while(l+1e-7<r) {
		double mid=(l+r)/2;
		if (ok(mid)) r=mid;
		else l=mid;
	}
	cout << fixed << setprecision(7) << l;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/