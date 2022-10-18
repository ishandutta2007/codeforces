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

	ll n, k; cin >> n >> k;

	vl c(n);
	FOR(i,0,n) cin >> c[i];

	ll res = 0;
	set<pll> costs;
	ll costsum = 0;

	FOR(i,0,k) {
		costs.insert(pll(c[i],i));
		costsum += c[i];
		res += (k-i)*c[i];
	}
	
	vl ans(n);

	FOR(i,k,n+k) {
		if (i < n) {
			costs.insert(pll(c[i],i));
			costsum += c[i];
		}

		auto cur = *costs.rbegin();
		costs.erase(cur);
		costsum -= cur.xx;
		
		ans[cur.yy] = i+1;

		res += costsum;
	}
	cout << res << endl;
	FOR(i,0,n) cout << ans[i] << " \n"[i+1==n];
}