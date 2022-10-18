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

const ll N = 510;
ll a[N], shr[N][N], dp[N];

ll shrink(ll i, ll j) {
	if (i >= j) return -2;
	if (i+1 == j) return shr[i][j] = a[i];
	if (shr[i][j] != -1) return shr[i][j];
	
	FOR(k,i+1,j) {
		ll x = shrink(i,k), y = shrink(k,j);
		if (x >= 0 && y >= 0 && x == y) return shr[i][j] = x+1;
	}
	return shr[i][j] = -2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	FOR(i,0,n) cin >> a[i];
	
	memset(shr,-1,sizeof shr);
	
	FOR(k,1,n+1) {
		dp[k] = k;
		FOR(i,0,k) if (shrink(i,k) >= 0) {
			dp[k] = min(dp[k], dp[i] + 1);
		}
	}
	cout << dp[n] << endl;
}