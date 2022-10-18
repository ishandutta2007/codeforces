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

const double pi = 2*acos(0);

double solve(ll n) {
	if (n%2 == 0) {
		return 1/tan(pi/2/n);
	}
	
	double beta = (n/2) * pi/n;
	double x = (1 - sin(beta)) / cos(beta);
	double alpha = atan(x);
	return cos(alpha)/sin(pi/2/n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		cout << fixed << setprecision(20) << solve(n) << endl;
	}
}