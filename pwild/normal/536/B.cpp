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

const ll MOD = 1e9 + 7;

vi calcZ(string p) {
	ll n = sz(p);
	vi z(n);
	ll l = 0, r = 0;
	FOR(i,1,n) {
		if (i > r) {
			l = r = i;
			while (r < n && p[r-l] == p[r]) r++;
			z[i] = r-l; r--;
		} else {
			ll k = i-l;
			if (z[k] < r-i+1) {
				z[i] = z[k];
			} else {
				l = i;
				while (r < n && p[r-l] == p[r]) r++;
				z[i] = r-l; r++;
			}
		}
	}
	return z;
}


int main() {
	ios_base::sync_with_stdio(false);

	ll n, m; cin >> n >> m;
	
	string p; cin >> p;
	ll k = sz(p);
	vi z = calcZ(p);


	vi y(m+1);
	FOR(i,0,m) cin >> y[i], y[i]--;
	y[m] = oo;

	bool ok = true;
	ll res = 1;

	ll j = 0;
	FOR(i,0,n) {
		if (i == y[j]) {
			if (j > 0 && y[j-1]+k > i) {
				ll d = y[j]-y[j-1];
				if (d + z[d] < k) {
					ok = false;
					break;
				}
			}
			j++;
		} else if (j == 0 || y[j-1]+k <= i) {
			res = res*26 % MOD;
		}			

	}
	

	
	if (ok) cout << res << endl;
	else cout << 0 << endl;

}