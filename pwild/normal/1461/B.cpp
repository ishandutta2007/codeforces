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

	ll tc; cin >> tc;
	while (tc--) {
		ll m, n;
		cin >> m >> n;
		
		vector<string> a(m);
		FOR(i,0,m) cin >> a[i];

		vvl dp(m, vl(n,-1));
		function<ll(ll,ll)> rec = [&](ll i, ll j) {
			if (i < 0 || i >= m || j < 0 || j >= n) return 0LL;
			if (a[i][j] == '.') return 0LL;
			if (dp[i][j] != -1) return dp[i][j];
			return dp[i][j] = 1 + min(rec(i+1,j-1), min(rec(i+1,j), rec(i+1,j+1)));
		};
		
		ll res = 0;
		FOR(i,0,m) FOR(j,0,n) res += rec(i,j);
		cout << res << endl;
	}

}