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

string solve() {
	ll n, m;
	cin >> n >> m;
	vector<string> a(n);
	FOR(i,0,n) cin >> a[i];

	FOR(j,0,m) FOR(k,0,26) {
		string s = a[0];
		s[j] = 'a'+k;

		bool ok = true;
		FOR(ii,0,n) {
			ll dist = 0;
			FOR(jj,0,m) dist += s[jj] != a[ii][jj];
			if (dist > 1) ok = false;
		}
		if (ok) return s;
	}
	return "-1";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) cout << solve() << endl;
}