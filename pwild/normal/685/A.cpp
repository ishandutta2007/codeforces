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
	
	ll m, n; cin >> m >> n;
	ll p = 1, q = 1, k = 0;
	while (p < m) p *= 7, k++;
	while (q < n) q *= 7, k++;
	if (p == 1) k++;
	if (q == 1) k++;

	if (k > 7) {
		cout << 0 << endl;
		return 0;
	}
	
	ll res = 0;
	FOR(i,0,m) FOR(j,0,n) {
		ll mask = 0;
		bool ok = true;
		ll x = i;
		while (ok && x) {
			if (mask & (1 << (x%7))) ok = false;
			mask ^= 1 << (x%7);
			x /= 7;
		}
		x = j;
		while (ok && x) {
			if (mask & (1 << (x%7))) ok = false;
			mask ^= 1 << (x%7);
			x /= 7;
		}
		while (ok && __builtin_popcount(mask) < k) {
			if (mask & 1) ok = false;
			mask ^= 1;
		}
		res += ok;
	}
	cout << res << endl;

}