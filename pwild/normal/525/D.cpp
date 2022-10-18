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
#define pb push
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll m, n;
string s[2010];

bool mustdelete(ll i, ll j) {
	FOR(di,-1,2) FOR(dj,-1,2) if (di && dj) {	
		ll ni = i+di, nj = j+dj;
		if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
		if (s[i][nj] == '.' && s[ni][j] == '.' && s[ni][nj] == '.') return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> m >> n;
	FOR(i,0,m) cin >> s[i];
		
	queue<ll> q;
	FOR(i,0,m) FOR(j,0,n) {
		if (s[i][j] == '*' && mustdelete(i,j)) q.pb(i), q.pb(j);
	}
	
	while (sz(q)) {
		ll i = q.front(); q.pop();
		ll j = q.front(); q.pop();
		if (s[i][j] == '.') continue;
		s[i][j] = '.';
		FOR(di,-1,2) FOR(dj,-1,2) if (di || dj) {
			ll ni = i+di, nj = j+dj;
			if (ni < 0 || ni >= m || nj < 0 || nj >= n || s[ni][nj] == '.') continue;
			if (mustdelete(ni,nj)) q.pb(ni), q.pb(nj);
		}	
	}

	FOR(i,0,m) cout << s[i] << endl;

}