#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, a[mxN], b[mxN+1], ans[mxN], ft[mxN+1];
vector<int> f[mxN+1];
vector<ar<int, 2>> v[mxN];

void upd(int i, int x) {
	for (++i; i<=n; i+=i&-i)
		ft[i]+=x;
}

int qry(int i) {
	int r=0;
	for (++i; i; i-=i&-i)
		r+=ft[i];
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=1; i<=mxN; ++i)
		for (int j=i; j<=mxN; j+=i)
			f[j].push_back(i);
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i], b[a[i]]=i;
	for (int i=0; i<m; ++i) {
		int l, r;
		cin >> l >> r, --l, --r;
		v[r].push_back({l, i});
	}
	for (int i=0; i<n; ++i) {
		for (int j : f[a[i]])
			if (b[j]<=i)
				upd(b[j], 1);
		for (int j=2*a[i]; j<=n; j+=a[i])
			if (b[j]<=i)
				upd(b[j], 1);
		for (ar<int, 2> q : v[i])
			ans[q[1]]=qry(i)-qry(q[0]-1);
	}
	for (int i=0; i<m; ++i)
		cout << ans[i] << "\n";
	return 0;
}