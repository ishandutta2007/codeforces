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

ll n, d, x;

ll nextX() {
	x = (x*37 + 10007) % 1000000007;
	return x;
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> d >> x;
	vi a(n), b(n), c(n);
	FOR(i,0,n) a[i] = i+1;
	FOR(i,0,n) swap(a[i],a[nextX() % (i+1)]);
	FOR(i,0,n) b[i] = (i < d);
	FOR(i,0,n) swap(b[i],b[nextX() % (i+1)]);

	if (d < sqrt(n)) {
		vi ones;
		FOR(i,0,n) if (b[i]) ones.pb(i);
		for (const ll &j: ones) FOR(i,0,n) {
			if (i+j >= n) break;
			c[i+j] = max(c[i+j],a[i]);
		}
	} else {
		set<ll> todo;
		FOR(i,0,n) todo.insert(i);
		vi ai(n);
		FOR(i,0,n) ai[a[i]-1] = i;
		ll k = n;
		while (k > 0 && sz(todo)) {
			ll i = ai[k-1];
			auto it = todo.lower_bound(i);
			while (it != todo.end()) {
				auto tmp = it++;
				ll j = *tmp;
				if (b[j-i]) {
					c[j] = k;
					todo.erase(tmp);
				}
			}
			k--;
		}
	}	

	FOR(i,0,n) cout << c[i] << endl;

}