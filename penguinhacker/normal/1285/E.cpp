#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, ans, cur, cnt[mxN], ft[2*mxN+1];
ar<int, 2> a[mxN];

void upd(int i, int x) {
	for (++i; i<=2*n; i+=i&-i)
		ft[i]+=x;
}

int qry(int i) {
	int r=0;
	for (++i; i; i-=i&-i)
		r+=ft[i];
	return r;
}

void solve() {
	cin >> n;
	ans=0, cur=0;
	vector<int> d;
	for (int i=0; i<n; ++i) {
		cin >> a[i][0] >> a[i][1];
		d.push_back(a[i][0]);
		d.push_back(a[i][1]);
	}
	sort(a, a+n);
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (int i=0; i<n; ++i) {
		a[i][0]=lower_bound(d.begin(), d.end(), a[i][0])-d.begin();
		a[i][1]=lower_bound(d.begin(), d.end(), a[i][1])-d.begin();
		cnt[i]=i-qry(a[i][0]-1);
		upd(a[i][1], 1);
		cur+=cnt[i]==0;
	}
	memset(ft, 0, 4*(2*n+1));
	for (int i=0; i<n; ++i)
		if (cnt[i]==1)
			upd(i, 1);
	for (int i=0; i<n; ++i) {
		int r=lower_bound(a, a+n, ar<int, 2>{a[i][1]+1})-a-1;
		ans=max(ans, cur-(cnt[i]==0)+qry(r)-qry(i));
	}
	memset(ft, 0, 4*(2*n+1));
	cout << ans << "\n";
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