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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<bool> vb;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
#define sz(c) int((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); ++i)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll exp_mod(ll a, ll x, ll m) {
	if (x == 0) return 1;
	ll res = exp_mod(a,x/2,m);
	res = (res*res) % m;
	return (x % 2) ? (res*a) % m : res;
}

int main() {
	ios_base::sync_with_stdio(false);

	ll n, x; cin >> n >> x;
	if (x == 2) {
		cout << -1 << endl;
		return 0;
	}
	if (n == 1) {
		cout << x-1 << endl;
		return 0;
	}	
	ll p = n+1;
	for (ll i = 2; i*i <= p; i++) {
		if (p % i == 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	vi facs;
	ll tmp = n;
	for (ll i = 2; i*i <= tmp; i++) {
		if (tmp % i) continue;
		facs.pb(i);
		while (tmp % i == 0) tmp /= i;
	}
	if (tmp > 1) facs.pb(tmp);
	FORD(k,max(1ll,x-p),x) {
		ll v = k % p;
		bool pr = true;
		for (const ll &f: facs) {
			if (exp_mod(v,n/f,p) == 1) {
				pr = false;
				break;
			}
		}
		if (pr) {
			cout << k << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;

}