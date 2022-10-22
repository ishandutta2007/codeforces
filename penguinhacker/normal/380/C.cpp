#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int mxN=1e6;

int n;
string s;

struct node {
	int a{0}, o{0}, c{0};
} st[4*1000000];

node combine(node l, node r) {
	node u;
	int t=min(l.o, r.c);
	u.a=l.a+r.a+t;
	u.o=l.o+r.o-t;
	u.c=l.c+r.c-t;
	return u;
}

void build(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		if (s[l]=='(')
			st[u].o=1;
		else
			st[u].c=1;
		return;
	}
	int mid=(l+r)/2;
	build(2*u, l, mid);
	build(2*u+1, mid+1, r);
	st[u]=combine(st[2*u], st[2*u+1]);
}

node qry(int x, int y, int u=1, int l=0, int r=n-1) { // query on [x, y]
	if (l>y||r<x)
		return node{0, 0, 0};
	if (x<=l&&r<=y)
		return st[u];
	int mid=(l+r)/2;
	node a=qry(x, y, 2*u, l, mid), b=qry(x, y, 2*u+1, mid+1, r);
	return combine(a, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n=s.size();
	build();

	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		cout << 2*qry(l, r).a << '\n';
	}
	return 0;
}