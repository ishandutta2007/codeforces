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

pll operator-(pll a, pll b) {
	return {a.xx-b.xx, a.yy-b.yy};
}

bool solve() {
	ll n; cin >> n;

	vector<pll> a(n);
	FOR(i,0,n) cin >> a[i].xx >> a[i].yy;
	a.pb(a[0]);
	
	if (n%2) return false;

	FOR(i,0,n/2) {
		if (a[i+1]-a[i] != a[n/2+i]-a[n/2+i+1]) return false;
	}
	
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << (solve() ? "YES" : "NO") << endl;
}