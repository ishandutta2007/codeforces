#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, m, dp[mxN], last[mxN];
vector<ar<int, 2>> seg[mxN];
vector<int> d;
ar<int, 2> st[1<<21], st2[1<<21];
bool vis[mxN];

void upd(int ql, int qr, ar<int, 2> x, int u=1, int l=0, int r=d.size()-1) {
	if (ql<=l&&r<=qr) {
		st[u]=max(st[u], x);
		st2[u]=max(st2[u], x);
		return;
	}
	int mid=(l+r)/2;
	if (ql<=mid)
		upd(ql, qr, x, 2*u, l, mid);
	if (qr>mid)
		upd(ql, qr, x, 2*u+1, mid+1, r);
	st2[u]=max(st[u], max(st2[2*u], st2[2*u+1]));
}

ar<int, 2> qry(int ql, int qr, int u=1, int l=0, int r=d.size()-1) {
	if (ql<=l&&r<=qr)
		return st2[u];
	int mid=(l+r)/2;
	ar<int, 2> ls=ql<=mid?qry(ql, qr, 2*u, l, mid):ar<int, 2>{};
	ar<int, 2> rs=qr>mid?qry(ql, qr, 2*u+1, mid+1, r):ar<int, 2>{};
	return max(st[u], max(ls, rs));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int j, l, r;
		cin >> j >> l >> r, --j, --l, --r;
		seg[j].push_back({l, r});
		d.push_back(l);
		d.push_back(r);
	}
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (int i=0; i<n; ++i) {
		dp[i]=1, last[i]=-1;
		for (auto& [l, r] : seg[i]) {
			l=lower_bound(d.begin(), d.end(), l)-d.begin();
			r=lower_bound(d.begin(), d.end(), r)-d.begin();
			ar<int, 2> cur=qry(l, r);
			if (cur[0]+1>dp[i])
				dp[i]=cur[0]+1, last[i]=cur[1];
		}
		for (auto [l, r] : seg[i])
			upd(l, r, {dp[i], i});
	}
	int pos=max_element(dp, dp+n)-dp;
	cout << n-dp[pos] << "\n";
	for (; pos!=-1; pos=last[pos])
		vis[pos]=1;
	for (int i=0; i<n; ++i)
		if (!vis[i])
			cout << i+1 << " ";
	return 0;
}