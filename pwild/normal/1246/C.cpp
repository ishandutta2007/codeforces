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

const ll MOD = 1e9 + 7;

void self_add(ll &x, ll y) { x = (x+y) % MOD; }
void self_sub(ll &x, ll y) { x = (x+MOD-y) % MOD; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n;
	cin >> m >> n;

	if (m == 1 && n == 1) {
		cout << 1 << endl;
		return 0;
	}

	vector<string> a(m);
	FOR(i,0,m) cin >> a[i];
	
	vvl cntD(m,vl(n)), cntR(m,vl(n));
	FORD(i,1,m) FOR(j,0,n) cntD[i-1][j] = cntD[i][j] + (a[i][j] == 'R');
	FOR(i,0,m) FORD(j,1,n) cntR[i][j-1] = cntR[i][j] + (a[i][j] == 'R');

	vvl addD(m+1,vl(n)), addR(m,vl(n+1));
	addD[1][0] = -1, addR[0][1] = -1;

	vvl dpD(m,vl(n)), dpR(m,vl(n));
	dpD[0][0] = dpR[0][0] = 1;

	FOR(i,0,m) FOR(j,0,n) {
		if (i > 0) dpD[i][j] = (dpD[i-1][j] + addD[i][j]) % MOD;
		if (j > 0) dpR[i][j] = (dpR[i][j-1] + addR[i][j]) % MOD;
		
		ll imin = i+1, imax = m-cntD[i][j];
		self_add(addD[imin][j], dpR[i][j]);
		self_sub(addD[imax][j], dpR[i][j]);
		
		ll jmin = j+1, jmax = n-cntR[i][j];
		self_add(addR[i][jmin], dpD[i][j]);
		self_sub(addR[i][jmax], dpD[i][j]);
	}
	
	ll res = (dpR[m-1][n-1] + dpD[m-1][n-1]) % MOD;
	if (res < 0) res += MOD;
	cout << res << endl;
}