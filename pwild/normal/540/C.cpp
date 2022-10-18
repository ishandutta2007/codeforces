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

const ll di[] = {1,0,-1,0}, dj[] = {0,1,0,-1};
string a[512];

bool test() {
	ll m, n; cin >> m >> n;
	FOR(i,0,m) cin >> a[i];
	ll i1, j1, i2, j2;
	cin >> i1 >> j1 >> i2 >> j2;
	i1--, j1--, i2--, j2--;
	
	ll cnt = 0;
	FOR(k,0,4) {
		ll ni = i2+di[k], nj = j2+dj[k];
		if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
		if (a[ni][nj] == '.' || (ni == i1 && nj == j1)) cnt++;
	}
	if (cnt <= 1 && a[i2][j2] == '.') return false;
	if (cnt == 0) {
		return (abs(i1-i2)+abs(j1-j2) == 1);
	}

	a[i2][j2] = '*';
	queue<ll> q;
	q.push(i2); q.push(j2);
	while (sz(q)) {
		ll i = q.front(); q.pop();
		ll j = q.front(); q.pop();
		FOR(k,0,4) {
			ll ni = i+di[k], nj = j+dj[k];
			if (ni < 0 || nj < 0 || ni >= m || nj >= n || a[ni][nj] != '.') continue;
			a[ni][nj] = '*';
			q.push(ni); q.push(nj);
		}
	}

	FOR(k,0,4) {
		ll ni = i1+di[k], nj = j1+dj[k];
		if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
		if (a[ni][nj] == '*') return true;
	}
	return false;



}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	if (test()) cout << "YES" << endl;
	else cout << "NO" << endl;

}