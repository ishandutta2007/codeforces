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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, a, b, t; cin >> n >> a >> b >> t;
	string s; cin >> s;
	s = s.substr(1)+s;
	ll res = 0;
	FOR(dir,0,2) {
		ll m = n-1;
		ll cost = 1 + (s[m] == 'w' ? b : 0);
		ll l = m;
		while (l > 0) {
			if (cost + a + 1 + (s[l-1] == 'w' ? b : 0) <= t) {
				cost += a + 1 + (s[l-1] == 'w' ? b : 0), l--;
			} else break;
		}
		ll r = m;
		if (cost <= t) res = max(res,r-l+1);
		else break;
		while (r < 2*n-1) {
			r++;
			cost += 2*a + 1 + (s[r] == 'w' ? b : 0);
			while (cost > t && l < m) {
				cost -= a + 1 + (s[l] == 'w' ? b : 0), l++;
			}
			if (cost <= t) res = max(res,r-l+1);
		}
		reverse(all(s));
	}
	cout << min(res,n) << endl;

}