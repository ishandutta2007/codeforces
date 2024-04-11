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
	
	int n; cin >> n;
	vector<int> p(n), q(n);
	FOR(i,0,n) cin >> p[i], p[i]--;
	
	vb mark(n);
	
	map<ll,ll> unused;
	FOR(i,0,n) if (!mark[i]) {
		ll j = i, len = 0;
		do mark[j] = true, j = p[j], len++; while (j != i);
		if (len % 2) {
			// (1 2 3 4 5 6 7)^2 == (1 3 5 7 2 4 6)
			// (1 5 2 6 3 7 4)^2 == (1 2 3 4 5 6 7)
			ll k = i;
			FOR(t,0,len/2+1) k = p[k];
			FOR(t,0,len) q[j] = k, j = p[j], k = p[k];
		} else {
			// (1 2 3 4 5 6)^2 == (1 3 5)(2 4 6)
			if (has(unused,len)) {
				ll k = unused[len];
				FOR(t,0,len) q[j] = k, q[k] = p[j], j = p[j], k = p[k];
				unused.erase(len);
			} else {
				unused[len] = i;
			}
		}
	}
	if (sz(unused)) {
		cout << -1 << endl;
		return 0;
	}
	FOR(i,0,n) cout << q[i]+1 << " \n"[i+1 == n];

}