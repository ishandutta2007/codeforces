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
			value[i] = prop[i](value[2*i] + value[2*i+1]);
		}
	}

	void propagate(ll i) {
		FORD(h,1,H+1) if (dirty[i >> h]) {
			ll j = i >> h;
			apply(2*j,prop[j]), apply(2*j+1,prop[j]);
			prop[j] = noop, dirty[j] = false;
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

const ll MOD = 1e9 + 7;

struct node {
	ll x[2];
	node() { FOR(i,0,2) x[i] = 0; }
	node operator+(node n) {
		node res;
		FOR(i,0,2) res.x[i] = (x[i] + n.x[i]) % MOD;
		return res;
	}
};

struct update {
	ll a[2][2];
	update() { FOR(i,0,2) FOR(j,0,2) a[i][j] = 0; }
	node operator()(node n) {
		node res;
		FOR(i,0,2) FOR(j,0,2) res.x[i] = (res.x[i] + a[i][j] * n.x[j]) % MOD;
		return res;
	}
	update operator+(update u) {
		update res;
		FOR(i,0,2) FOR(k,0,2) FOR(j,0,2)
			res.a[i][j] = (res.a[i][j] + a[i][k]*u.a[k][j]) % MOD;
		return res;
	}
};

update fibmat(ll n) {
	update res, a;
	res.a[0][0] = res.a[1][1] = 1;
	a.a[0][0] = a.a[0][1] = a.a[1][0] = 1;
	while (n) {
		if (n & 1) res = res + a;
		a = a + a;
		n /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;

	node zero;
	zero.x[0] = 1;
	update unit;
	unit.a[0][0] = unit.a[1][1] = 1;

	vector<node> a(n);
	FOR(i,0,n) {
		ll k; cin >> k;
		a[i] = fibmat(k-1)(zero);
	}
	
	segtree<node,update> s(n,node(),unit);
	s.set_leaves(a);	
	
	while (m--) {
		ll type; cin >> type;
		if (type == 1) {
			ll l, r, x; cin >> l >> r >> x;
			l--;
			s.update(l,r,fibmat(x));
		} else {
			ll l, r; cin >> l >> r;
			l--;
			cout << s.query(l,r).x[0] << "\n";
		}
	}

}