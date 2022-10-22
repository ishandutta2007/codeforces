#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, B=400;
int n, k, q, t[mxN], a[mxN], prv[mxN+1], nxt[mxN+1], cnt[3*mxN+3];
ll p[mxN+1], ans[mxN], cur;
vector<ll> d;
ar<int, 3> qs[mxN];

int get(ll x) {
	return lower_bound(d.begin(), d.end(), x)-d.begin();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> t[i];
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		p[i+1]=p[i]+(t[i]==1?a[i]:-a[i]);
	for (int i=0; i<=n; ++i) {
		d.push_back(p[i]);
		d.push_back(p[i]+k);
		d.push_back(p[i]-k);
	}
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (int i=0; i<=n; ++i) {
		prv[i]=get(p[i]-k);
		nxt[i]=get(p[i]+k);
		p[i]=get(p[i]);
	}
	cin >> q;
	for (int i=0; i<q; ++i) {
		int l, r;
		cin >> l >> r, --l;
		qs[i]={l, r, i};
	}
	sort(qs, qs+q, [](ar<int, 3> x, ar<int, 3> y) {
			return x[0]/B^y[0]/B?x[0]/B<y[0]/B:x[1]<y[1];
		});
	for (int i=0, l=0, r=0; i<q; ++i) {
		int ql=qs[i][0], qr=qs[i][1];
		while(l>ql) {
			cur+=cnt[nxt[--l]];
			++cnt[p[l]];
		}
		while(r<=qr) {
			cur+=cnt[prv[r]];
			++cnt[p[r++]];
		}
		while(l<ql) {
			--cnt[p[l]];
			cur-=cnt[nxt[l++]];
		}
		while(r>qr+1) {
			--cnt[p[--r]];
			cur-=cnt[prv[r]];
		}
		ans[qs[i][2]]=cur;
	}
	for (int i=0; i<q; ++i)
		cout << ans[i] << "\n";
	return 0;
}