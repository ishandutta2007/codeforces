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
	
	ll n, m;
	cin >> n >> m;

	vl need(n);
	FOR(i,0,n) cin >> need[i];
	ll sum_need = accumulate(all(need),0LL);
	
	ll K = 4e5 + 10;
	vvl offers(K);
	while (m--) {
		ll d, i;
		cin >> d >> i;
		offers[d-1].pb(i-1);
	}
	
	ll tmin = sum_need-1, tmax = 2*sum_need;
	while (tmax-tmin > 1) {
		ll t = (tmin+tmax)/2;
		
		vl need_backup = need;

		ll rem = 2*sum_need-t;
		FORD(d,0,t) {
			if (rem > d+1) break;
			for (ll i: offers[d]) {
				ll take = min(need[i],rem);
				need[i] -= take, rem -= take;
			}
		}

		need = need_backup;

		if (rem > 0) tmin = t;
		else tmax = t;
	}
	cout << tmax << endl;
}