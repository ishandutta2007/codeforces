#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

template<const int32_t MOD>
struct ModInt {
	long long x;
	ModInt() : x(0) {}
	ModInt(long long u) : x(u) {}
	ModInt& operator = (const ModInt &m) { x = m.x; return *this; }
	friend bool operator == (const ModInt& a, const ModInt& b) { return a.x == b.x; }
	friend bool operator != (const ModInt& a, const ModInt& b) { return a.x != b.x; }
	friend bool operator < (const ModInt& a, const ModInt& b) { return a.x < b.x; }
	friend bool operator > (const ModInt& a, const ModInt& b) { return a.x > b.x; }
	friend bool operator <= (const ModInt& a, const ModInt& b) { return a.x <= b.x; }
	friend bool operator >= (const ModInt &a, const ModInt& b) { return a.x >= b.x; }
	static ModInt sign(long long k) { return ((k & 1) ? ModInt(MOD-1) : ModInt(1)); }

 
	ModInt& operator += (const ModInt& m) { x += m.x; if(x >= MOD) x -= MOD; return *this; }
	ModInt& operator -= (const ModInt& m) { x -= m.x; if(x < 0LL) x += MOD; return *this; }
	ModInt& operator *= (const ModInt& m) { x = (1LL * x * m.x) % MOD; return *this; }
	
	friend ModInt operator - (const ModInt& a) { ModInt res(a); if(res.x) res.x = MOD - res.x; return res; }
	friend ModInt operator + (const ModInt& a, const ModInt& b) { return ModInt(a) += ModInt(b); }
	friend ModInt operator - (const ModInt& a, const ModInt& b) { return ModInt(a) -= ModInt(b); }
	friend ModInt operator * (const ModInt& a, const ModInt& b) { return ModInt(a) *= ModInt(b); }
	
	static long long fp(long long u, long long k) {
		long long res = 1LL;
		while(k > 0LL) {
			if(k & 1LL) res = (res * u) % MOD;
			u = (u * u) % MOD;
			k /= 2LL;
		}
		return res;
	}
	
	ModInt fastpow(long long k) { return ModInt(fp(x, k)); }
	ModInt inv() { return ModInt(fp(x, MOD-2)); }
	ModInt& operator /= (const ModInt& m) { return *this *= ModInt(m).inv(); }
	friend ModInt operator / (const ModInt& a, const ModInt& b) { return ModInt(a) *= ModInt(b).inv(); }
 
	friend ostream& operator << (ostream& out, const ModInt& a) { return out << a.x; }
};

const int MOD = 1e9 + 7;
const int MAXN = 1e5;
const int MAXP = 20;

using Mint = ModInt<MOD>;
vector<int> G[MAXN];
int par[MAXP][MAXN];
int pre[MAXN], post[MAXN];
int cur_t;
int depth[MAXN];
int nb_sommets, nb_requetes;

struct Segtree_add
{
	vector<ll> seg;
	int p, deb;

	Segtree_add() {}

	Segtree_add(int nb_elem) 
	{
		p = 0;
		while ((1<<p) < nb_elem) ++p;
		deb = (1<<p)-1;
		seg.resize(2*(1<<p));
		for (auto &v : seg) v = 0;
	}

	Segtree_add(const vector<ll> &arr)
	{
		p=0;
		while ((1<<p) < SZ(arr)) ++p;
		seg.resize((1<<(p+1)));
		deb = (1<<p)-1;
		for (int i(0); i < SZ(arr); ++i)
			seg[deb + i] = arr[i];
		for (int i(deb-1); i >= 0; --i)
			seg[i] = seg[2*i+1] + seg[2*i+2];
	}

	void update(int pos, ll x)
	{
		pos += deb;
		seg[pos] = x;
		while (pos)
		{
			pos = (pos-1)/2;
			seg[pos] = seg[2*pos+1] + seg[2*pos+2];
		}
	}

	ll query(int lo, int up)
	{
		lo += deb;
		up += deb;
		ll ans = 0;
		while (lo < up)
		{
			if (lo%2==0)
				ans += seg[lo];
			if (up%2)
				ans += seg[up];
			lo /= 2;
			up = (up-2)/2;
		}
		if (lo==up)
			ans += seg[lo];
		return ans;
	}
};

Segtree_add seg;

void dfs(int u, int p, int d)
{
	pre[u] = cur_t++;
	depth[u] = d;
	par[0][u] = p;
	for (auto v : G[u])
		if (v != p)
			dfs(v, u, d+1);
	post[u] = cur_t++;
}

void init(void)
{
	for (int p(1); p < MAXP; ++p)
		for (int i(0); i < nb_sommets; ++i)
			par[p][i] = par[p-1][par[p-1][i]];
}

pair<int,int> get_lca(int u, int v)
{
	if (depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	int dist = diff;
	for (int p(0); p < MAXP; ++p)
		if (diff & (1<<p))
			u = par[p][u];
	for (int p(MAXP-1); p >= 0; --p)
		if (par[p][u] != par[p][v])
		{
			u = par[p][u];
			v = par[p][v];
			dist += 2*(1<<p);
		}
	if (u != v)
	{
		u = par[0][u];
		dist+=2;
	}
	return make_pair(u, dist);
}

void read_input()
{
	cin >> nb_sommets >> nb_requetes;

	for (int i(1); i < nb_sommets; ++i)
	{
		int _u, _v;
		cin >> _u >> _v;
		--_u, --_v;
		G[_u].push_back(_v);
		G[_v].push_back(_u);
	}

	dfs(0,0, 0);
	init();
	seg = Segtree_add(2 * nb_sommets+1);
}

bool is_in_query[MAXN];

void answer_query(void)
{
	int sz_query, max_groups, root;
	cin >> sz_query >> max_groups >> root;
	--root;
	vector<vector<Mint>> dp(sz_query);
	for (auto &v : dp)
	{
		v.resize(max_groups+1);
		for (auto &w : v) w = 0;
	}

	vector<pair<int, int> > sommets(sz_query);
	for (int i(0); i < sz_query; ++i)
	{
		cin >> sommets[i].second;
		--sommets[i].second;
		is_in_query[sommets[i].second]= true;
		sommets[i].first = get_lca(sommets[i].second, root).second;
		seg.update(pre[sommets[i].second], 1);
		seg.update(post[sommets[i].second], -1);
	}
	for (int i(0); i < sz_query; ++i)
	{
		int lca = get_lca(root, sommets[i].second).first;
		sommets[i].first = seg.query(0, pre[sommets[i].second]) + seg.query(0, pre[root]) - 2*seg.query(0, pre[lca]) + (is_in_query[lca]) - 1;

	}
	sort(sommets.begin(), sommets.end());
	dp[0][1] = Mint(1);
	for (int i(1); i < sz_query; ++i)
	{
		int u = sommets[i].second;
		for (int grp(1); grp <= max_groups; ++grp)
			if (grp > sommets[i].first)
				dp[i][grp] = dp[i-1][grp] * (grp - sommets[i].first) + dp[i-1][grp-1];
	}
	Mint ans = Mint(0);
	for (int grp(0); grp <= max_groups; ++grp)
		ans += dp[sz_query-1][grp];
	cout << ans << '\n';

	for (auto [_, u] : sommets)
	{
		seg.update(pre[u], 0);
		seg.update(post[u], 0);
		is_in_query[u] = false;
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	read_input();
	while (nb_requetes--)
		answer_query();	
}