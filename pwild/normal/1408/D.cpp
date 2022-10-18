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
	
	ll m, n;
	cin >> m >> n;

	vl ax(m), ay(m), bx(n), by(n);
	FOR(i,0,m) cin >> ax[i] >> ay[i];
	FOR(i,0,n) cin >> bx[i] >> by[i];
	
	ll N = 1e6 + 10;
	vl dp(N,-1);
	FOR(i,0,m) FOR(j,0,n) {
		ll dx = bx[j]-ax[i];
		ll dy = by[j]-ay[i];
//		cerr << dx << " " << dy << endl;
		if (dx < 0 || dy < 0) continue;
		dp[dx] = max(dp[dx], dy);
	}
	FORD(k,0,N-1) dp[k] = max(dp[k], dp[k+1]);
	
//	FOR(k,0,N) if (dp[k] >= 0) cout << dp[k] << " ";
//	cout << endl;

	ll res = oo;
	FOR(k,0,N) res = min(res, k+dp[k]+1);
	cout << res << endl;
}