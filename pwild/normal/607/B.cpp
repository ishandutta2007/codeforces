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

ll a[510];
ll dp[510][510];

ll rec(ll i, ll j) {
	if (i == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	ll res = rec(i+1,j) + 1;
	FOR(k,i+1,j) if (a[k] == a[i]) res = min(res,max(1LL,rec(i+1,k))+rec(k+1,j));
	return dp[i][j] = res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(dp,-1,sizeof(dp));
	ll n; cin >> n;
	FOR(i,0,n) cin >> a[i];
	cout << rec(0,n) << endl;

}