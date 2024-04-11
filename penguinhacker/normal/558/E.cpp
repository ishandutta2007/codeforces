#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, q;
string s;

struct seg_tree {
	int a[mxN], st[4*mxN], lz[4*mxN];
	seg_tree() {
		memset(lz, -1, sizeof(lz));
	}
	void push(int u, int l, int r) {
		if (lz[u]==-1)
			return;
		st[u]=lz[u]*(r-l+1);
		if (l^r)
			lz[2*u]=lz[2*u+1]=lz[u];
		lz[u]=-1;
	}
	void trav(int u=1, int l=0, int r=n-1) {
		push(u, l, r);
		if (l==r) {
			a[l]=st[u];
			return;
		}
		int mid=(l+r)/2;
		trav(2*u, l, mid);
		trav(2*u+1, mid+1, r);
	}
	void upd(int ql, int qr, int x, int u=1, int l=0, int r=n-1) {
		push(u, l, r);
		if (l>qr||r<ql)
			return;
		if (ql<=l&&r<=qr) {
			lz[u]=x;
			push(u, l, r);
			return;
		}
		int mid=(l+r)/2;
		upd(ql, qr, x, 2*u, l, mid);
		upd(ql, qr, x, 2*u+1, mid+1, r);
		st[u]=st[2*u]+st[2*u+1];
	}
	int qry(int ql, int qr, int u=1, int l=0, int r=n-1) {
		push(u, l, r);
		if (l>qr||r<ql)
			return 0;
		if (ql<=l&&r<=qr)
			return st[u];
		int mid=(l+r)/2;
		return qry(ql, qr, 2*u, l, mid)+qry(ql, qr, 2*u+1, mid+1, r);
	}
} t[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> s;
	for (int i=0; i<n; ++i)
		t[s[i]-'a'].upd(i, i, 1);
	while(q--) {
		int l, r, qt;
		cin >> l >> r >> qt, --l, --r;
		int cnt[26];
		for (int i=0; i<26; ++i) {
			cnt[i]=t[i].qry(l, r);
			t[i].upd(l, r, 0);
		}
		int cur=l;
		if (qt==1) {
			for (int i=0; i<26; ++i) {
				if (!cnt[i])
					continue;
				t[i].upd(cur, cur+cnt[i]-1, 1);
				cur+=cnt[i];
			}
		} else {
			for (int i=25; ~i; --i) {
				if (!cnt[i])
					continue;
				t[i].upd(cur, cur+cnt[i]-1, 1);
				cur+=cnt[i];
			}
		}
	}
	for (int i=0; i<26; ++i) {
		t[i].trav();
		for (int j=0; j<n; ++j)
			if (t[i].a[j]==1)
				s[j]='a'+i;
	}
	cout << s;
	return 0;
}