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

ll b[1010][1010];
const ll MOD = 1000000007;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	FOR(n,0,1010) {
		b[n][0] = b[n][n] = 1;
		FOR(k,1,n) b[n][k] = (b[n-1][k-1] + b[n-1][k]) % MOD;
	}

	ll k; cin >> k;
	vl c(k);
	FOR(i,0,k) cin >> c[i];
	
	ll fi = 1, sum = c[0];
	FOR(i,1,k) {
		fi = fi * b[sum+c[i]-1][c[i]-1] % MOD;
		sum += c[i];
	}
	cout << fi << endl;
}