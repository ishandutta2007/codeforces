#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <bitset>
#include <iterator>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); ++i)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll w[1100], h[1100];

int main() {
	ios_base::sync_with_stdio(false);

	ll n; cin >> n;
	FOR(i,0,n) cin >> w[i] >> h[i];
	
	ll W0 = 0;
	FOR(i,0,n) W0 += w[i];

	ll best = 1e12;
	FOR(H,0,1001) {
		bool ok = true;
		ll W = W0;
		ll tilt = n/2;
		vi diffs;
		FOR(i,0,n) {
			if (h[i] > H) {
				if (w[i] > H) { ok = false; break; }
				W += h[i]-w[i];
				tilt--;
			} else if (w[i] <= H) {
				diffs.eb(h[i]-w[i]);
			}
		}
		if (!ok || tilt < 0) continue;
		sort(all(diffs));
		FOR(i,0,min(tilt,sz(diffs))) {
			if (diffs[i] > 0) break;
			W += diffs[i];
		}
		best = min(best,W*H);
	}
	cout << best << endl;

}