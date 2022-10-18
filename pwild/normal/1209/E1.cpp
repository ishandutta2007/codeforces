#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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
	ll m, n;
	cin >> m >> n;
	
	vvl a(n,vl(m));
	FOR(i,0,m) FOR(j,0,n) cin >> a[j][i];
	for (auto &v: a) rotate(begin(v),max_element(all(v)),end(v));
	sort(all(a),greater<vl>());
	n = min(m,n);
	a.resize(n);
	
	vl dp(1 << m);
	for (vl v: a) {
		vl best(1 << m);
		FOR(mask,0,1 << m) FOR(rot,0,m) {
			ll cur = 0;
			FOR(i,0,m) if (mask & (1 << i)) cur += v[(i+rot)%m];
			best[mask] = max(best[mask], cur);
		}

		vl ndp(1 << m);
		FOR(mask,0,1 << m) {
			for (ll smask = mask; ; smask = (smask-1) & mask) {
				ndp[mask] = max(ndp[mask], dp[mask^smask] + best[smask]);
				if (!smask) break;
			}
		}
		dp = ndp;
	}
	cout << dp.back() << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}