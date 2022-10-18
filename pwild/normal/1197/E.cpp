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

const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n), b(n), val(n), cnt(n);

	vector<pll> events;
	FOR(i,0,n) {
		cin >> b[i] >> a[i];
		events.eb(b[i],~i);
		events.eb(a[i],i);
	}
	sort(all(events));
	
	map<ll,ll> best;
	best[0] = 1;

	
	for (auto ev: events) {
		ll i = ev.yy;
		if (i < 0) {
			i = ~i;
			ll x = val[i]-b[i];
			best[x] = (best[x] + cnt[i]) % MOD;
		} else {
			auto it = begin(best);
			assert(it->yy > 0);
			val[i] = it->xx + a[i];
			cnt[i] = it->yy;
		}
	}
	
	ll amax = *max_element(all(a));
	
	ll res = 0, valmin = oo;
	FOR(i,0,n) if (b[i] > amax) {
		if (val[i] > valmin) continue;
		if (val[i] < valmin) valmin = val[i], res = 0;
		res = (res + cnt[i]) % MOD;
	}
	cout << res << endl;
}