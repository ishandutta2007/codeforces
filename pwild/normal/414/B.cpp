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
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k; cin >> n >> k;
	
	vvl div(n+1);
	FOR(i,1,n+1) FOR(j,1,i+1) if (i % j == 0) div[i].pb(j);
	
	vvl dp(k+1,vl(n+1,0));
	dp[0][1] = 1;
	FOR(i,1,k+1) FOR(j,1,n+1) for (const ll &jj: div[j]) {
		dp[i][j] = (dp[i][j] + dp[i-1][jj]) % MOD;
	}

	ll res = 0;
	FOR(j,1,n+1) res = (res + dp[k][j]) % MOD;
	cout << res << endl;


}