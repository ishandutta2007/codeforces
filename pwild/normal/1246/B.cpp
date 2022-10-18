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
	
	ll M = 100100;
	vl cnt(M+1);
	
	ll res = 0;
	FOR(i,0,n) {
		ll x; cin >> x;
		vector<pll> pf;
		for (ll p = 2; p*p <= x; p++) {
			if (x%p) continue;
			ll e = 0;
			while (x%p == 0) x /= p, e++;
			pf.eb(p,e%k);
		}
		if (x > 1) pf.eb(x,1);
		
		x = 1;
		ll y = 1;
		for (auto [p,e]: pf) {
			FOR(j,0,e) x = min(x*p,M);
			FOR(j,0,(k-e)%k) y = min(y*p,M);
		}
		
		res += cnt[y];
		cnt[x]++;
	}
	cout << res << endl;
}