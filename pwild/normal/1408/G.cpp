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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	
	vvl a(n, vl(n));
	FOR(i,0,n) FOR(j,0,n) cin >> a[i][j];

	vector<tuple<ll,ll,ll>> edges;
	FOR(i,0,n) FOR(j,i+1,n) edges.eb(a[i][j],i,j);
	sort(all(edges));
	
	vl pos(n);
	iota(all(pos),0);
	vvl v(n);
	FOR(i,0,n) v[i] = {i};
	vl left(2*n-1), right(2*n-1);
	vl ec(2*n-1);

	for (auto [c,i,j]: edges) {
		if (pos[i] == pos[j]) {
			ec[pos[i]]++;
			continue;
		}
		left[sz(v)] = pos[i];
		right[sz(v)] = pos[j];
		ec[sz(v)] = 1 + ec[pos[i]] + ec[pos[j]];
		vl w = v[pos[i]];
		for (ll x: v[pos[j]]) w.pb(x);
		for (ll x: w) pos[x] = sz(v);
		v.pb(w);
	}
	
	vvl dp(2*n-1);
	FOR(i,0,n) dp[i] = {1};
	
	FOR(i,n,2*n-1) {
		ll m = sz(v[i]);
		dp[i].resize(m);
		ll j = left[i], k = right[i];

		dp[i][0] = ec[i] == m*(m-1)/2;
		FOR(a,0,sz(dp[j])) FOR(b,0,sz(dp[k])) {
			dp[i][a+b+1] = (dp[i][a+b+1] + dp[j][a]*dp[k][b]) % MOD;
		}
	}
	
	for (ll x: dp.back()) cout << x << " ";
	cout << endl;
}