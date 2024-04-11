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
		for (i /= 2; i; i /= 2) value[i] = prop[i](value[2*i] + value[2*i+1]);
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

struct node {
	int fst, lst;
	int cnt[10][10];
	node(ll i = -1): fst(i), lst(i) { memset(cnt,0,sizeof cnt); }
	node operator+(node n) {
		if (fst == -1) return n;
		if (n.fst == -1) return *this;
		node res;
		res.fst = fst, res.lst = n.lst;
		FOR(i,0,10) FOR(j,0,10) res.cnt[i][j] = cnt[i][j] + n.cnt[i][j];
		res.cnt[lst][n.fst]++;
		return res;
	}
};
struct update {
	ll val;
	update(ll val = -1): val(val) {}
	node operator()(node n) {
		if (val == -1) return n;
		node res;
		res.fst = res.lst = val;
		return res;
	}
	update operator+(update u) {
		if (u.val == -1) return *this;
		return u;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, k; cin >> n >> m >> k;
	string s; cin >> s;
	vector<node> a(n);
	FOR(i,0,n) a[i].fst = a[i].lst = s[i]-'a';
	
	segtree<node,update> sg(n);
	sg.set_leaves(a);
	
	while (m--) {
		ll type; cin >> type;
		if (type == 1) {
			ll l, r; char c;
			cin >> l >> r >> c;
			l--;
			sg.update(l,r,update(c-'a'));
		} else {
			string p; cin >> p;
			node t = sg.query(0,n);
			ll res = n;
			FOR(i,0,k) FOR(j,i+1,k) res -= t.cnt[p[i]-'a'][p[j]-'a'];
			cout << res << "\n";
		}
	}
}