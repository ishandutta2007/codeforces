#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, a[100000];
pair<int, int> st[400000]; //<gcd of range, cnt of gcd>

int gcd(int x, int y) {
	if (x<y)
		swap(x, y);
	if (x%y==0)
		return y;
	return gcd(y, x%y);
}

pair<int, int> combine(pair<int, int> x, pair<int, int> y) {
	if (x.first==-1)
		return y;
	if (y.first==-1)
		return x;
	int g=gcd(x.first, y.first);
	int cnt=0;
	if (x.first==g)
		cnt+=x.second;
	if (y.first==g)
		cnt+=y.second;
	return {g, cnt};
}

void build(int id=1, int l=0, int r=n-1) {
	if (l==r) {
		st[id]={a[l], 1};
		return;
	}
	int mid=(l+r)/2;
	build(2*id, l, mid);
	build(2*id+1, mid+1, r);
	st[id]=combine(st[2*id], st[2*id+1]);
}

pair<int, int> qry(int x, int y, int id=1, int l=0, int r=n-1) {
	if (l>y||r<x)
		return {-1, -1};
	if (x<=l&&r<=y)
		return st[id];
	int mid=(l+r)/2;
	return combine(qry(x, y, 2*id, l, mid), qry(x, y, 2*id+1, mid+1, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	build();
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		cout << (r-l+1)-qry(l, r).second << '\n';
	}
	return 0;
}