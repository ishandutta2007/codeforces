#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, r, m;
	cin >> n >> a >> r >> m;
	m=min(m, a+r);
	vector<int> h(n);
	for (int& i : h)
		cin >> i;
	sort(h.begin(), h.end());
	ll s=accumulate(h.begin(), h.end(), 0ll);
	ll ans=(s-(ll)n*h[0])*r;
	ll p=0;
	for (int i=0; i<n; ++i) {
		// i+1 below
		// add (i+1)*x-prev sum
		// remove above sum-(n-i-1)*x
		// m*min(fa, fr)+a*(fa-min(fa, fr))+r*(fr-min(fa, fr))
		p+=h[i];

		auto ck=[&](ll x) {
			ll fa=(i+1)*x-p;
			ll fr=(s-p)-(n-i-1)*x;
			ll mn=min(fa, fr);
			ans=min(ans, m*mn+a*(fa-mn)+r*(fr-mn));
		};

		ck(h[i]);
		if (i+1<n) {
			ck(h[i+1]);
			ll fa1=(i+1)*1ll*h[i]-p;
			ll fr1=(s-p)-(n-i-1)*1ll*h[i];
			ll fa2=(i+1)*1ll*h[i+1]-p;
			ll fr2=(s-p)-(n-i-1)*1ll*h[i+1];
			if (fa1<fr1&&fa2>fr2) {
				ll dif=(fr1-fa1)/n;
				ck(h[i]+dif);
				if (h[i]+dif+1<h[i+1])
					ck(h[i]+dif+1);
			}
		}
	}
	cout << ans;
	return 0;
}