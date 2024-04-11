#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
string s;

struct Node {
	int dp00, dp01, dp10, dp11;
	bool lz=0;
} st[1<<21];

Node cmb(Node a, Node b) {
	Node r;
	r.dp00=a.dp00+b.dp00;
	r.dp11=a.dp11+b.dp11;
	r.dp01=max({a.dp00+b.dp01, a.dp00+b.dp11, a.dp01+b.dp11});
	r.dp10=max({a.dp11+b.dp10, a.dp11+b.dp00, a.dp10+b.dp00});
	return r;
}

void bld(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		if (s[l]=='4')
			st[u].dp00=1;
		else
			st[u].dp11=1;
		return;
	}
	int mid=(l+r)/2;
	bld(2*u, l, mid);
	bld(2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

void psh(int u, int l, int r) {
	if (st[u].lz) {
		swap(st[u].dp00, st[u].dp11);
		swap(st[u].dp01, st[u].dp10);
		if (l^r)
			st[2*u].lz^=1, st[2*u+1].lz^=1;
		st[u].lz=0;
	}
}

void upd(int ql, int qr, int u=1, int l=0, int r=n-1) {
	psh(u, l, r);
	if (l>qr||r<ql)
		return;
	if (ql<=l&&r<=qr) {
		st[u].lz^=1;
		psh(u, l, r);
		return;
	}
	int mid=(l+r)/2;
	upd(ql, qr, 2*u, l, mid);
	upd(ql, qr, 2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;
	bld();
	while(m--) {
		string t;
		cin >> t;
		if (t[0]=='s') {
			int l, r;
			cin >> l >> r, --l, --r;
			upd(l, r);
		} else {
			cout << max({st[1].dp00, st[1].dp01, st[1].dp11}) << "\n";
		}
	}
	return 0;
}