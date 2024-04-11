#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

struct LazyAddMax
{
	vector<ll> seg;
	vector<ll> updates;
	int nb_elem;
	ll UNDEF = -1e18;
	int p, deb;

	LazyAddMax(const vector<ll> &arr)
	{
		p=0;
		while ((1<<p) < SZ(arr)) ++p;
		deb = (1<<p)-1;
		nb_elem = (1<<p);
		seg.resize(4*nb_elem);
		updates.resize(4*nb_elem);
		for (int i(0); i < SZ(seg); ++i)
			seg[i] = UNDEF;	
		for (int i(0); i < SZ(arr); ++i)
			seg[deb + i] = arr[i];
		for (int i(deb-1); i >= 0; --i)
			seg[i] = max(seg[2*i+1], seg[2*i+2]);
	}

	void push(int node)
	{
		seg[node] += updates[node];
		if (2*node +1 < SZ(updates))
			updates[2*node+1] += updates[node];
		if (2*node + 2 < SZ(updates))
			updates[2*node+2] += updates[node];
		updates[node] = 0;
	}

	void __add(int node, int l, int r, int lo, int up, ll delta)
	{
		if (l > r) return ;
		push(node);
		if (l > up or r < lo)
			return ;
		if (lo <= l and up >= r)
		{
			updates[node] += delta;
			push(node);
			return ;
		}
		int mid = (l+r)/2;
		__add(2*node + 1, l, mid, lo,up, delta);
		__add(2*node+2, mid+1, r, lo,up,delta);
		seg[node] = max(seg[2*node+1], seg[2*node+2]);
		assert(!updates[node]);
	}

	void add(int lo, int up, ll delta)
	{
		__add(0,0, nb_elem-1, lo,up, delta);
	}

	ll __query(int node, int l, int r, int lo, int up)
	{
		push(node);
		if (l > up or r < lo)
			return UNDEF;
		if (l >= lo and r <= up)
			return seg[node];
		return max(__query(2*node+1, l, (l+r)/2, lo, up), __query(2*node+2, (l+r)/2+1, r, lo,up));
	}

	ll query(int lo, int up)
	{
		return __query(0, 0, nb_elem-1, lo,up);
	}
};



int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> p(n), q(n);
	vector<int> rev(n);
	for (int i(0); i < n; ++i)
	{
		cin >> p[i];
		rev[--p[i]] = i;
	}

	for (auto &v : q)
	{
		cin >> v;
		--v;
	}
	LazyAddMax lazy = LazyAddMax(vector<ll>(n, 0));
	int rep = n-1;
	lazy.add(0, rev[n-1], 1);
	for (auto v : q)
	{
		while (lazy.query(0, n-1) <= 0)
		{
			--rep;
			lazy.add(0, rev[rep], 1);
		}
		cout << rep + 1 << ' ';
		lazy.add(0, v, -1);
	}
	cout << endl;
}