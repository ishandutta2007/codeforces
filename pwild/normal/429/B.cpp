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
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
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

const int N = 1010;
ll a[N][N], ul[N][N], ur[N][N], dl[N][N], dr[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	
	ll m, n; cin >> m >> n;
	FOR(i,0,m) FOR(j,0,n) cin >> a[i][j];
	
	FOR(i,0,m) FOR(j,0,n) {
		ll add = 0;
		if (i > 0) add = max(add,ul[i-1][j]);
		if (j > 0) add = max(add,ul[i][j-1]);
		ul[i][j] = a[i][j] + add;
	}
	FOR(i,0,m) FORD(j,0,n) {
		ll add = 0;
		if (i > 0) add = max(add,ur[i-1][j]);
		if (j < n-1) add = max(add,ur[i][j+1]);
		ur[i][j] = a[i][j] + add;
	}
	FORD(i,0,m) FOR(j,0,n) {
		ll add = 0;
		if (i < m-1) add = max(add,dl[i+1][j]);
		if (j > 0) add = max(add,dl[i][j-1]);
		dl[i][j] = a[i][j] + add;
	}
	FORD(i,0,m) FORD(j,0,n) {
		ll add = 0;
		if (i < m-1) add = max(add,dr[i+1][j]);
		if (j < n-1) add = max(add,dr[i][j+1]);
		dr[i][j] = a[i][j] + add;
	}

	ll best = 0;
	FOR(i,1,m-1) FOR(j,1,n-1) {
		best = max(best,ul[i-1][j]+ur[i][j+1]+dl[i][j-1]+dr[i+1][j]);
		best = max(best,ul[i][j-1]+ur[i-1][j]+dl[i+1][j]+dr[i][j+1]);
	}
	cout << best << endl;


}