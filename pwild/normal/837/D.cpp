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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k; cin >> n >> k;

	ll N = 30 * n;
	vvl dp(k+1,vl(N,-oo));
	dp[0][0] = 0;

	FOR(i,0,n) {
		ll a, c2 = 0, c5 = 0;
		cin >> a;
		while (a % 2 == 0) c2++, a /= 2;
		while (a % 5 == 0) c5++, a /= 5;
		
		FORD(j,0,k) FOR(b5,0,N) if (dp[j][b5] > -oo) {
			dp[j+1][b5+c5] = max(dp[j+1][b5+c5], dp[j][b5] + c2);
		}
	}
	
	ll res = 0;
	FOR(b5,0,N) res = max(res, min(b5,dp[k][b5]));
	cout << res << endl;
}