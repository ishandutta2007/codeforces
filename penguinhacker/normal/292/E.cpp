#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, a[100000], b[100000];
pair<int, int> updates[100000];
int last[100000], lazy[4*100000];

void propagate(int id, int l, int r) {
	if (lazy[id]==-1)
		return;
	if (l==r)
		last[l]=lazy[id];
	else {
		lazy[2*id]=lazy[id];
		lazy[2*id+1]=lazy[id];
	}
	lazy[id]=-1;
}

void upd(int x, int y, int c, int id=1, int l=0, int r=n-1) {
	propagate(id, l, r);
	if (l>y||r<x)
		return;
	if (x<=l&&r<=y) {
		lazy[id]=c;
		propagate(id, l, r);
		return;
	}
	int mid=(l+r)/2;
	upd(x, y, c, 2*id, l, mid);
	upd(x, y, c, 2*id+1, mid+1, r);
}

void qry(int pos, int id=1, int l=0, int r=n-1) {
	propagate(id, l, r);
	if (r<pos||l>pos||l==r)
		return;
	int mid=(l+r)/2;
	qry(pos, 2*id, l, mid);
	qry(pos, 2*id+1, mid+1, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	fill(last, last+n, -1);
	fill(lazy, lazy+4*n, -1);
	for (int i=0, type; i<q; ++i) {
		cin >> type;
		if (type==1) {
			int x, y, k;
			cin >> x >> y >> k, --x, --y;
			updates[i]={x, y};
			upd(y, y+k-1, i);
		}
		else {
			int pos;
			cin >> pos, --pos;
			qry(pos);
			int ind=last[pos];
			cout << (ind==-1?b[pos]:a[pos-updates[ind].second+updates[ind].first]) << '\n';
		}
	}
	return 0;
}