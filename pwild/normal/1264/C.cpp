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

const ll MOD = 998244353;

ll exp_mod(ll a, ll n) {
	ll res = 1;
	for (; n; n /= 2) {
		if (n%2) res = res*a % MOD;
		a = a*a % MOD;
	}
	return res;
}

ll inv_mod(ll a) { return exp_mod(a,MOD-2); }

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
	ll len, prod, sum;
	node(): len(0), prod(1), sum(0) { }
	node(ll p): len(1), prod(p), sum((MOD+1-p)%MOD) { }

	node operator+(node n) {
		node res;
		res.len = len + n.len;
		res.prod = prod * n.prod % MOD;
		res.sum = (sum + prod * n.sum + len * prod % MOD * (MOD + 1 - n.prod)) % MOD;
		return res;
	}

	ll eval() {
		return (len + sum * inv_mod(prod)) % MOD;
	}

	bool operator==(node n) {
		if (len != n.len) return false;
		if ((prod-n.prod) % MOD) return false;
		if ((sum-n.sum) % MOD) return false;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, q;
	cin >> n >> q;
	
	vector<node> leaves(n);
	FOR(i,0,n) {
		ll x; cin >> x;
		leaves[i] = node(x * inv_mod(100) % MOD);
	}

	segtree<node> S(leaves);

	auto exp_val = [&](ll i, ll j) {
		node cur = S.query(i,j);
		return cur.eval();
	};

	set<ll> indices = {0,n};

/*
	node zero;
	FOR(i,0,n) FOR(j,i+1,n+1) {
		node cur = S.query(i,j);
		assert( cur + zero == cur );
		assert( zero + cur == cur );
		cout << i << " " << j << " " << cur.len << " " << cur.prod << " " << cur.sum << " " << exp_val(i,j) << endl;
	}
*/

	ll res = exp_val(0,n);

	while (q--) {
		ll j; cin >> j;
		j--;

		auto it = indices.lower_bound(j);
		if (*it == j) {
			ll i = *prev(it), k = *next(it);
			indices.erase(j);
			res = (res - exp_val(i,j) - exp_val(j,k) + exp_val(i,k)) % MOD;
		} else {
			ll i = *prev(it), k = *it;
			indices.insert(j);
			res = (res + exp_val(i,j) + exp_val(j,k) - exp_val(i,k)) % MOD;
		}

		if (res < 0) res += MOD;
		cout << res << endl;
	}
}