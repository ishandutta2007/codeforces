#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, st[800000];

void build(int id=1, int l=0, int r=n-1) {
	if (l==r) {
		st[id]=1;
		return;
	}
	int mid=(l+r)/2;
	build(2*id, l, mid);
	build(2*id+1, mid+1, r);
	st[id]=st[2*id]+st[2*id+1];
}

void upd(int pos, int id=1, int l=0, int r=n-1) {
	if (l>pos||r<pos)
		return;
	--st[id];
	if (l==r)
		return;
	int mid=(l+r)/2;
	upd(pos, 2*id, l, mid);
	upd(pos, 2*id+1, mid+1, r);
}

int qry(int pos, int id=1, int l=0, int r=n-1) { //number of positions from [0, pos]
	if (l>pos)
		return 0;
	if (r<=pos)
		return st[id];
	int mid=(l+r)/2;
	int a=qry(pos, 2*id, l, mid), b=qry(pos, 2*id+1, mid+1, r);
	return a+b;
}

int cnt[200000], ans[200000];

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Tree;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int turn=0; turn<2; ++turn) {
		build();
		for (int i=0, a; i<n; ++i) {
			cin >> a;
			upd(a);
			cnt[i]+=qry(a);
		}
	}
	for (int i=n-2; ~i; --i) {
		if (i) {
			if (cnt[i]>=n-i) {
				cnt[i]-=n-i;
				++cnt[i-1];
			}
		}
		else {
			cnt[i]%=n;
		}
	}
	Tree p;
	for (int i=0; i<n; ++i)
		p.insert(i);
	for (int i=0; i<n; ++i) {
		ans[i]=*p.find_by_order(cnt[i]);
		p.erase(p.find_by_order(cnt[i]));
	}
	for (int i=0; i<n; ++i)
		cout << ans[i] << ' ';
	return 0;
}