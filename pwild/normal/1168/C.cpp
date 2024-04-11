#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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
	
	ll n, q;
	cin >> n >> q;

	vl a(n+1);
	FOR(i,1,n+1) cin >> a[i];

	vb res(q);
	vector<vector<pll>> qat(n+1);

	FOR(i,0,q) {
		ll x, y;
		cin >> x >> y;
		qat[y].eb(x,i);
	}
	
	const ll K = 20;

	vvl dp(n+1,vl(K));
	vl next_with(K);

	FOR(i,1,n+1) {
		FOR(k,0,K) if (a[i] & (1 << k)) {
			ll j = next_with[k];
			FOR(l,0,K) dp[i][l] = max(dp[i][l], dp[j][l]);
		}
		FOR(k,0,K) if (a[i] & (1 << k)) {
			next_with[k] = i;
			dp[i][k] = i;
		}
		//FOR(k,0,K) cout << dp[i][k] << " ";
		//cout << endl;
		
		for (pll p: qat[i]) {
			ll j, id;
			tie(j,id) = p;
			FOR(k,0,K) if (a[j] & (1 << k)) {
				if (dp[i][k] >= j) res[id] = true;
			}
		}
	}
	
	FOR(i,0,q) cout << (res[i] ? "Shi" : "Fou") << "\n";
}