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

const ll MOD = 1e9 + 7;

ll mod_exp(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) res = res*a % MOD;
		a = a*a % MOD;
		n /= 2;
	}
	return res;
}

ll mod_inv(ll a) {
	a %= MOD;
	assert(a);
	return mod_exp(a,MOD-2);
}

vvl adj;

const ll N = 100100;
ll dp[N][2][2];

void rec1(ll i, ll p = -1) {
	for (ll j: adj[i]) if (j != p) {
		rec1(j,i);
	}

	FOR(k1,0,2) FOR(k2,0,2) {
		dp[i][k1][k2] = 1;
		for (ll j: adj[i]) if (j != p) {
			ll cur = dp[j][0][k1^k2] + dp[j][1][k1^k2];
			if (sz(adj[j]) == 1) cur = 1;
			dp[i][k1][k2] = dp[i][k1][k2] * cur % MOD;
		}
	}
}

ll res[N];

void rec2(ll i, ll p = -1) {
	res[i] = (dp[i][0][0] + dp[i][1][0]) % MOD;
	
	for (ll j: adj[i]) if (j != p) {
		ll ndpi[2][2];
		FOR(k1,0,2) FOR(k2,0,2) {
			ll cur = dp[j][0][k1^k2] + dp[j][1][k1^k2];
			if (sz(adj[j]) == 1) cur = 1;
			ndpi[k1][k2] = dp[i][k1][k2] * mod_inv(cur) % MOD;
		}
		
		FOR(k1,0,2) FOR(k2,0,2) {
			ll cur = ndpi[0][k1^k2] + ndpi[1][k1^k2];
			if (sz(adj[i]) == 1) cur = 1;
			dp[j][k1][k2] = dp[j][k1][k2] * cur % MOD;
		}
		rec2(j,i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	
	adj.resize(n);
	FOR(i,1,n) {
		ll a, b; cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	rec1(0);
	rec2(0);
	//FOR(i,0,n) cout << res[i] << endl;
	ll ans = 0;
	FOR(i,0,n) ans = (ans + res[i]) % MOD;
	cout << ans << endl;
}