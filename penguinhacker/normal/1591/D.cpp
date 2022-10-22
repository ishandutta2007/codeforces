#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n, a[mxN], cnt[mxN], ft[mxN+1];

void upd(int i) {
	for (++i; i<=n; i+=i&-i)
		++ft[i];
}

int qry(int i) {
	int r=0;
	for (++i; i; i-=i&-i)
		r+=ft[i];
	return r;
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		cnt[i]=0;
	}
	if (n==1) {
		cout << "YES\n";
		return;
	}
	if (n==2) {
		cout << (a[0]<=a[1]?"YES":"NO") << "\n";
		return;
	}
	for (int i=0; i<n; ++i)
		++cnt[a[i]];
	for (int i=0; i<n; ++i)
		if (cnt[i]>1) {
			cout << "YES\n";
			return;
		}
	// permutation [1, n] n>=3
	memset(ft, 0, 4*(n+1));
	ll inv=0;
	for (int i=0; i<n; ++i) {
		inv+=i-qry(a[i]);
		upd(a[i]);
	}
	cout << (inv%2?"NO":"YES") << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}