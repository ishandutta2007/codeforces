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
	
	ll n, k;
	cin >> n >> k;

	map<pll, vl> rays;
	FOR(i,0,n) {
		ll x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) continue;
		
		ll g = abs(gcd(x,y));
		x /= g, y /= g;
		
		rays[mp(x,y)].pb(g);
	}

	vector<pair<pll,ll>> values;
	map<pll, vl> ray_vals;
	values.eb(mp(0,0),0);
	for (auto [pr,dists]: rays) {
//		auto [x,y] = pr;
//		ll len2 = x*x + y*y;
		
		ll m = sz(dists);
		sort(all(dists));
		
		ll i = m-1, w = k-1;
		while (w >= 0 && i >= 0) {
			ll cur = dists[i] * w;
			values.eb(pr,cur);
			ray_vals[pr].pb(cur);
			i--, w -= 2;
		}
		ll s = 0;
		FOR(j,0,i+1) {
			ll cur = -2*s + w*dists[j];
			values.eb(pr,cur);
			ray_vals[pr].pb(cur);
			s += dists[j];
		}
	}
	assert(sz(values) == n);

	auto eval = [&](pair<pll,ll> a) {
		auto [x,y] = a.xx;
		// return (__int128(x*x + y*y) * a.yy) * a.yy;
		return sqrt(x*x + y*y)*a.yy;
	};

	sort(all(values), [&](pair<pll,ll> a, pair<pll,ll> b) {
	//	if ((a.yy < 0) != (b.yy < 0)) return a.yy > b.yy;
		return eval(a) > eval(b); 
	});
	
	map<pll,ll> ray_cnt;
	FOR(i,0,k) ray_cnt[values[i].xx]++;

	long double res = 0;
	for (auto [pr,ki]: ray_cnt) {
		auto [x,y] = pr;
		
		if (x == 0 && y == 0) continue;

		auto vec = ray_vals[pr];
		sort(all(vec),greater<ll>());

		ll cur = 0;
		FOR(i,0,ki) cur += vec[i];
		res += sqrt(x*x + y*y) * cur;

	}
	cout << fixed << setprecision(20) << res << endl;
	
}