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
	
	vector<string> prefs = {"","o","t","on","tw","one","two"};
	vvl adj(7,vl(26));
	FOR(i,0,7) FOR(k,0,26) {
		string s = prefs[i] + char('a'+k);
		FOR(j,0,7) {
			string t = prefs[j];
			if (sz(s) >= sz(t) && s.substr(sz(s)-sz(t)) == t) {
				adj[i][k] = j;
			}
		}
	}

	ll tc; cin >> tc;
	while (tc--) {
		string a; cin >> a;

		ll n = sz(a);
		vvl dp(n+1,vl(5));

		FORD(i,0,n) FOR(j,0,5) {
			dp[i][j] = 1 + dp[i+1][j];
			ll nj = adj[j][a[i]-'a'];
			if (nj < 5) dp[i][j] = min(dp[i][j], dp[i+1][nj]);
		}
		
		ll res = dp[0][0];
		cout << res << endl;
		ll j = 0;
		FOR(i,0,n) {
			if (dp[i][j] == 1 + dp[i+1][j]) {
				cout << i+1 << " ";
			} else {
				j = adj[j][a[i]-'a'];
			}
		}
		cout << endl;
	}
}