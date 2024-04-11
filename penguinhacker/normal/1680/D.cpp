#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3000;
int n, k, a[mxN], fr[mxN+1];
ll ans, ps[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		fr[i+1]=fr[i]+(!a[i]);
		ps[i+1]=ps[i]+a[i];
	}
	if ((ll)fr[n]*k<abs(ps[n])) {
		cout << -1;
		return 0;
	}
	for (int rep=0; rep<2; ++rep) {
		// check max subarray [l, r]
		for (int i=0; i<n; ++i)
			for (int j=i; j<n; ++j) {
				ll x=fr[j+1]-fr[i];
				ll s=ps[j+1]-ps[i];
				ans=max(ans, min(s+x*k, -(ps[n]-s-(fr[n]-x)*k)));
			}
		for (int i=0; i<n; ++i) {
			ps[i+1]=-ps[i+1];
			a[i]*=-1;
		}
	}
	cout << ans+1;
	return 0;
}