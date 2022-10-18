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

ll solve() {
	ll m, n;
	cin >> m >> n;

	vector<string> a(m);
	FOR(i,0,m) cin >> a[i];
	
	bool hasA = false, hasP = false;
	FOR(i,0,m) FOR(j,0,n) {
		if (a[i][j] == 'A') hasA = true;
		if (a[i][j] == 'P') hasP = true;
	}
	if (!hasA) return oo;
	if (!hasP) return 0;
	
	ll res = 4;
	bool borderA = false;
	FOR(rot,0,4) {
		if (a[0] == string(n,'A')) return 1;
		FOR(j,0,n) if (a[0][j] == 'A') borderA = true;
		if (a[0][0] == 'A') res = min(res,2LL);
		
		ll jmin = n, jmax = -1;
		FOR(j,0,n) if (a[0][j] == 'P') {
			jmin = min(jmin,j), jmax = max(jmax,j);
		}
		
		FOR(i,1,m) {
			bool ok = true;
			FOR(j,jmin,jmax+1) if (a[i][j] == 'P') ok = false;
			if (ok) res = min(res,2LL);
		}

		vector<string> b(n,string(m,' '));
		FOR(i,0,m) FOR(j,0,n) b[n-1-j][i] = a[i][j];
		swap(a,b), swap(m,n);
	}
	
	if (res == 2) return res;
	return borderA ? 3 : 4;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll res = solve();
		if (res < oo) cout << res << endl;
		else cout << "MORTAL" << endl;
	}
}