#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

template<typename T, typename U> struct segtree {
	ll n, H;
	
	T zero;
	vector<T> value;

	U noop;
	vector<bool> dirty;
	vector<U> prop;

	segtree<T,U>(ll n, T zero = T(), U noop = U()): n(n), zero(zero), noop(noop) {
		H = 0; while ((1 << H) < 2*n) H++;
		value.resize(2*n,zero);
		dirty.resize(n,false);
		prop.resize(n,noop);
	}

	void set_leaves(vector<T> &leaves) {
		copy(all(leaves),begin(value)+n);
		FORD(i,1,n) value[i] = value[2*i] + value[2*i+1];
	}

	void apply(ll i, U &upd) {
		value[i] = upd(value[i]);
		if (i < n) prop[i] = prop[i] + upd, dirty[i] = true;
	}

	void rebuild(ll i) {
		for (i /= 2; i; i /= 2) {
			T combined = value[2*i] + value[2*i+1]; value[i] = prop[i](combined);
		}
	}

	void propagate(ll i) {
		FORD(h,1,H+1) if (dirty[i >> h]) {
			ll j = i >> h;
			apply(2*j,prop[j]), apply(2*j+1,prop[j]);
			prop[j] = noop; dirty[j] = false;
		}
	}

	void update(ll i, ll j, U upd) {
		i += n, j += n;
		propagate(i), propagate(j-1);
		for (ll l = i, r = j; l < r; l /= 2, r /= 2) {
			if (l & 1) apply(l++,upd);
			if (r & 1) apply(--r,upd);
		}
		rebuild(i), rebuild(j-1);
	}
	
	T query(ll i, ll j) {
		i += n, j += n;
		propagate(i), propagate(j-1);
		T resl = zero, resr = zero;
		for (; i < j; i /= 2, j /= 2) {
			if (i & 1) resl = resl + value[i++];
			if (j & 1) resr = value[--j] + resr;
		}
		return resl + resr;
	}

};

struct node {
	ll a;
	node(ll a = 0): a(a) {}
	node operator+(const node &n) { return {a | n.a}; }
};

struct update {
	ll a;
	update(ll a): a(a) {}
	node operator()(const node &n) { return (a == -1) ? n : node(a); }
	update operator+(const update &u) { return (u.a == -1) ? *this : update(u.a); }
};

vvl adj;
vl c, l, r;
vector<node> a;
ll k = 0;

void dfs(ll i, ll p) {
	l[i] = k;
	a[k++] = node(1LL << c[i]);
	for (ll j: adj[i]) if (j != p) dfs(j,i);
	r[i] = k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	adj.resize(n);
	c.resize(n);
	a.resize(n);
	l.resize(n);
	r.resize(n);
	FOR(i,0,n) cin >> c[i];
	FOR(i,1,n) {
		ll u, v; cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0,-1);
	
	segtree<node,update> s(n,{0},{-1});
	s.set_leaves(a);
	
	while (m--) {
		ll t; cin >> t;
		if (t == 1) {
			ll i, ci; cin >> i >> ci;
			i--;
			s.update(l[i],r[i],{1LL << ci});
		} else {
			ll i; cin >> i;
			i--;
			ll res = s.query(l[i],r[i]).a;
			cout << __builtin_popcountll(res) << "\n";
		}
	}

}