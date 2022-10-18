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
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

template<typename T>
struct segtree {
	ll n;
	vector<T> value;

	segtree<T>(vector<T> leaves): n(sz(leaves)) {
		value.resize(2*n);
		copy(all(leaves),begin(value)+n);
		FORD(i,1,n) value[i] = value[2*i] + value[2*i+1];
	}
	
	void update(ll i, T v) {
		i += n;
		value[i] = v;
		for (i /= 2; i; i /= 2) value[i] = value[2*i] + value[2*i+1];
	}
	
	T query(ll i, ll j) {
		i += n, j += n;
		T resl, resr;
		for (; i < j; i /= 2, j /= 2) {
			if (i & 1) resl = resl + value[i++];
			if (j & 1) resr = value[--j] + resr;
		}
		return resl + resr;
	}
};

struct node {
	ll x = -oo, i = -1;
	node operator+(node n) {
		if (x > n.x) return *this;
		return n;
	}
};

const ll K = 19;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, q;
	cin >> n >> m >> q;

	vl val(n), a(m), b(m);
	FOR(i,0,n) cin >> val[i];
	FOR(i,0,m) cin >> a[i] >> b[i], a[i]--, b[i]--;
	
	vector<pll> queries(q);
	for (auto &[t,i]: queries) cin >> t >> i, i--;
	
	vl del(m,q);
	FOR(i,0,q) if (queries[i].xx == 2) {
		del[queries[i].yy] = i;
	}

	vvl par(n, vl(K,-1));
	vl root(n), tpar(n,-1);
	iota(all(root),0);

	function<ll(ll)> find = [&](ll x) {
		if (x == root[x]) return x;
		return root[x] = find(root[x]);
	};

	auto unite = [&](ll x, ll y, ll t) {
		ll rx = find(x), ry = find(y);
		if (rx == ry) return false;
		if (rand() & 1) swap(rx,ry);
		root[rx] = ry;
		par[rx][0] = ry;
		tpar[rx] = t;
		return true;
	};

	FOR(i,0,m) if (del[i] == q) unite(a[i],b[i],q);
	FORD(i,0,q) if (queries[i].xx == 2) {
		ll j = queries[i].yy;
		unite(a[j],b[j],i);
	}
	
	FOR(k,0,K-1) FOR(i,0,n) {
		if (par[i][k] == -1) continue;
		par[i][k+1] = par[par[i][k]][k];
	}
	
	vvl children(n);
	FOR(i,0,n) if (par[i][0] != -1) children[par[i][0]].pb(i);
	FOR(i,0,n) sort(all(children[i]), [&](ll j, ll k) { return tpar[j] > tpar[k]; });

	ll T = 0;
	vl tin(n), tout(n), order(n);
	
	function<void(ll)> dfs = [&](ll i) {
		tin[i] = T;
		order[T++] = i;
		for (ll j: children[i]) dfs(j);
		tout[i] = T;
	};

	FOR(i,0,n) if (par[i][0] == -1) {
		dfs(i);
	}

	vector<node> leaves(n);
	FOR(i,0,n) {
		ll j = order[i];
		leaves[i] = {val[j],j};
		// cerr << val[j] << " " << j << endl;
	}
	segtree<node> S(leaves);

	FOR(i,0,q) {
		if (queries[i].xx == 2) continue;
		ll x = queries[i].yy;
		FORD(k,0,K) {
			if (par[x][k] != -1 && tpar[par[x][k]] > i) {
				x = par[x][k];
			}
		}
		if (tpar[x] > i) x = par[x][0];
		assert(tpar[x] < i);

		node res = S.query(tin[x],tin[x]+1);

		if (sz(children[x]) && tpar[children[x][0]] > i) {
			ll lo = 0, hi = sz(children[x]);
			while (hi-lo > 1) {
				ll m = (lo+hi)/2;
				ll y = children[x][m];
				if (tpar[y] > i) lo = m; else hi = m;
			}
			res = res + S.query(tin[children[x][0]], tout[children[x][lo]]);
		}

		cout << res.x << '\n';
		val[res.i] = 0;
		S.update(tin[res.i], {0,res.i});
	}
}