#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[1000], b[1000], c[2000];

bool ok(double x) {
	for (int i=0; i<n; ++i) {
		double need=(x+m)/c[i];
		if (need>x)
			return 0;
		x-=need;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	c[0]=a[0];
	for (int i=1; i<n; ++i)
		c[2*i-1]=b[i], c[2*i]=a[i];
	c[2*n-1]=b[0];
	n*=2;

	double l=0, r=1e9+10;
	while(r-l>1e-9) {
		double mid=(l+r)/2;
		if (ok(mid))
			r=mid;
		else
			l=mid;
	}
	if (l>1e9+1)
		cout << -1;
	else
		cout << fixed << setprecision(10) << l;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/