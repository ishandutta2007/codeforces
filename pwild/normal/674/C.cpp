#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
//const ll oo = 0x3f3f3f3f3f3f3f3f;
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

typedef pair<double,double> pdd;

const ll maxN = 200010, maxK = 52;
double dp[maxK][maxN];
ll A[maxK][maxN];
double t[maxN], tsum[maxN], tisum[maxN], ttsum[maxN];

double cost(ll i, ll j) {
	return ttsum[j] - ttsum[i] - tsum[i]*(tisum[j]-tisum[i]);
}

void rec(ll i, ll l, ll r, ll jmin, ll jmax) {
	if (l > r) return;
	ll m = (l+r)/2;
	dp[i][m] = 1e100;
	FOR(j,jmin,jmax+1) {
		if (j >= m) break;
		double cur = dp[i-1][j] + cost(j,m);
		if (cur < dp[i][m] - eps) {
			dp[i][m] = cur;
			A[i][m] = j;
		}
	}
	if (l == r) return;
	rec(i,l,m-1,jmin,A[i][m]);
	rec(i,m+1,r,A[i][m],jmax);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k; cin >> n >> k;
	FOR(i,0,n) cin >> t[i];
	tsum[0] = 0;
	FOR(i,0,n) tsum[i+1] = tsum[i] + t[i];
	tisum[0] = 0;
	FOR(i,0,n) tisum[i+1] = tisum[i] + 1.0/t[i];
	ttsum[0] = 0;
	FOR(i,0,n) ttsum[i+1] = ttsum[i] + tsum[i+1]/t[i];

	//FOR(i,0,n) FOR(j,i+1,n+1) cout << i << " " << j << " " <<  cost(i,j) << endl;

	dp[0][0] = 0;
	FOR(j,1,n+1) dp[0][j] = 1e100;
	
	FOR(i,1,k+1) {
		auto a = [&](ll j) { return mp(tsum[j],dp[i-1][j] - ttsum[j] + tsum[j]*tisum[j]); };
		auto eval = [&](pdd p, double x) { return p.xx*x + p.yy; };
		auto bad = [&](pdd a, pdd b, pdd c) { 
			return (b.xx-a.xx)*(c.yy-b.yy) < (c.xx-b.xx)*(b.yy-a.yy); 
		};
		vector<pdd> v;
		dp[i][0] = 1e100;
		v.eb(a(0));
		ll p = 0, len = 1;
		FOR(j,1,n+1) {
			if (p >= len) p = len-1;
			double x = -tisum[j];
			while(p+1 < len && eval(v[p+1],x) < eval(v[p],x)) p++;
			dp[i][j] = ttsum[j] + eval(v[p],x);
			pdd w = a(j);
			while (len >= 2 && bad(v[len-2],v[len-1],w)) v.pop_back(), len--;
			v.pb(w), len++;
		}
	}

	cout << fixed << setprecision(12) << dp[k][n] << endl;

}