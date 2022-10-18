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
		ll m, n;
		cin >> m >> n;
		vvl a(m, vl(n));
		FOR(i,0,m) FOR(j,0,n) cin >> a[i][j];
	
		ll res = 0;
		FOR(i,0,m) FOR(j,0,n) if (i <= m-1-i && j <= n-1-j) {
			vector<tuple<ll,ll,ll>> s;
			for (ll ni: {i,m-1-i}) for (ll nj: {j,n-1-j}) {
				s.eb(a[ni][nj],ni,nj);
			}
			sort(all(s));
			s.erase(unique(all(s)),end(s));
			
//			for (auto [v,i,j]: s) cout << v << " ";
//			cout << endl;

			ll med = get<0>(s[sz(s)/2]);
			FOR(i,0,sz(s)) res += abs(get<0>(s[i])-med);
		}
		cout << res << endl;
	}
}