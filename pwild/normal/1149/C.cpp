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

ll c[3][3] = {{1,-1,0},{0,-2,-1},{0,0,1}};

struct node {
	ll a[3][3];
	node() {
		FOR(i,0,3) FOR(j,0,3) a[i][j] = -oo*(i <= j);
	}
	node(ll x) {
		FOR(i,0,3) FOR(j,0,3) a[i][j] = c[i][j]*x;
	}
	node operator+(node n) {
		node res;
		FOR(i,0,3) FOR(j,i,3) {
			res.a[i][j] = max(a[i][j], n.a[i][j]);
			FOR(k,i,j) res.a[i][j] = max(res.a[i][j], a[i][k] + n.a[k+1][j]);
		}
		return res;
	}
};

struct update {
	ll x = 0;
	node operator()(node n) {
		FOR(i,0,3) FOR(j,i,3) n.a[i][j] += c[i][j]*x;
		return n;
	}
	update operator+(update u) {
		return {x+u.x};
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, q;
	cin >> n >> q;

	string s; cin >> s;
	n = sz(s);
	
	vector<node> leaves;
	leaves.pb(node(0));
	ll h = 0;
	for (char c: s) {
		if (c == '(') h++; else h--;
		leaves.pb(node(h));
	}

	segtree<node,update> S(leaves);

	FOR(k,0,q+1) {
		//FOR(i,0,n+1) cout << S.query(i,i+1).a[0][0] << " ";
		cout << S.query(0,n+1).a[0][2] << endl;
		if (k == q) break;
		
		ll a, b;
		cin >> a >> b;
		a--, b--;
		if (a > b) swap(a,b);

		S.update(a+1,b+1, {s[a] == '(' ? -2 : 2});
		swap(s[a],s[b]);
	}
}