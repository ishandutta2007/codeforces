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
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

// dp[i][j][k] = if the j-th 1 is at position i, and k moves were made to move
//               the first j 1s, what is the total least number of unprotected pairs?

// TODO check m == 0

ll n, m = 0;
ll a[85], dp[85][85][3333];

ll tri(ll i) { return i*(i-1)/2; }

ll rec(ll i, ll j, ll k) {
	if (k < abs(i-a[j])) return oo;
	if (j == 0) return tri(i);
	if (dp[i][j][k] != -1) return dp[i][j][k];

	ll res = oo;
	FOR(h,j-1,i) {
		ll add = tri(i-h-1), nk = k - abs(i-a[j]);
		res = min(res, rec(h,j-1,nk) + add);
	}
	return dp[i][j][k] = res;
}

ll solve(ll k) {
	if (m == 0) return 0;
	ll res = oo;
	FOR(i,0,n) res = min(res, rec(i,m-1,k) + tri(n-i-1));
	return tri(n-m) - res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(dp,-1,sizeof dp);

	cin >> n;
	FOR(i,0,n) {
		ll x; cin >> x;
		if (x) a[m++] = i;
	}
	
	FOR(k,0,tri(n)+1) cout << solve(k) << " ";
	cout << endl;


}