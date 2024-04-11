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
		vl have(3);
		FOR(i,0,3) cin >> have[i];
		
		int res = 0;
		FOR(mask,0,1 << 8) {
			if (mask & 1) continue;
			vl cnt(3);
			FOR(i,1,8) if (mask & (1 << i)) {
				FOR(j,0,3) if (i & (1 << j)) cnt[j]++;
			}
			
			bool ok = true;
			FOR(i,0,3) if (cnt[i] > have[i]) ok = false;
			if (ok) res = max(res, __builtin_popcount(mask));
		}
		cout << res << endl;
	}
	
}