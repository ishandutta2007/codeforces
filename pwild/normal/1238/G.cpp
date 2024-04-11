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

ll solve() {
	ll n, T, init, cap;
	cin >> n >> T >> cap >> init;
	vl time(n+1), amount(n+1), cost(n+1);
	amount[0] = init;
	FOR(i,1,n+1) cin >> time[i] >> amount[i] >> cost[i];
	
	vector<pll> events = {{T,oo}};
	FOR(i,0,n+1) events.eb(time[i],i);
	sort(all(events));
	
	ll V = 0;
	set<pll> S;
	ll res = 0;
	FOR(k,0,n+1) {
		auto [cur,i] = events[k];
		
		S.emplace(cost[i],i);
		V += amount[i];
		while (V > cap) {
			ll i = S.rbegin()->yy;
			ll take = min(amount[i],V-cap);
			amount[i] -= take, V -= take;
			if (amount[i] == 0) S.erase(mp(cost[i],i));
		}

		ll nxt = events[k+1].xx;
		ll diff = nxt-cur;
		while (diff > 0) {
			if (S.empty()) return -1;
			ll i = begin(S)->yy;
			ll take = min(amount[i],diff);
			amount[i] -= take, diff -= take, V -= take;
			if (amount[i] == 0) S.erase(begin(S));
			res += take * cost[i];
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) cout << solve() << endl;
}