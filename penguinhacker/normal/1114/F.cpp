#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=4e5, M=1e9+7;
int n, q, a[mxN], id[301];
vector<int> primes;
vector<ll> tot;
set<ar<int, 2>> seg[62];
ll st[1<<20], lz[1<<20];

vector<int> factor(int x) {
	vector<int> r;
	for (int i=0; i<primes.size(); ++i)
		if (x%primes[i]==0)
			r.push_back(i);
	return r;
}

void addSeg(set<ar<int, 2>>& s, ar<int, 2> x) {
	auto it=s.lower_bound(x);
	if (it!=s.end()&&(*it)[0]==x[0]) {
		if ((*it)[1]>=x[1])
			return;
		it=s.erase(it);
	}
	if (it!=s.begin()) {
		ar<int, 2> y=*prev(it);
		if (y[1]>=x[1])
			return;
		if (y[1]+1>=x[0]) {
			s.erase(prev(it));
			x={y[0], x[1]};
		}
	}
	while(it!=s.end()&&(*it)[1]<=x[1])
		it=s.erase(it);
	if (it!=s.end()&&x[1]+1>=(*it)[0]) {
		x={x[0], (*it)[1]};
		it=s.erase(it);
	}
	s.insert(it, x);
}

void bld(int u=1, int l=0, int r=n-1) {
	lz[u]=1;
	if (l==r) {
		st[u]=a[l];
		return;
	}
	int mid=(l+r)/2;
	bld(2*u, l, mid);
	bld(2*u+1, mid+1, r);
	st[u]=(st[2*u]*st[2*u+1])%M;
}

ll bp(ll b, int p=M-2) {
	ll r=1;
	for (; p; p/=2, b=b*b%M)
		if (p%2)
			r=r*b%M;
	return r;
}

void psh(int u, int l, int r) {
	if (lz[u]!=1) {
		st[u]=st[u]*bp(lz[u], r-l+1)%M;
		if (l^r)
			lz[2*u]=lz[2*u]*lz[u]%M, lz[2*u+1]=lz[2*u+1]*lz[u]%M;
		lz[u]=1;
	}
}

void upd(int ql, int qr, int x, int u=1, int l=0, int r=n-1) {
	psh(u, l, r);
	if (l>qr||r<ql)
		return;
	if (ql<=l&&r<=qr) {
		lz[u]=x;
		psh(u, l, r);
		return;
	}
	int mid=(l+r)/2;
	upd(ql, qr, x, 2*u, l, mid);
	upd(ql, qr, x, 2*u+1, mid+1, r);
	st[u]=st[2*u]*st[2*u+1]%M;
}

ll qry(int ql, int qr, int u=1, int l=0, int r=n-1) {
	psh(u, l, r);
	if (ql<=l&&r<=qr)
		return st[u];
	int mid=(l+r)/2;
	return (ql<=mid?qry(ql, qr, 2*u, l, mid):1)*(qr>mid?qry(ql, qr, 2*u+1, mid+1, r):1)%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=2; i<=300; ++i) {
		bool ok=1;
		for (int j : primes)
			ok&=i%j>0;
		if (ok) {
			id[i]=primes.size();
			primes.push_back(i);
			tot.push_back((i-1)*bp(i)%M);
		}
	}
	assert(primes.size()==sizeof(seg)/sizeof(seg[0]));
	cin >> n >> q;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		for (int p : factor(a[i]))
			addSeg(seg[p], {i, i});
	}
	bld();
	while(q--) {
		string t;
		int l, r;
		cin >> t >> l >> r, --l, --r;
		if (t[0]=='M') {
			int x;
			cin >> x;
			upd(l, r, x);
			for (int p : factor(x))
				addSeg(seg[p], {l, r});
		} else {
			ll ans=qry(l, r);
			for (int i=0; i<primes.size(); ++i) {
				auto it=seg[i].lower_bound({l});
				if (it!=seg[i].end()&&(*it)[0]<=r||it!=seg[i].begin()&&(*prev(it))[1]>=l)
					ans=ans*tot[i]%M;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}