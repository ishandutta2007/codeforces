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
	
	ll na, nb, ta, tb, k;
	cin >> na >> nb >> ta >> tb >> k;

	vl a(na);
	FOR(i,0,na) cin >> a[i];

	vl b(nb);
	FOR(i,0,nb) cin >> b[i];
	
	ll tmin = 0, tmax = 2e9 + 10;

	while (tmax-tmin > 1) {
		ll t = (tmin+tmax)/2;
		
		ll mb = upper_bound(all(b),t-tb) - begin(b);

		bool can_block = false;
		FOR(ka,0,min(k,na)+1) {
			ll kb = min(k-ka,mb);
			
			if (ka == na || kb == mb || a[ka]+ta > b[mb-kb-1]) can_block = true;
		}
		if (can_block) tmin = t; else tmax = t;
	}
	
	if (tmax > 2e9) tmax = -1;
	cout << tmax << endl;
	


}