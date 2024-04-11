#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f;
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
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const ll N = 1010;
ll a[N], dp[8][N][11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	FOR(i,0,n) cin >> a[i], a[i]--;

	memset(dp,0x3f,sizeof dp);
	
	FORD(i,0,n) {
		FOR(d,0,8) dp[d][i][0] = dp[d][i+1][0];
		dp[a[i]][i][0] = i+1;
	}
	
	FOR(d,0,8) FOR(k,1,11) FOR(i,0,n) {
		if (dp[d][i][k-1] == oo) continue;
		dp[d][i][k] = dp[d][ dp[d][i][k-1] ][k-1];
	}

	auto step = [&](ll d, ll i, ll c) {
		FORD(k,0,11) if (c & (1 << k)) {
			if (i == oo) return oo;
			i = dp[d][i][k];
		}
		return i;
	};
	
	ll res = 0;
	
	cerr << "dp" << endl;

	vl p(8);
	iota(all(p),0);
	do {
		
		auto test = [&](ll c, ll mask) {
			ll i = 0;
			FOR(j,0,8) {
				i = step(p[j],i,c + !!(mask & (1 << j)));
				if (i == oo) return false;
			}
			return true;
		};
		
		FOR(mask,0,255) {
			ll x = res - __builtin_popcount(mask), c;
			if (x < 0) c = 0;
			else c = x/8 + 1;
			if (!test(c,mask)) continue;
			c++;
			while (test(c,mask)) c++;
			c--;
			res = max(res,8*c + __builtin_popcount(mask));
		}
	} while (next_permutation(all(p)));
	
	cout << res << endl;

/*	
	vvl dp(256,vl(8,-oo));
	FOR(j,0,8) dp[1 << j][j] = 0;

	for (ll k: a) {
		vvl ndp = dp;
		FOR(mask,0,256) FOR(j,0,8) if (dp[mask][j] > -oo) {
			if (j == k) {
				ndp[mask][j] = max(ndp[mask][j],dp[mask][j] + 1);
			} else {
				if (mask & (1 << j)) continue;
				ndp[mask | (1 << k)][k] = max(ndp[mask | (1 << k)][k],dp[mask][j] + 1);
			}
		}
		dp = ndp;
	}
	ll res = -oo;
	FOR(mask,0,256) FOR(j,0,8) res = max(res,dp[mask][j]);
	cout << res << endl;
*/
}