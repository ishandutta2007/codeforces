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

vl solve() {
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	if (a == vl(n,a[0])) return vl(n,1);

	vl res(n);
	if (n%2 == 0) {
		FOR(i,0,n) res[i] = 1 + i%2;
		return res;
	}

	FOR(i,0,n-1) if (a[i] == a[i+1]) {
		FOR(j,0,n) res[j] = 1 + (j + (j > i)) % 2;
		return res;
	}

	if (a[0] == a[n-1]) {
		FOR(i,0,n) res[i] = 1 + i%2;
		return res;
	}
	
	FOR(i,0,n) res[i] = 1 + i%2;
	res[0] = 3;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		vl res = solve();
		cout << *max_element(all(res)) << endl;
		for (ll x: res) cout << x << " ";
		cout << endl;
	}
}