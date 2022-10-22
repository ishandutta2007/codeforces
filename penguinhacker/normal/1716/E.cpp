#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, a[1<<18];
ll ans[1<<18];

struct node {
	ll ans=0, pref=0, suf=0, sum=0;
	node *lc=nullptr, *rc=nullptr;
	node(int x) { ans=pref=suf=max(0, x); sum=x; }
	node(node* lc, node* rc) : lc(lc), rc(rc) { pll(); }
	void pll() {
		ans=max({lc->ans, rc->ans, lc->suf+rc->pref});
		pref=max({lc->pref, lc->sum+rc->pref});
		suf=max({lc->suf+rc->sum, rc->suf});
		sum=lc->sum+rc->sum;
	}
};
node* rt;

node* bld(int l, int r) {
	if (l==r)
		return new node(a[l]);
	int mid=(l+r)/2;
	return new node(bld(l, mid), bld(mid+1, r));
}

void upd(int bit, node* u, int level) {
	if (level==bit+1) {
		swap(u->lc, u->rc);
		u->pll();
		return;
	}
	upd(bit, u->lc, level-1);
	upd(bit, u->rc, level-1);
	u->pll();
}

void solve(int mask, int i) {
	if (i==n) {
		//cout << mask << " " << rt->ans << endl;
		ans[mask]=rt->ans;
		return;
	}
	solve(mask, i+1);
	upd(i, rt, n);
	solve(mask|1<<i, i+1);
	upd(i, rt, n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<1<<n; ++i)
		cin >> a[i];
	rt=bld(0, (1<<n)-1);
	solve(0, 0);
	cin >> q;
	int mask=0;
	while(q--) {
		int x;
		cin >> x;
		mask^=1<<x;
		cout << ans[mask] << "\n";
	}
	return 0;
}