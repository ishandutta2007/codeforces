#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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

vvl automaton(string s) {
	ll n = sz(s);

	vvl res(n+1,vl(26,0));
	FOR(i,0,n+1) FOR(j,0,26) {
		string t = s.substr(0,i) + char('a'+j);
		FOR(k,0,i+2) if (k <= sz(s) && t.substr(i+1-k) == s.substr(0,k)) res[i][j] = k;
	}
	return res;
}


const ll N = 1010, K = 55;
ll dp[N][K][K];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s, a, b;
	cin >> s >> a >> b;
	
	ll n = sz(s);
	vvl p = automaton(a);
	vvl q = automaton(b);
	
	memset(dp,0xbf,sizeof dp);
	dp[0][0][0] = 0;
	
	FOR(i,0,n) FOR(j,0,sz(a)+1) FOR(k,0,sz(b)+1) {
		if (dp[i][j][k] < -1e5) continue;
		//cerr << i << " " << j << " " << k << " " << dp[i][j][k] << endl;

		char cmin = s[i] == '*' ? 'a' : s[i];
		char cmax = s[i] == '*' ? 'z' : s[i];
		for (char c = cmin; c <= cmax; c++) {
			ll nj = p[j][c-'a'];
			ll nk = q[k][c-'a'];
			ll nval = dp[i][j][k];
			if (nj == sz(a)) nval++;
			if (nk == sz(b)) nval--;
			
			dp[i+1][nj][nk] = max(dp[i+1][nj][nk], nval);
		}
	}
	ll res = -1e5;
	FOR(j,0,sz(a)+1) FOR(k,0,sz(b)+1) res = max(res, dp[n][j][k]);
	cout << res << endl;
}