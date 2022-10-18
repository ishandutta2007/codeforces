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

ll a[110][110];

int main() {
	ios_base::sync_with_stdio(false);

	ll m, n, k; cin >> m >> n >> k;
	if (m >= n) {
		FOR(i,0,m) FOR(j,0,n) cin >> a[i][j];
	} else {
		FOR(i,0,m) FOR(j,0,n) cin >> a[j][i];
		swap(m,n);
	}
	if (n <= 10) {
		ll best = k+1;
		FOR(row,0,1 << n) {
			ll cur = 0;
			FOR(i,0,m) {
				ll crow = 0;
				FOR(j,0,n) if (a[i][j]) crow += (1 << j);
				ll cnt = __builtin_popcount(row ^ crow);
				cur += min(cnt,n-cnt);
			}
			best = min(best,cur);
		}
		if (best < k+1) cout << best << endl;
		else cout << -1 << endl;
	} else {
		ll best = k+1;
		FOR(ii,0,m) {
			ll cur = 0;
			FOR(i,0,m) {
				ll cnt = 0;
				FOR(j,0,n) if (a[i][j] != a[ii][j]) cnt++;
				cur += min(cnt,n-cnt);
			}
			best = min(best,cur);
		}
		if (best < k+1) cout << best << endl;
		else cout << -1 << endl;
	}


}