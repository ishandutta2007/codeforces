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

const ll N = 1010;

typedef bitset<N> bs;

ll query(vl a) {
	if (sz(a) == 0) return 0;
	cout << "? " << sz(a);
	for (ll x: a) cout << " " << x+1;
	cout << endl;

	ll res; cin >> res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	const ll m = 13;
	vector<bs> dp(1 << m);
	vl masks(N);
	
	ll p = 0;
	FORD(mask,0,1 << m) {
		dp[mask].set();
		ll k = __builtin_popcount(mask);
		if (k == m/2 && p < N) {
			masks[p] = mask;
			dp[mask][p++] = 0;
		}
		FOR(i,0,m) if (!(mask & (1 << i))) dp[mask] &= dp[mask ^ (1 << i)];
	}
	
	ll n; cin >> n;

	vl b(m);
	FOR(i,0,m) {
		vl a;
		FOR(j,0,n) if (dp[1 << i][j]) a.pb(j);
		b[i] = query(a);
	}
	
	cout << "!";
	FOR(j,0,n) {
		ll res = 0;
		FOR(i,0,m) if (masks[j] & (1 << i)) res |= b[i];
		cout << " " << res;
	}
	cout << endl;
}