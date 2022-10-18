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

void solve() {
	ll n; cin >> n;
	vl a(n), b(n), c(n);
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) cin >> b[i];
	FOR(i,0,n) cin >> c[i];

	vl p = a;
	FOR(i,1,n) {
		if (p[i] == p[i-1]) p[i] = b[i];
	}
	for (ll x: {a[0],b[0],c[0]}) {
		if (x != p[1] && x != p[n-1]) p[0] = x;
	}
	FOR(i,0,n) cout << p[i] << " \n"[i+1==n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}