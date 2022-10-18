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

template<typename T, typename U>
struct segtree {
	ll n, H;
	
	vector<T> value;
	vector<U> prop;
	vector<bool> dirty;

	segtree<T,U>(vector<T> leaves): n(sz(leaves)) {
		H = 32 - __builtin_clz(2*n-1);

		value.resize(2*n);
		copy(all(leaves),begin(value)+n);
		FORD(i,1,n) value[i] = value[2*i] + value[2*i+1];
		
		dirty.resize(n,false);
		prop.resize(n);
	}

	void apply(ll i, U &upd) {
		value[i] = upd(value[i]);
		if (i < n) prop[i] = prop[i] + upd, dirty[i] = true;
	}

	void rebuild(ll i) {
		for (i /= 2; i; i /= 2) value[i] = prop[i](value[2*i] + value[2*i+1]);
	}

	void propagate(ll i) {
		FORD(h,1,H+1) if (dirty[i >> h]) {
			ll j = i >> h;
			apply(2*j,prop[j]), apply(2*j+1,prop[j]);
			prop[j] = U(), dirty[j] = false;
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
		T resl, resr;
		for (; i < j; i /= 2, j /= 2) {
			if (i & 1) resl = resl + value[i++];
			if (j & 1) resr = value[--j] + resr;
		}
		return resl + resr;
	}
};

struct node {
	ll x = oo;
	node operator+(node n) { return {min(x,n.x)}; }
};

struct update {
	ll add = 0;
	node operator()(node n) { return {n.x+add}; }
	update operator+(update u) { return {add + u.add}; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl p(n), a(n);
	FOR(i,0,n) cin >> p[i], p[i]--;
	FOR(i,0,n) cin >> a[i];
	
	vector<node> leaves(n+1, {0});
	segtree<node,update> S(leaves);
	
	FOR(i,0,n) {
		S.update(p[i]+1,n+1,{a[i]});
	}

	ll res = oo;
	FOR(i,0,n-1) {
		S.update(p[i]+1,n+1,{-a[i]});
		S.update(0,p[i]+1,{a[i]});
		res = min(res, S.query(0,n+1).x);
	}
	cout << res << endl;
}