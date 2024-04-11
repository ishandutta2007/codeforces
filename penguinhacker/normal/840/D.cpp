#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, q, a[mxN], ans[mxN], cnt[mxN];
ar<int, 3> qry[mxN];
ar<int, 4> tb[mxN];
vector<int> oc[mxN];

void add(int id, int x) {
	for (int i=0; i<4; ++i) {
		if (tb[id][i]==x)
			return;
		if (tb[id][i]==-1) {
			tb[id][i]=x;
			return;
		}
	}
	assert(0);
}

void solve(int l, int r, vector<int> v) {
	if (v.empty())
		return;
	int mid=(l+r)/2;
	memset(tb+l, -1, (r-l+1)*sizeof(tb[0]));
	for (int i=mid; i>=l; --i) {
		int ts=(mid-i+1)/5+1; // threshold
		if (++cnt[a[i]]>=ts)
			add(i, a[i]);
		if (i<mid)
			for (int j=0; j<4; ++j)
				if (tb[i+1][j]^-1&&cnt[tb[i+1][j]]>=ts)
					add(i, tb[i+1][j]);
	}
	for (int i=l; i<=mid; ++i)
		--cnt[a[i]];
	for (int i=mid+1; i<=r; ++i) {
		int ts=(i-mid)/5+1; // threshold
		if (++cnt[a[i]]>=ts)
			add(i, a[i]);
		if (i>mid+1)
			for (int j=0; j<4; ++j)
				if (tb[i-1][j]^-1&&cnt[tb[i-1][j]]>=ts)
					add(i, tb[i-1][j]);
	}
	for (int i=mid+1; i<=r; ++i)
		--cnt[a[i]];
	vector<int> vl, vr;
	for (int i : v) {
		int ql=qry[i][0], qr=qry[i][1], k=qry[i][2];
		if (qr<=mid)
			vl.push_back(i);
		else if (ql>mid)
			vr.push_back(i);
		else {
			ans[i]=-1;
			auto Check=[&](int x) {
				int cnt=upper_bound(oc[x].begin(), oc[x].end(), qr)-lower_bound(oc[x].begin(), oc[x].end(), ql);
				if (cnt>=(qr-ql+1)/k+1)
					if (ans[i]==-1||x<ans[i])
						ans[i]=x;
			};
			for (int i=0; i<4; ++i) {
				if (tb[ql][i]^-1)
					Check(tb[ql][i]);
				if (tb[qr][i]^-1)
					Check(tb[qr][i]);
			}
		}
	}
	solve(l, mid, vl);
	solve(mid+1, r, vr);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		oc[a[i]].push_back(i);
	}
	vector<int> v;
	for (int i=0; i<q; ++i) {
		cin >> qry[i][0] >> qry[i][1] >> qry[i][2], --qry[i][0], --qry[i][1];
		if (qry[i][0]==qry[i][1])
			ans[i]=a[qry[i][0]];
		else
			v.push_back(i);
	}
	solve(0, n-1, v);
	for (int i=0; i<q; ++i)
		cout << (ans[i]^-1?ans[i]+1:-1) << "\n";
	return 0;
}