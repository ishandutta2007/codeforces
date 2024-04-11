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

string a[100];
bool poss[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	FOR(i,0,n) cin >> a[i];
	
	FOR(dx,-n+1,n) FOR(dy,-n+1,n) if (dx || dy) {
		bool ok = true;
		FOR(x,0,n) FOR(y,0,n) if (a[x][y] == 'o') {
			ll nx = x+dx, ny = y+dy;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (a[nx][ny] == '.') {
				ok = false;
				break;
			}
		}
		if (!ok) continue;
		poss[50+dx][50+dy] = true;
		
		FOR(x,0,n) FOR(y,0,n) if (a[x][y] == 'o') {
			ll nx = x+dx, ny = y+dy;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (a[nx][ny] == 'x') a[nx][ny] = 'y';
		}

	}

	FOR(x,0,n) FOR(y,0,n) if (a[x][y] == 'x') {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	FOR(dx,-n+1,n) {
		FOR(dy,-n+1,n) {
			if (poss[50+dx][50+dy]) {
				cout << 'x';
			} else if (!dx && !dy) {
				cout << 'o'; 
			} else {
				cout << '.';
			}
		}
		cout << endl;
	}



}