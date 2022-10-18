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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, k;
	cin >> n >> m >> k;

	vl need(n), get(n), imp(n);
	FOR(i,0,n) cin >> need[i] >> get[i] >> imp[i];
	
	vl latest(n);
	iota(all(latest),0);

	while (m--) {
		ll u, v;
		cin >> u >> v;
		u--, v--;
		latest[v] = max(latest[v], u);
	}
	
	vvl portals(n);
	FOR(i,0,n) portals[latest[i]].pb(imp[i]);
	
	const ll M = 5010;
	vl dp(M,-1);
	dp[k] = 0;
	
	FOR(i,0,n) {
		vl ndp(M,-1);
		FOR(cnt,need[i],M) if (dp[cnt] >= 0) {
			ndp[cnt+get[i]] = dp[cnt];
		}
		dp = ndp;

		vl val = portals[i];
		sort(all(val),greater<ll>());
		
		ll sum = 0, send = 0;
		for (ll x: val) {
			sum += x, send++;
			FOR(cnt,send,M) if (dp[cnt] >= 0) {
				ndp[cnt-send] = max(ndp[cnt-send], dp[cnt] + sum);
			}
		}
		dp = ndp;
	}
	
	ll res = *max_element(all(dp));
	cout << res << endl;
}