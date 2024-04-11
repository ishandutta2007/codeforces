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

	vector<pll> a(n);
	FOR(i,0,n) {
		ll x, s;
		cin >> x >> s;
		a[i] = {x-s,x+s};
	}
	sort(all(a));
	a.erase(unique(all(a)),end(a));
	n = sz(a);
	
	vector<pll> b;
	FOR(i,0,n) {
		bool ok = true;
		FOR(j,0,n) if (j != i && a[j].xx <= a[i].xx && a[i].yy <= a[j].yy) ok = false;
		if (ok) b.pb(a[i]);
	}
	a = b, n = sz(a);
	sort(all(a));
	
	vl dp(m+1,oo);
	dp[0] = 0;

	for (auto [l,r]: a) {
		vl ndp = dp;
		FOR(a,0,m+1) {
			ll nl = max(0LL, l-a-1), nr = min(m, r+a);
			ndp[nr] = min(ndp[nr], a + dp[nl]);
		}
		FORD(x,0,m) ndp[x] = min(ndp[x],ndp[x+1]);
		dp = ndp;
	}
	cout << dp[m] << endl;
}