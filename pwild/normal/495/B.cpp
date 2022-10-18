#include <list>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <functional>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <tuple>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);

	ll a, b;
	cin >> a >> b;
	ll n = a - b;

	if (n < 0) {
		cout << 0 << endl;
	} else if (n == 0) {
		cout << "infinity" << endl;
	} else {
		vector<pair<ll,ll>> divis;

		for (ll k = 2; k*k <= n; k++) {
			int deg = 0;
			while (n % k == 0) {
				deg++;
				n /= k;
			}
			if (deg) divis.pb(mp(k,deg));
		}
		if (n > 1) divis.pb(mp(n,1));

		vector<ll> divis2({1});
		for (const auto &dp : divis) {
			ll p, deg;
			tie(p,deg) = dp;
			int len = sz(divis2);
			ll q = 1;
			FOR(j,0,deg) {
				q *= p;
				FOR(i,0,len) {
					divis2.pb(divis2[i]*q);
				}
			}
		}
		
		int res = 0;
		for (const ll &d: divis2) if (d > b) res++;
		cout << res << endl;
		



	}


	
}