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
	ll n, H = 0;
	
	T zero;
	vector<T> value;

	U noop;
	vector<bool> dirty;
	vector<U> prop;

	segtree(ll n, T zero = T(), U noop = U()): n(n), zero(zero), noop(noop) {
		while ((1 << H) < 2*n) H++;
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
		if (i == j) return;
		i += n, j += n;
		propagate(i), propagate(j-1);
		for (ll l = i, r = j; l < r; l /= 2, r /= 2) {
			if (l & 1) apply(l++,upd);
			if (r & 1) apply(--r,upd);
		}
		rebuild(i), rebuild(j-1);
	}
	
	T query(ll i, ll j) {
		if (i == j) return zero;
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

const ll N = 1e5 + 10;
const ll MOD[] = {1000000007/*123454411*/,123454349,123454339}, r[] = {752,2874,2348};

ll modExp[3][N];
ll modExpSum[3][N];

struct node {
	ll len, a[3];
	
	node(ll x = 0) {
		len = 1;
		FOR(i,0,3) a[i] = x % MOD[i];
	}
	node operator+(node n) {
		node res;
		res.len = len + n.len;
		FOR(i,0,3) res.a[i] = (a[i] + modExp[i][len] * n.a[i]) % MOD[i];
		return res;
	}
	bool operator==(const node &n) {
		FOR(i,0,1) if (a[i] != n.a[i]) return false;
		return true;
	}
};

struct update {
	ll x;
	
	update(ll x = -1): x(x) {}
	node operator()(node n) {
		if (x == -1) return n;
		node res;
		res.len = n.len;
		FOR(i,0,3) res.a[i] = x * modExpSum[i][n.len] % MOD[i];
		return res;
	}
	update operator+(update u) {
		return (u.x != -1) ? u : *this;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	FOR(i,0,3) {
		modExp[i][0] = 1;
		FOR(j,1,N) modExp[i][j] = modExp[i][j-1] * r[i] % MOD[i];
		modExpSum[i][0] = 0;
		FOR(j,1,N) modExpSum[i][j] = (modExpSum[i][j-1] + modExp[i][j-1]) % MOD[i];
	}

	ll n, m, k; cin >> n >> m >> k;
	string s; cin >> s;
	
	node zero;
	zero.len = 0;
	segtree<node,update> sg(n,zero);

	vector<node> v(n);
	FOR(i,0,n) v[i] = node(s[i]-'0');
	sg.set_leaves(v);

	m += k;
	while (m--) {
		ll type, l, r, c;
		cin >> type >> l >> r >> c;
		l--;
		if (type == 1) {
			sg.update(l,r,update(c));
		} else {
			node n1 = sg.query(l,r-c), n2 = sg.query(l+c,r);
//			FOR(i,0,3) cerr << n1.a[i] << " " << n2.a[i] << endl;
			cout << (n1 == n2 ? "YES" : "NO") << "\n";
		}
	}
}