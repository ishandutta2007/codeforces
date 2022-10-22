#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;

struct BIT {
	int ft[mxN+1];
	void upd(int i, int x) {
		for (++i; i<=mxN; i+=i&-i)
			ft[i]+=x;
	}
	int qry(int i) {
		int r=0;
		for (++i; i; i-=i&-i)
			r+=ft[i];
		return r;
	}
} ft1, ft2;

int n, q, a[mxN], bad[mxN], ans[mxN];
vector<ar<int, 2>> qry[mxN];
vector<int> oc[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], --a[i];
	cin >> q;
	for (int i=0; i<q; ++i) {
		int l, r;
		cin >> l >> r, --l, --r;
		qry[r].push_back({l, i});
	}
	memset(bad, -1, sizeof(bad));
	for (int i=0; i<n; ++i) {
		ft1.upd(i, 1);
		if (oc[a[i]].size())
			ft1.upd(oc[a[i]].back(), -1);
		oc[a[i]].push_back(i);
		if (oc[a[i]].size()>=3&&oc[a[i]].end()[-1]-oc[a[i]].end()[-2]!=oc[a[i]].end()[-2]-oc[a[i]].end()[-3]) {
			ft2.upd(oc[a[i]].end()[-3], 1);
			if (bad[a[i]]^-1)
				ft2.upd(bad[a[i]], -1);
			bad[a[i]]=oc[a[i]].end()[-3];
		}
		for (ar<int, 2> x : qry[i]) {
			int c=ft1.qry(i)-ft1.qry(x[0]-1);
			int d=ft2.qry(i)-ft2.qry(x[0]-1);
			ans[x[1]]=c+(c==d);
		}
	}
	for (int i=0; i<q; ++i)
		cout << ans[i] << "\n";
	return 0;
}