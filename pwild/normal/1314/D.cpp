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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	mt19937_64 gen(23583);
	uniform_int_distribution<ll> dis(0,1);

	ll n, k;
	cin >> n >> k;
	
	vvl a;

	if (n < 0) {
		n = 80;
		a.resize(n, vl(n));
		FOR(i,0,n) FOR(j,0,n) if (i != j) a[i][j] = rand();
	} else {
		a.resize(n, vl(n));
		FOR(i,0,n) FOR(j,0,n) cin >> a[i][j];
	}

	ll res = oo;
	FOR(iter,0,10000) {
		vl col(n);
		FOR(i,0,n) col[i] = dis(gen);
		vl dp(n,oo);
		dp[0] = 0;
		FOR(s,0,k) {
			vl ndp(n,oo);
			FOR(i,0,n) FOR(j,0,n) if (col[i] != col[j]) {
				ndp[j] = min(ndp[j], dp[i] + a[i][j]);
			}
			dp = ndp;
		}
		res = min(res, dp[0]);
	}
	cout << res << endl;
}