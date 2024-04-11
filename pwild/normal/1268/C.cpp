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

#include <bits/extc++.h>
using namespace __gnu_pbds;

// order statistic tree, change null_type to something else to get a map
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
	ll c0, c1, c01, c10;
	node(): c0(0), c1(0), c01(0), c10(0) { }
	node(ll x): c0(!x), c1(x), c01(0), c10(0) { }
	node operator+(node n) {
		node res;
		res.c0 = c0 + n.c0;
		res.c1 = c1 + n.c1;
		res.c01 = c01 + n.c01 + c0*n.c1;
		res.c10 = c10 + n.c10 + c1*n.c0;
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i], a[i]--;

	vl ai(n);
	FOR(i,0,n) ai[a[i]] = i;
	
	vector<node> leaves(n,node(0));
	segtree<node> S(leaves);
	
	ordered_set<ll> indices;

	vl inv(n), res(n);
	FOR(k,0,n) {
		ll i = ai[k];
		inv[k] = S.query(i,n).c1;
		if (k > 0) inv[k] += inv[k-1];
		
		indices.insert(i);
		S.update(i, node(1));
		
		res[k] = inv[k];
		
		ll m = *indices.find_by_order(k/2);
		res[k] += S.query(0,m).c10;
		res[k] += S.query(m+1,n).c01;
	}

//	FOR(i,0,n) cout << inv[i] << " \n"[i+1==n];
	FOR(i,0,n) cout << res[i] << " \n"[i+1==n];
}