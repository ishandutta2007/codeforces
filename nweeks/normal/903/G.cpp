#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

struct LazyAddMax
{
	vector<ll> seg;
	vector<ll> updates;
	int nb_elem;
	ll UNDEF = 1e18;
	int p, deb;

	LazyAddMax() {}

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
			seg[i] = min(seg[2*i+1], seg[2*i+2]);
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
		seg[node] = min(seg[2*node+1], seg[2*node+2]);
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
		return min(__query(2*node+1, l, (l+r)/2, lo, up), __query(2*node+2, (l+r)/2+1, r, lo,up));
	}

	ll query(int lo, int up)
	{
		return __query(0, 0, nb_elem-1, lo,up);
	}
};

const int MAXN = 2e5;
int nb_sommets, nb_aretes, nb_requetes;
vector<pair<int, int> > G[MAXN];
int costA[MAXN], costB[MAXN+1];
ll best[MAXN];
LazyAddMax lazy1, lazy2;

void read_input()
{
	cin >> nb_sommets >> nb_aretes >> nb_requetes;

	for (int i(0); i < nb_sommets - 1; ++i)
		cin >> costA[i] >> costB[i+1];

	for (int i(0); i < nb_aretes; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		--u, --v;
		G[u].emplace_back(v, c);
	} 	
}

void comp_best()
{
	lazy1 = LazyAddMax(vector<ll>(costB, costB + nb_sommets));
	for (int x(0); x < nb_sommets; ++x)
	{
		for (auto [y, c] : G[x])
			lazy1.add(0, y, c);
		best[x] = lazy1.query(0, nb_sommets-1);
	}
}

void build_lazy2(void)
{
	lazy2 = LazyAddMax(vector<ll>(best, best + nb_sommets));
	for (int x(0); x < nb_sommets; ++x)
		lazy2.add(x,x, costA[x]);
}

void answer_query()
{
	int x, nouv;
	cin >> x >> nouv;
	--x;
	ll delta = nouv - costA[x];
	lazy2.add(x,x,delta);
	costA[x] = nouv;
	cout << lazy2.query(0, nb_sommets-1) << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	read_input();
	comp_best();
	build_lazy2();
	cout << lazy2.query(0, nb_sommets-1) << '\n';
	while (nb_requetes--)
		answer_query();
}