#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

int dp[2110][2110][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s, t; cin >> s >> t;
	ll m = sz(s), n = sz(t);

	memset(dp,0x3f,sizeof(dp));
	
	FOR(i,0,m) if (s[i] == t[0]) dp[0][i][0] = dp[0][i][1] = 1;
	FOR(j,1,n) {
		int best = oo;
		FOR(i,0,m) FOR(k,0,2) best = min(best,dp[j-1][i][k]);
		
		FOR(i,0,m) FOR(k,0,2) if (s[i] == t[j]) dp[j][i][k] = best + 1;
		FOR(i,1,m) if (s[i] == t[j]) dp[j][i][0] = min(dp[j][i][0],dp[j-1][i-1][0]);
		FOR(i,0,m-1) if (s[i] == t[j]) dp[j][i][1] = min(dp[j][i][1],dp[j-1][i+1][1]);
	}
	
	ll j = n-1;
	vector<pll> res;
	while (j >= 0) {
		int best = oo, i = -1;
		FOR(ii,0,m) FOR(k,0,2) if (dp[j][ii][k] < best) i = ii, best = dp[j][ii][k];
		if (best == oo) {
			cout << -1 << endl;
			return 0;
		}
		pll cur;
		cur.yy = i+1;
		if (dp[j][i][0] < dp[j][i][1]) {
			while (j > 0 && i > 0 && dp[j-1][i-1][0] == dp[j][i][0]) j--, i--;
		} else {
			while (j > 0 && i+1 < m && dp[j-1][i+1][1] == dp[j][i][1]) j--, i++;
		}
		cur.xx = i+1;
		res.pb(cur);
		j--;
	}
	


	reverse(all(res));
	cout << sz(res) << endl;
	for (const pll &p: res) cout << p.xx << " " << p.yy << endl;








}