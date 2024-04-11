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
	ll m, n, a, b;
	cin >> m >> n >> a >> b;
	
	if (m*a != n*b) {
		cout << "NO" << endl;
		return;
	}
	
	cout << "YES" << endl;
	
	FOR(k,1,m+1) {
		vector<string> res(m, string(n,'0'));
		FOR(i,0,m) FOR(j,0,n) {
			if ((i+k*j)%m < b) res[i][j] = '1';
		}

		bool ok = true;
		FOR(i,0,m) {
			ll sum = 0;
			FOR(j,0,n) sum += res[i][j]-'0';
			if (sum != a) { ok = false; break; }
		}
		FOR(j,0,n) {
			ll sum = 0;
			FOR(i,0,m) sum += res[i][j]-'0';
			if (sum != b) { ok = false; break; }
		}
		
		if (ok) {
			for (string s: res) cout << s << endl;
			return;
		}
	}
	TR(m), TR(n), TR(a), TR(b);
	assert(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}