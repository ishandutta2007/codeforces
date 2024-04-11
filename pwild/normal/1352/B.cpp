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

vl solve(ll n, ll k) {
	if (k%2 == 0) {
		if (n%2 == 1) return {-1};
		vl res(k,1);
		res[0] = n-k+1;
		return res;
	} else {
		if (n%2 == 0) {
			vl res(k,2);
			res[0] = n-2*(k-1);
			return res;
		} else {
			vl res(k,1);
			res[0] = n-k+1;
			return res;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n, k;
		cin >> n >> k;
		vl a = solve(n,k);

		bool ok = true;
		for (ll x: a) if (x <= 0) ok = false;

		if (ok) {
			cout << "YES" << endl;
			for (ll x: a) cout << x << " ";
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}