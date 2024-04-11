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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n = 10;
	auto id = [&](ll i, ll j) {
		return (n-1-i)*n + (i%2 ? j : n-1-j);
	};

	vl ladder(n*n);
	FOR(i,0,n) FOR(j,0,n) {
		ll x; cin >> x;
		ladder[id(i,j)] = id(i-x,j);
	}
	
	vector<double> dp(n*n);
	FOR(iter,0,1000) {
		FORD(k,0,n*n-1) {
			double sum = 0;
			FOR(j,1,7) {
				ll nk = k+j < n*n ? k+j : k;
				sum += min(dp[nk], dp[ladder[nk]]);
			}
			dp[k] = 1 + sum/6;
		}
	}
	cout << fixed << setprecision(10) << dp[0] << endl;
}