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
	ll x = -oo;
	node operator+(node n) { return {max(x,n.x)}; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll m, n, w;
	cin >> m >> n >> w;

	bool first_row = true;
	vl dp(n+1-w);
	
	while (m--) {
		vl a(n);
		FOR(i,0,n) cin >> a[i];
		
		vl ndp(n+1-w);
		
		FOR(dir,0,2) {
			vl s(n+1);
			FOR(i,0,n) s[i+1] = s[i] + a[i];

			if (dir == 0) FOR(i,0,n+1-w) dp[i] += s[i+w]-s[i];

			if (first_row) {
				first_row = false;
				ndp = dp;
				break;
			}

			ll best_disjoint = -oo;
			segtree<node> S(vector<node>(n+1-w));
			FOR(i,0,n+1-w) {
				S.update(i, {dp[i] - s[i+w]});
				ndp[i] = max(ndp[i], S.query(max(i-w,0LL), i+1).x + s[i+w]);
				ndp[i] = max(ndp[i], s[i+w] - s[i] + best_disjoint);
				if (i >= w) best_disjoint = max(best_disjoint, dp[i-w]);
			}

			reverse(all(dp)), reverse(all(ndp)), reverse(all(a));
		}
		
		dp = ndp;
	}
	
	cout << *max_element(all(dp)) << endl;
}