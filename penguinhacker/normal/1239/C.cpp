#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct seg_tree {
	int n; vector<int> seg;
	seg_tree(int _n) : n(_n) {seg.assign(4*n, 0);}

	void upd(int x, int val, int u, int l, int r) {
		if (l>x||r<x) return;
		if (l==r) {seg[u]=val; return;}
		int mid=(l+r)/2;
		upd(x, val, 2*u, l, mid), upd(x, val, 2*u+1, mid+1, r);
		seg[u]=seg[2*u]+seg[2*u+1];
	}
	void upd(int x, int val) {upd(x, val, 1, 0, n-1);}
	int qry(int x, int y, int u, int l, int r) {
		if (l>y||r<x) return 0;
		if (x<=l&&r<=y) return seg[u];
		int mid=(l+r)/2;
		return qry(x, y, 2*u, l, mid)+qry(x, y, 2*u+1, mid+1, r);
	}
	int qry(int x, int y) {return qry(x, y, 1, 0, n-1);}
};

const int mxN=1e5;
int n, p, a[mxN], ind[mxN];
ll ans[mxN], T=-1;
queue<int> q;
set<int> qq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		ind[i]=i;
	}
	sort(ind, ind+n, [](int x, int y) {return a[x]==a[y]?x<y:a[x]<a[y];});

	seg_tree tree(n);
	auto check=[&](int pos) {
		return tree.qry(0, pos-1)==0;
	};
	auto remove=[&](int &last) {
		int pos=q.front(); q.pop();
		last=pos;
		tree.upd(pos, 0);
		T+=p;
		ans[pos]=T;
	};

	for (int i=0, last=-1; !q.empty()||!qq.empty()||i<n; ) {
		if (q.empty()&&qq.empty()&&a[ind[i]]>T)
			T=a[ind[i]];
		while(i<n&&a[ind[i]]<=T) {
			if (a[ind[i]]<T&&check(ind[i])&&(last==-1||last>ind[i])) {
				q.push(ind[i]);
				tree.upd(ind[i], 1);
				++i;
			}
			else qq.insert(ind[i++]);
		}
		if (!qq.empty()&&check(*qq.begin())) {
			int x=*qq.begin();
			q.push(x);
			tree.upd(x, 1);
			qq.erase(qq.begin());
		}
		assert(!q.empty());
		remove(last);
	}
	for (int i=0; i<n; ++i)
		cout << ans[i] << " ";
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/