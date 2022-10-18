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
	ll K = 34;
	vvl f(K,vl(n)), wsum(K,vl(n)), wmin(K,vl(n));
	FOR(i,0,n) cin >> f[0][i];
	FOR(i,0,n) cin >> wsum[0][i], wmin[0][i] = wsum[0][i];
	
	FOR(d,0,K-1) FOR(i,0,n) {
		f[d+1][i] = f[d][f[d][i]];
		wmin[d+1][i] = min(wmin[d][i],wmin[d][f[d][i]]);
		wsum[d+1][i] = wsum[d][i] + wsum[d][f[d][i]];
	}
	
	FOR(i,0,n) {
		ll csum = 0, cmin = INT_MAX, j = i;
		FOR(d,0,K) if (k & (1LL << d)) {
			csum += wsum[d][j];
			cmin = min(cmin,wmin[d][j]);
			j = f[d][j];
		}
		cout << csum << " " << cmin << "\n";
	}

}