#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int nb_armes, nb_bouc, nb_monstres;
int p, deb;
vector<pair<int, int> > armes, boucliers;
struct Monstre
{
	int def, att, rec, ind;
};

vector<Monstre> monstres_def, monstres_att;

bool sort_att(const Monstre a, const Monstre b)
{
	if (a.att == b.att)
		return a.ind < b.ind;
	return a.att < b.att;
}

bool sort_def(const Monstre a, const Monstre b)
{
	if (a.def == b.def)
		return a.ind < b.ind;
	return a.def < b.def;
}

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

	void show_seg(void)
	{
		cout << "---------------" << endl;
		for (int k(0); k <= p; ++k)
		{
			for (int i(0); i < (1<<k); ++i)
				cout << seg[(1<<k)-1 + i] << ' ';
			cout << endl;
		}
		cout << "---------------" << endl;
	}

	void show_updates(void)
	{
		cout << "---------------" << endl;
		for (int k(0); k <= p; ++k)
		{
			for (int i(0); i < (1<<k); ++i)
				cout << updates[(1<<k)-1 + i] << ' ';
			cout << endl;
		}
		cout << "---------------" << endl;
	}
};


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> nb_armes>> nb_bouc>>nb_monstres;	
	armes.resize(nb_armes);
	boucliers.resize(nb_bouc);	
	monstres_att.resize(nb_monstres);
	monstres_def.resize(nb_monstres);

	for (auto &[a, c] : armes) cin >> a >> c;
	for (auto &[d, c] : boucliers) cin >> d >> c;
	for (int i = 0; i < nb_monstres; ++i)
	{
		cin >> monstres_def[i].def >> monstres_def[i].att >> monstres_def[i].rec;
		monstres_def[i].ind = i;
	}

	sort(monstres_def.begin(), monstres_def.end(), sort_att);
	for (int i(0); i < nb_monstres; ++i)
	{
		monstres_att[i] = monstres_def[i];
		monstres_att[i].ind = i;
	}
	sort(monstres_att.begin(), monstres_att.end(), sort_def);

	sort(armes.begin(), armes.end());
	vector<ll> cost(nb_monstres+1, -1e18);
	for (auto [d, c] : boucliers)
	{
		int lo(0), up(nb_monstres-1);

		while (lo < up)
		{
			int mid = (lo+up+1)/2;
			if (monstres_def[mid].att < d)
				lo = mid;
			else
				up = mid-1;
		}

		if (d <= monstres_def[lo].att)
			--lo;
		cost[lo+1] = max(cost[lo+1], -((ll)c));
	}

	for (int i = nb_monstres-1; i >= 0; --i)
		cost[i] = max(cost[i], cost[i+1]);
	LazyAddMax lazy = LazyAddMax(cost);
	int cur_monstre(0);
	ll ans(-1e18);
	for (auto [att, c] : armes)
	{
		while (cur_monstre < nb_monstres and monstres_att[cur_monstre].def < att)
		{
			//for (int i(monstres_att[cur_monstre].ind+1); i <= nb_monstres; ++i)
			//	cost[i] += monstres_att[cur_monstre].rec;
			lazy.add(monstres_att[cur_monstre].ind+1, nb_monstres, monstres_att[cur_monstre].rec);
			++cur_monstre;
		}
		/*ll cur_best(-1e18);
		for (int i(0); i <= nb_monstres; ++i)
			cur_best = max(cur_best, cost[i]-c);
		cout << cur_monstre << ' ' << cur_best << endl;*/
		ll cur_best = -c + lazy.query(0, nb_monstres);
		ans = max(ans,cur_best);
	}
	cout << ans << endl;
}