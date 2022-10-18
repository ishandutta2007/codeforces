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

bool can_split(string a, string b, string c) {
	ll m = sz(a), n = sz(b), p = sz(c);

	vvl next_occ(m+1,vl(26,m));
	FORD(i,0,m) {
		next_occ[i] = next_occ[i+1];
		next_occ[i][ a[i]-'a' ] = i;
	}

	vvl dp(n+1,vl(p+1,m+1));
	dp[0][0] = 0;
	FOR(j,0,n+1) FOR(k,0,p+1) {
		ll i = dp[j][k];
		if (i > m) continue;

		if (j < n) {
			dp[j+1][k] = min(dp[j+1][k], next_occ[i][ b[j]-'a' ] + 1);
		}
		if (k < p) {
			dp[j][k+1] = min(dp[j][k+1], next_occ[i][ c[k]-'a' ] + 1);
		}
	}
	return dp[n][p] <= m;
}

bool solve() {
	string a, b;
	cin >> a >> b;

	FOR(i,0,sz(b)) {
		if (can_split(a, b.substr(0,i), b.substr(i))) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) cout << (solve() ? "YES" : "NO") << endl;
}