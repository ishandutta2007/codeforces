#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, st[4*mxN];
ar<int, 3> q[mxN];
vector<int> d;
set<int> s[mxN];

void upd(int i, int u=1, int l=0, int r=d.size()-1) {
	if (l==r) {
		st[u]=s[l].empty()?-1:*s[l].rbegin();
		return;
	}
	int mid=(l+r)/2;
	if (i<=mid)
		upd(i, 2*u, l, mid);
	else
		upd(i, 2*u+1, mid+1, r);
	st[u]=max(st[2*u], st[2*u+1]);
}

int qry(int x, int y, int u=1, int l=0, int r=d.size()-1) {
	if (r<x||st[u]<y)
		return -1;
	if (l==r)
		return l;
	int mid=(l+r)/2;
	int ls=qry(x, y, 2*u, l, mid);
	if (ls^-1)
		return ls;
	return qry(x, y, 2*u+1, mid+1, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s >> q[i][1] >> q[i][2];
		q[i][0]=s=="add"?0:s=="remove"?1:2;
		d.push_back(q[i][1]);
	}
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	memset(st, -1, 4*n);
	for (int i=0; i<n; ++i) {
		int t=q[i][0], x=lower_bound(d.begin(), d.end(), q[i][1])-d.begin(), y=q[i][2];
		if (t==0) {
			s[x].insert(y);
			upd(x);
		} else if (t==1) {
			s[x].erase(y);
			upd(x);
		} else {
			int ax=qry(x+1, y+1);
			if (ax==-1) {
				cout << "-1\n";
			} else {
				int ay=*s[ax].lower_bound(y+1);
				cout << d[ax] << " " << ay << "\n";
			}
		}
	}
	return 0;
}