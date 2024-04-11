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
	
	ll n, m;
	cin >> n >> m;

	vl p(m), hs(m);
	iota(all(p),0);
	
	function<ll(ll)> find = [&](ll x) {
		if (p[x] == x) return x;
		return p[x] = find(p[x]);
	};

	vl res;
	FOR(i,0,n) {
		ll k; cin >> k;
		vl a(k);
		FOR(i,0,k) cin >> a[i], a[i]--;
		
		if (k == 1) {
			ll x = find(a[0]);
			if (!hs[x]) hs[x] = 1, res.pb(i);
		} else {
			ll x = find(a[0]), y = find(a[1]);
			if (x == y) continue;
			if (hs[x] && hs[y]) continue;
			if (rand() % 2) swap(x,y);
			p[x] = y, hs[y] += hs[x];
			res.pb(i);
		}	
	}
	
	ll x = 1;
	FOR(i,0,sz(res)) x = 2*x % MOD;
	cout << x << " " << sz(res) << endl;
	for (ll i: res) cout << i+1 << " ";
	cout << endl;
}