#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int q, d;
set<int> s;

struct {
	int ft[mxN+1];
	void upd(int i, int x) {
		for (; i<=mxN; i+=i&-i)
			ft[i]+=x;
	}
	int qry(int i) {
		int r=0;
		for (; i; i-=i&-i)
			r+=ft[i];
		return r;
	}
} ft;

ll C2(int x) {
	assert(x>=0);
	return (ll)x*(x-1)/2;
}

struct {
	ll st[1<<19];
	int active[1<<19], lz[1<<19];
	void psh(int u, int l, int r) {
		if (lz[u]) {
			st[u]+=(ll)lz[u]*active[u];
			if (l!=r)
				lz[2*u]+=lz[u], lz[2*u+1]+=lz[u];
			lz[u]=0;
		}
	}
	void pll(int u) {
		st[u]=st[2*u]+st[2*u+1];
		active[u]=active[2*u]+active[2*u+1];
	}
	void upd(int ql, int qr, int x, int u=1, int l=1, int r=mxN) {
		psh(u, l, r);
		if (l>qr||r<ql)
			return;
		if (ql<=l&&r<=qr) {
			lz[u]+=x;
			psh(u, l, r);
			return;
		}
		int mid=(l+r)/2;
		upd(ql, qr, x, 2*u, l, mid);
		upd(ql, qr, x, 2*u+1, mid+1, r);
		pll(u);
	}
	void activate(int i, int x, int u=1, int l=1, int r=mxN) {
		psh(u, l, r);
		if (l>i||r<i)
			return;
		if (l==r) {
			assert(st[u]==0);
			active[u]=x;
			//st[u]=0;
			return;
		}
		int mid=(l+r)/2;
		activate(i, x, 2*u, l, mid);
		activate(i, x, 2*u+1, mid+1, r);
		pll(u);
	}
	ll qry(int i, int u=1, int l=1, int r=mxN) {
		psh(u, l, r);
		if (l>i)
			return 0;
		if (r<=i)
			return st[u];
		int mid=(l+r)/2;
		return qry(i, 2*u, l, mid)+qry(i, 2*u+1, mid+1, r);
	}
} st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> q >> d;
	ll ans=0;
	while(q--) {
		int a;
		cin >> a;
		if (s.find(a)==s.end()) { // add
			int lhs=ft.qry(a)-ft.qry(max(a-d-1, 0));
			int rhs=ft.qry(min(mxN, a+d))-ft.qry(a);
			ans+=C2(lhs)+C2(rhs)+st.qry(a);
			ft.upd(a, 1);
			s.insert(a);
			st.activate(a, 1);
			st.upd(max(1, a-d), a-1, 1);
			st.upd(a+1, min(mxN, a+d), -1);
			st.upd(a, a, rhs-lhs);
		} else {
			ft.upd(a, -1);
			s.erase(a);
			int lhs=ft.qry(a)-ft.qry(max(a-d-1, 0));
			int rhs=ft.qry(min(mxN, a+d))-ft.qry(a);
			st.upd(max(1, a-d), a-1, -1);
			st.upd(a+1, min(mxN, a+d), 1);
			st.upd(a, a, -(rhs-lhs));
			st.activate(a, 0);
			ans-=C2(lhs)+C2(rhs)+st.qry(a);
		}
		cout << ans << "\n";
	}
	return 0;
}