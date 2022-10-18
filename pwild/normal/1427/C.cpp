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
	
	ll r, n;
	cin >> r >> n;

	vl t(n+1), x(n+1), y(n+1);
	x[0] = y[0] = 1;
	FOR(i,1,n+1) cin >> t[i] >> x[i] >> y[i];

	vl dp(n+1,-oo);
	dp[0] = 0;
	FOR(i,1,n+1) {
		FOR(j,max(i-4*r,0),i) {
			if (abs(x[i]-x[j]) + abs(y[i]-y[j]) > t[i]-t[j]) continue;
			dp[i] = max(dp[i],dp[j]+1);
		}
	}
	
	cout << *max_element(all(dp)) << endl;
}