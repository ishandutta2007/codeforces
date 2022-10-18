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
	
	ll n; cin >> n;
	vl dp(10,-oo);
	dp[0] = 0;
	
	while (n--) {
		vl ndp = dp;
		
		ll k; cin >> k;
		vvl by_cost(4);
		while (k--) {
			ll c, d;
			cin >> c >> d;
			by_cost[c].pb(d);
		}
		FOR(c,1,4) sort(all(by_cost[c]),greater<ll>());
		
		vector<pll> cards;
		FOR(c,1,4) FOR(i,0,min(4-c,sz(by_cost[c]))) cards.eb(c,by_cost[c][i]);
		
		k = sz(cards);
		FOR(mask,0,1 << k) {
			vector<pll> v;
			FOR(i,0,k) if (mask & (1 << i)) v.pb(cards[i]);
			
			ll cost = 0;
			for (pll p: v) cost += p.xx;
			if (cost > 3) continue;
			
			sort(all(v));
			do {
				FOR(s,0,10) {
					ll cur = dp[s];
					FOR(i,0,sz(v)) {
						cur += v[i].yy;
						if (s+i == 9) cur += v[i].yy;
					}
					ll ns = (s+sz(v))%10;
					ndp[ns] = max(ndp[ns], cur);
				}
			} while (next_permutation(all(v)));
		}

		dp = ndp;
	}
	
	cout << *max_element(all(dp)) << endl;
}