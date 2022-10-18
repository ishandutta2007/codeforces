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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	sort(all(a));

	map<ll,ll> cnt;
	for (ll x: a) cnt[x]++;

	ll sum = accumulate(all(a),0);

	vvl dp(n+1,vl(sum+1));
	dp[0][0] = 1;
	for (pll p: cnt) {
		vvl ndp(n+1,vl(sum+1));
		
		FOR(i,0,n+1) FOR(s,0,sum+1) if (dp[i][s]) {
			FOR(take,0,p.yy+1) {
				ndp[i+take][s+take*p.xx] += dp[i][s];
			}
		}
		
		for (vl &v: ndp) for (ll &x: v) x = min(x,2LL);
		dp = ndp;
	}
	
	ll res = 0;
	for (pll p: cnt) {
		FOR(take,1,p.yy+1) {
			ll s = p.xx*take;
			if (dp[take][s] == 1) {
				ll cur = take;
				if (take == p.yy && sz(cnt) == 2) cur = n;
				res = max(res,cur);
			}
		}
	}
	cout << res << endl;
}