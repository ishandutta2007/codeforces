#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const int oo = 0x3f3f3f3f;
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

int dp[101][1 << 17], take[101][1 << 17];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll m = 60;
	vb pr(m,true);
	pr[0] = pr[1] = false;
	vl primes;
	FOR(i,2,m) if (pr[i]) {
		primes.pb(i);
		for (ll j = i*i; j < m; j += i) pr[j] = false;
	}
	ll p = sz(primes);
	vector<int> mask(m);
	FOR(i,1,m) FOR(j,0,p) if (i % primes[j] == 0) mask[i] |= 1 << j;

	ll n; cin >> n;
	vector<int> a(n);
	FOR(i,0,n) cin >> a[i];
	
	memset(dp,0x3f,sizeof(dp));
	dp[0][0] = 0;
	FOR(i,0,n) FOR(j,0,1 << p) if (dp[i][j] < oo) {
		FOR(k,0,m) if (!(j & mask[k])) {
			int nj = j ^ mask[k];
			int ndp = dp[i][j] + abs(a[i]-k);
			if (ndp < dp[i+1][nj]) {
				dp[i+1][nj] = ndp;
				take[i+1][nj] = k;
			}
		}
	}
	
	ll j = 0;
	FOR(jj,0,1 << p) if (dp[n][jj] < dp[n][j]) j = jj;
	vl b(n);
	FORD(i,0,n) {
		ll k = take[i+1][j];
		j ^= mask[k];
		b[i] = k;
	}
	FOR(i,0,n) cout << b[i] << " \n"[i==n-1];

}