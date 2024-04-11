#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

const int INF = 1e9;

int n, dif, majority, a[200000], ls[200001], rs[200001]; //dif is #(stawberry-blueberry)

void init() {
	cin >> n;
	dif=0;
	for (int i=0; i<2*n; ++i) {
		cin >> a[i];
		if (a[i]==1)
			dif++;
		else
			dif--;
	}
	if (dif>0)
		majority=1;
	else if (dif<0)
		majority=2;
	dif = abs(dif);
	for (int i=1; i<=200000; ++i) {
		ls[i]=INF;
		rs[i]=INF;
	}
	ls[0]=0;
	rs[0]=0;
}

void solve() {
	init();
	if (dif==0) {
		cout << 0 << '\n';
		return;
	}
	int best = 2*n;
	int ldif = 0;
	int rdif = 0;
	for (int i=n-1; i>=0; --i) {
		if (a[i] == majority)
			ldif++;
		else
			ldif--;
		if (ldif <= 0)
			continue;
		ls[ldif] = min(ls[ldif], n-i);
	}
	for (int i=n; i<2*n; ++i) {
		if (a[i] == majority)
			rdif++;
		else
			rdif--;
		if (rdif <= 0)
			continue;
		rs[rdif] = min(rs[rdif], i-n+1);
	}
	for (int i=0; i<=dif; ++i) {
		best = min(best, ls[i]+rs[dif-i]);
	}
	cout << best << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}