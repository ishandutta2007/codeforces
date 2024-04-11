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
	
	ll n; cin >> n;
	
	vvl adj(n,vl(n,oo));
	FOR(i,0,n) FOR(j,0,n) {
		char c; cin >> c;
		if (c == '0') adj[i][j] = oo*(i!=j);
		else adj[i][j] = 1;
	}
	FOR(k,0,n) FOR(i,0,n) FOR(j,0,n) adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]); 
	
	ll m; cin >> m;
	vl p(m);
	FOR(i,0,m) cin >> p[i], p[i]--;
	
	vl dp(m,oo), go(m,13452345);
	dp[m-1] = 1;
	FORD(i,0,m-1) {
		FOR(j,i+1,m) {
			if (adj[ p[i] ][ p[j] ] != j-i) break;
			if (dp[j]+1 < dp[i]) {
				dp[i] = dp[j]+1, go[i] = j;
			}
		}
	}
	
	cout << dp[0] << endl;
	ll i = 0;
	while (i < m-1) {
		cout << p[i]+1 << " ";
		i = go[i];
	}
	cout << p[m-1]+1 << endl;
}