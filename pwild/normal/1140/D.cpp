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
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

const ll N = 510;
ll dp[N][N];

ll n;

ll cost(ll i, ll j, ll k) {
	return (1+i%n) * (1+j%n) * (1+k%n);
}

ll rec(ll i, ll j) {
	i %= n, j %= n;
	ll &res = dp[i][j];
	if (res != oo) return res;
	
	if (j < i) j += n;
	if (i+1 == j) return 0;

	FOR(k,i+1,j) {
		res = min(res, cost(i,k,j) + rec(i,k) + rec(k,j));
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	memset(dp,0x3f,sizeof dp);
	
	ll res = oo, k = 0;
	FOR(i,1,n) FOR(j,i+1,n) res = min(res, cost(i,j,k) + rec(i,j) + rec(j,k) + rec(k,i));
	cout << res << endl;
}