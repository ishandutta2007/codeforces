#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int d[1000001];
void gen() {
	for (int i=1; i<=1000000; ++i)
		for (int j=i; j<=1000000; j+=i)
			++d[j];
}

const int mxN=300000;
int n, m, a[mxN];
set<int> s;

ll st[4*mxN];
void build(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st[u]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*u, l, mid);
	build(2*u+1, mid+1, r);
	st[u]=st[2*u]+st[2*u+1];
}
vector<int> to_erase;
void upd(int pos, int u=1, int l=0, int r=n-1) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[u]=d[st[u]];
		if (st[u]<=2)
			to_erase.push_back(l);
		return;
	}
	int mid=(l+r)/2;
	upd(pos, 2*u, l, mid);
	upd(pos, 2*u+1, mid+1, r);
	st[u]=st[2*u]+st[2*u+1];
}
ll qry(int x, int y, int u=1, int l=0, int r=n-1) {
	if (r<x||l>y) return 0;
	if (x<=l&&r<=y) return st[u];
	int mid=(l+r)/2;
	return qry(x, y, 2*u, l, mid)+qry(x, y, 2*u+1, mid+1, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		if (a[i]>2)
			s.insert(i);
	}
	build();
	gen();
	while(m--) {
		int t, l, r;
		cin >> t >> l >> r, --l, --r;
		if (t==1) {
			for (auto it=s.lower_bound(l); it!=s.end()&&*it<=r; ++it)
				upd(*it);
			for (int i : to_erase)
				s.erase(i);
			to_erase.clear();
		}
		else {
			cout << qry(l, r) << '\n';
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/