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
	
	ll n; cin >> n;
	string a, b;
	cin >> a >> b;

	vl dp(n+1);
	FORD(i,0,n) {
		dp[i] = dp[i+1] + (a[i] != b[i]);
		
		if (i+1 < n && a[i] == b[i+1] && a[i+1] == b[i]) {
			dp[i] = min(dp[i], dp[i+2] + 1);
		}
	}
	cout << dp[0] << endl;
}