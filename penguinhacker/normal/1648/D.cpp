#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
const ll INF=1e18;
int n, m, a[mxN][3];
ll p[mxN+1][3], val[mxN], dp[mxN], st[mxN], best_l[mxN], best_r[mxN]; // st stores random stuff i want
vector<ar<int, 2>> qry[mxN];
vector<ll> todo[mxN];

void solve(vector<ar<int, 3>> v, int l=0, int r=n-1) {
	if (v.empty()) return;
	if (l==r) {
		for (auto x : v) dp[l]=max(dp[l], val[l]-x[2]);
		return;
	}
	vector<ar<int, 3>> vl, vr, vm;
	int mid=(l+r)/2;
	for (auto [ql, qr, c] : v) {
		if (qr<=mid) vl.push_back({ql, qr, c});
		else if (ql>mid) vr.push_back({ql, qr, c});
		else vm.push_back({ql, qr, c});
	}
	solve(vl, l, mid), solve(vr, mid+1, r);
	if (vm.size()) {
		for (int i=l; i<=r; ++i) st[i]=best_l[i]=best_r[i]=-INF;
		for (auto [ql, qr, c] : vm) {
			assert(l<=ql&&ql<=mid&&mid<qr&&qr<=r);
			st[ql]=max(st[ql], -1ll*c);
			st[qr]=max(st[qr], -1ll*c);
		}
		for (int i=r-1; i>mid; --i)
			st[i]=max(st[i], st[i+1]);
		ll best=-INF, best_c=-INF;
		for (int i=l; i<=mid; ++i) { // solve left side
			best_c=max(best_c, st[i]);
			best=max(best, val[i]+best_c);
			dp[i]=max(dp[i], best);
		}
		best=-INF;
		for (int i=mid+1; i<=r; ++i) { // solve right side
			best=max(best, val[i]);
			dp[i]=max(dp[i], best+st[i]);
		}
		// do both
		for (int i=mid; i>=l; --i)
			best_l[i]=max(val[i], i<mid?best_l[i+1]:-INF);
		for (auto [ql, qr, c] : vm)
			best_r[qr]=max(best_r[qr], best_l[ql]-c);
		for (int i=r; i>mid; --i) {
			if (i<r) best_r[i]=max(best_r[i], best_r[i+1]);
			dp[i]=max(dp[i], best_r[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int j : {0, 1, 2})
		for (int i=0; i<n; ++i) {
			cin >> a[i][j];
			p[i+1][j]=p[i][j]+a[i][j];
		}
	for (int i=0; i<n; ++i) {
		dp[i]=-INF;
		val[i]=p[i+1][0]-p[i][1];
	}
	vector<ar<int, 3>> v;
	for (int i=0; i<m; ++i) {
		int l, r, c;
		cin >> l >> r >> c, --l, --r;
		v.push_back({l, r, c});
		qry[l].push_back({r, c});
		/*ll best=-INF;
		for (int j=l; j<=r; ++j) {
			best=max(best, val[j]);
			dp[j]=max(dp[j], best-c);
		}*/
	}
	solve(v);
	/*for (int i=0; i<n; ++i)
		cout << dp[i] << "\n";
	return 0;*/
	ll ans=-INF;
	/*for (int i=0; i<n-1; ++i)
		for (auto [r, c] : qry[i+1])
			for (int j=i+1; j<=r; ++j)
				dp[j]=max(dp[j], dp[i]-c);*/
	multiset<ll> active;
	for (int i=0; i<n; ++i) {
		if (active.size()) dp[i]=max(dp[i], *active.rbegin());
		if (i+1<n) {
			for (auto [r, c] : qry[i+1]) {
				active.insert(dp[i]-c);
				todo[r].push_back(dp[i]-c);
			}
		}
		for (ll x : todo[i]) active.erase(active.find(x));
	}
	for (int i=0; i<n; ++i)
		ans=max(ans, dp[i]+p[i+1][1]+p[n][2]-p[i][2]);
	cout << ans;
	return 0;
}