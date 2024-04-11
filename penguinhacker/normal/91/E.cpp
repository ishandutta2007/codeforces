#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, q, ans[mxN];
ll a[mxN], b[mxN];
vector<int> st[1<<18];
vector<ar<int, 2>> qry[1<<18];

ll e(int i, int t) {
	return a[i]+b[i]*t;
}

ll ix(int i, int j) {
	assert(b[i]<b[j]);
	ll x=a[i]-a[j], y=b[j]-b[i];
	return x>=0?(x+y-1)/y:x/y;
}

void add(int ql, int qr, ar<int, 2> x, int u=1, int l=0, int r=n-1) {
	if (ql<=l&&r<=qr) {
		qry[u].push_back(x);
		return;
	}
	int mid=(l+r)/2;
	if (ql<=mid)
		add(ql, qr, x, 2*u, l, mid);
	if (qr>mid)
		add(ql, qr, x, 2*u+1, mid+1, r);
}

void dfs(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st[u]={l};
	} else {
		int mid=(l+r)/2;
		dfs(2*u, l, mid);
		dfs(2*u+1, mid+1, r);
		st[u].resize(r-l+1);
		merge(st[2*u].begin(), st[2*u].end(), st[2*u+1].begin(), st[2*u+1].end(), st[u].begin(), [](int i, int j) { return b[i]^b[j]?b[i]<b[j]:a[i]<a[j]; });
	}
	deque<int> hull;
	for (int i : st[u]) {
		while(hull.size()&&b[i]==b[hull.back()]||hull.size()>=2&&ix(hull.back(), i)<=ix(hull.end()[-2], hull.back()))
			hull.pop_back();
		hull.push_back(i);
	}
	sort(qry[u].begin(), qry[u].end());
	for (auto [t, i] : qry[u]) {
		while(hull.size()>=2&&e(hull[1], t)>=e(hull[0], t))
			hull.pop_front();
		if (ans[i]==-1||e(hull[0], t)>e(ans[i], t))
			ans[i]=hull[0];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<n; ++i)
		cin >> a[i] >> b[i];
	for (int i=0; i<q; ++i) {
		ans[i]=-1;
		int ql, qr, t;
		cin >> ql >> qr >> t, --ql, --qr;
		add(ql, qr, {t, i});
	}
	dfs();
	for (int i=0; i<q; ++i)
		cout << ans[i]+1 << "\n";
	return 0;
}