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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;
	vi a(k);
	FOR(i,0,k) cin >> a[i];

	FOR(i,0,n-k+1) {
		vi b(n);
		FOR(j,0,k) b[j] = a[j];
		FOR(j,k,k+i) b[j] = 1;
		FOR(j,k+i,n) b[j] = y;
		sort(all(b));
		ll sum = 0;
		FOR(i,0,n) sum += b[i];
		if (b[n/2] >= y && sum <= x) {
			vi res(n-k);
			FOR(j,0,i) res[j] = 1;
			FOR(j,i,n-k) res[j] = y;
			FOR(j,0,n-k-1) cout << res[j] << " ";
			cout << res[n-k-1] << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	

}