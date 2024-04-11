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
	ll x[2][2];
	node() { x[0][0] = x[1][1] = 0, x[0][1] = x[1][0] = -oo; }
	node(ll a) {
		x[0][0] = x[1][1] = 0;
		x[0][1] = a, x[1][0] = -a;
	}
	node operator+(node n) {
		node res;
		res.x[0][1] = res.x[1][0] = -oo;
		FOR(i,0,2) FOR(k,0,2) FOR(j,0,2) {
			res.x[i][j] = max(res.x[i][j], x[i][k]+n.x[k][j]);
		}
		return res;
	}
	ll value() {
		ll res = -oo;
		FOR(i,0,2) FOR(j,0,2) res = max(res, x[i][j]);
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n, q;
		cin >> n >> q;

		vl a(n);
		FOR(i,0,n) cin >> a[i];

		vector<node> leaves;
		FOR(i,0,n) leaves.eb(a[i]);
		segtree<node> S(leaves);

		cout << S.query(0,n).value() << endl;

		while (q--) {
			ll i, j;
			cin >> i >> j;
			i--, j--;
			swap(a[i],a[j]);
			S.update(i, node(a[i]));
			S.update(j, node(a[j]));

			cout << S.query(0,n).value() << "\n";
		}
	}
}