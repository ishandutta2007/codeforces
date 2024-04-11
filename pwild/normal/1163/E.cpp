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

bool find_base(vl a, ll k, vl &b) {
	ll n = 0;
	while (n < sz(a) && a[n] < (1 << k)) n++;
	a.resize(n);
	FOR(i,0,k) {
		bool found = false;
		FOR(j,0,n) if (a[j] & (1 << i)) {
			b.pb(j);
			ll x = a[j];
			FOR(jj,0,n) if (a[jj] & (1 << i)) a[jj] ^= x;
			found = true;
			break;
		}
		if (!found) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	sort(all(a));
	
	FORD(k,0,20) {
		vl b;
		if (!find_base(a,k,b)) continue;
		
		vl res = {0};
		for (ll i: b) {
			ll x = a[i];
			ll t = sz(res);
			FORD(i,0,t) res.pb(res[i]^x);
		}
		
		cout << k << endl;
		for (ll x: res) cout << x << " ";
		cout << endl;

		return 0;
	}
}