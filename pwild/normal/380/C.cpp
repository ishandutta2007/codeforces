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

template<typename T> struct segtree {
	ll n;
	
	T zero;
	vector<T> value;

	segtree<T>(ll n, T zero = T()): n(n), zero(zero) {
		value.resize(2*n,zero);
	}

	void set_leaves(vector<T> &leaves) {
		copy(all(leaves),begin(value)+n);
		FORD(i,1,n) value[i] = value[2*i] + value[2*i+1];
	}

	T query(ll i, ll j) {
		i += n, j += n;
		T resl = zero, resr = zero;
		for (; i < j; i /= 2, j /= 2) {
			if (i & 1) resl = resl + value[i++];
			if (j & 1) resr = value[--j] + resr;
		}
		return resl + resr;
	}

};

struct node {
	ll a, b, c;
	node operator+(node n) {
		ll t = min(b,n.c);
		return { a+n.a+2*t, b+n.b-t, c+n.c-t };
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;
	ll n = sz(s);
	
	segtree<node> t(n);
	vector<node> v(n);
	FOR(i,0,n) if (s[i] == '(') v[i] = {0,1,0}; else v[i] = {0,0,1};
	t.set_leaves(v);
	
	ll m; cin >> m;
	while (m--) {
		ll l, r; cin >> l >> r;
		cout << t.query(l-1,r).a << "\n";
	}
}