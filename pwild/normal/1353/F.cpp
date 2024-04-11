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

const ll N = 105;
ll a[N][N], dp[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll m, n;
		cin >> m >> n;

		vector<tuple<ll,ll,ll>> cells;
		FOR(i,0,m) FOR(j,0,n) {
			ll x; cin >> x;
			x -= i+j;
			cells.eb(x,i,j);
		}
		sort(all(cells));
		reverse(all(cells));
	
		memset(a,0x3f,sizeof a);
		memset(dp,0x3f,sizeof dp);
		
		ll res = oo;
		for (auto [x,si,sj]: cells) {
			a[si][sj] = x;
			FOR(i,si,m) FOR(j,sj,n) {
				ll prev = oo;
				if (i) prev = min(prev,dp[i-1][j]);
				if (j) prev = min(prev,dp[i][j-1]);
				if (!i && !j) prev = 0;
				dp[i][j] = min(dp[i][j], prev + a[i][j]);
			}	
			res = min(res, dp[m-1][n-1] - (m+n-1)*x);
		}
		cout << res << endl;
	}

}