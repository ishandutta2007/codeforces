#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, pos;
string s;

struct node {
	int lo, hi, o, c;
} st[1<<21];

node mk(int x) {
	if (x==0) // nothing
		return {0, 0, 0, 0};
	if (x==1) // opening
		return {0, 1, 1, 0};
	return {-1, 0, 0, 1}; // closing
}

node cmb(node l, node r) {
	return {
		min(l.lo, l.o-l.c+r.lo),
		max(l.hi, l.o-l.c+r.hi),
		l.o+r.o,
		l.c+r.c
	};
}

void upd(int i, int x, int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st[u]=mk(x);
		return;
	}
	int mid=(l+r)/2;
	i<=mid?upd(i, x, 2*u, l, mid):upd(i, x, 2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i=0; i<n; ++i) {
		if (s[i]=='L')
			pos=max(0, pos-1);
		else if (s[i]=='R')
			++pos;
		else
			upd(pos, s[i]=='('?1:s[i]==')'?2:0);
		cout << (st[1].lo==0&&st[1].o==st[1].c?st[1].hi:-1) << " ";
	}
	return 0;
}