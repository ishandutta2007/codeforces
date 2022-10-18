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
	
	ll n, p, k;
	cin >> n >> p >> k;

	vl a(n);
	FOR(i,0,n) cin >> a[i];
	vvl s(n,vl(p));
	FOR(i,0,n) FOR(j,0,p) cin >> s[i][j];
	
	vl is(n);
	iota(all(is),0);
	sort(all(is),[&](ll i, ll j) { return a[i] > a[j]; });

	vl dp(1 << p, -oo);
	dp[0] = 0;
	
	FOR(t,0,n) {
		ll i = is[t];
		vl ndp(1 << p, -oo);
		FOR(mask,0,1 << p) FOR(j,0,p) if (!(mask & (1 << j))) {
			ll nmask = mask | (1 << j);
			ndp[nmask] = max(ndp[nmask], dp[mask] + s[i][j]);
		}
		FOR(mask,0,1 << p) {
			bool take = t < k + __builtin_popcount(mask);
			ndp[mask] = max(ndp[mask], dp[mask] + take*a[i]);
		}
		dp = ndp;
	}
	cout << dp.back() << endl;
}