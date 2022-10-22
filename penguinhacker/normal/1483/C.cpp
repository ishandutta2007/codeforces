#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct seg_tree {
	const ll ID=-1e18;
	ll n;
	vector<ll> seg, lazy;
	seg_tree(ll _n) : n(_n) {
		seg.assign(4*n, 0);
		lazy.assign(4*n, 0);
	}

	ll combine(ll a, ll b) {return max(a, b);}
	void push(ll u, ll l, ll r) {
		seg[u]+=lazy[u];
		if (l!=r) lazy[2*u]+=lazy[u], lazy[2*u+1]+=lazy[u];
		lazy[u]=0;
	}
	void pull(ll u) {seg[u]=combine(seg[2*u], seg[2*u+1]);}

	void build(ll a[], ll u, ll l, ll r) {
		if (l==r) { seg[u]=a[l]; return; }
		ll mid=(l+r)/2;
		build(a, 2*u, l, mid), build(a, 2*u+1, mid+1, r);
		pull(u);
	}
	void build(ll a[]) {build(a, 1, 0, n-1);}

	void upd(ll x, ll y, ll val, ll u, ll l, ll r) {
		push(u, l, r); if (l>y||r<x) return;
		if (x<=l&&r<=y) { lazy[u]+=val; push(u, l, r); return; }
		ll mid=(l+r)/2; upd(x, y, val, 2*u, l, mid), upd(x, y, val, 2*u+1, mid+1, r);
		pull(u);
	}
	void upd(ll x, ll y, ll val) {upd(x, y, val, 1, 0, n-1);}

	ll qry(ll x, ll y, ll u, ll l, ll r) {
		push(u, l, r); if (l>y||r<x) return ID;
		if (x<=l&&r<=y) return seg[u];
		ll mid=(l+r)/2;
		return combine(qry(x, y, 2*u, l, mid), qry(x, y, 2*u+1, mid+1, r));
	}
	ll qry(ll x, ll y) {return qry(x, y, 1, 0, n-1);}
};

ll n, h[300001], b[300001];
ll dp[300000];

ll comb(ll i, ll j) {
	return h[i] < h[j] ? i : j;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; ++i)
		cin >> h[i];
	for (ll i = 0; i < n; ++i)
		cin >> b[i];
	seg_tree st(n);
	vector<pair<ll, ll>> p;
	ll mn = 0;
	for (ll i = 0; i < n; ++i) {
		dp[i] = -1e18;
		while(p.size() >= 2 && comb(p.end()[-2].second, p.back().second) == p.back().second) {
			pair<ll, ll> t = p.back();
			p.pop_back();
			st.upd(p.back().first, t.first - 1, b[t.second] - b[p.back().second]);
			p.back().second = t.second;
		}
		mn = comb(mn, i);
		dp[i] = b[mn];
		if (i)
			dp[i] = max(dp[i], st.qry(0, i - 1));
		if (i + 1 < n) {
			st.upd(i, i, dp[i] + b[i + 1]);
			p.emplace_back(i, i + 1);
		}
		//cout << dp[i] << "\n";
	}
	cout << dp[n - 1];
	return 0;
}