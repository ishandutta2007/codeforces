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
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n, m;
		cin >> n >> m;

		vl a(n);
		FOR(i,0,n) cin >> a[i], a[i]--;

		ll k = n;
		while (k > 0 && a[k-1] == k-1) k--;

		double res = k > 0;
		while (m--) {
			ll r; cin >> r;
			double p; cin >> p;
			if (r >= k) res *= 1-p;
		}
		
		res = 1-res;
		cout << fixed << setprecision(20) << res << endl;
	}

}