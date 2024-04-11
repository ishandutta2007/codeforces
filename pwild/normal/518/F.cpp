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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;

#define sz(c) ll((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })
#define xx first
#define yy second

string a[2010];
bool u[2010][2010];
bool d[2010][2010];
bool l[2010][2010];
bool r[2010][2010];

int main() {
	ios_base::sync_with_stdio(false);
	
	ll n, m; cin >> m >> n;
	
	FOR(i,0,m) cin >> a[i];

	FOR(i,0,m) FOR(j,0,n) {
		u[i][j] = a[i][j] == '.';
		if (i > 0 && !u[i-1][j]) u[i][j] = false;
	}
	FORD(i,0,m) FOR(j,0,n) {
		d[i][j] = a[i][j] == '.';
		if (i < m-1 && !d[i+1][j]) d[i][j] = false;
	}
	FOR(j,0,n) FOR(i,0,m) {
		l[i][j] = a[i][j] == '.';
		if (j > 0 && !l[i][j-1]) l[i][j] = false;
	}
	FORD(j,0,n) FOR(i,0,m) {
		r[i][j] = a[i][j] == '.';
		if (j < n-1 && !r[i][j+1]) r[i][j] = false;
	}
	
	ll res = 0;
	
	FOR(i,1,m-1) if (l[i][0] && r[i][0]) res++;
	FOR(j,1,n-1) if (u[0][j] && d[0][j]) res++;

	FOR(i,1,m-1) FOR(j,1,n-1) {
		if (l[i][j] && u[i][j]) res++;
		if (r[i][j] && u[i][j]) res++;
		if (l[i][j] && d[i][j]) res++;
		if (r[i][j] && d[i][j]) res++;
	}

	FOR(i,1,m-1) {
		ll len = 0, cur = 0;
		FOR(j,1,n-1) {
			if (a[i][j] == '.') {
				len++;
				if (len >= 2) {
					ll mult = u[i][j] + d[i][j];
					res += cur*mult + u[i][j]*d[i][j-1] + d[i][j]*u[i][j-1];
					cur += u[i][j-1] + d[i][j-1];
				}
			} else {
				len = cur = 0;
			}
		}
	}


	FOR(j,1,n-1) {
		ll len = 0, cur = 0;
		FOR(i,1,m-1) {
			if (a[i][j] == '.') {
				len++;
				if (len >= 2) {
					ll mult = l[i][j] + r[i][j];
					res += cur*mult + l[i][j]*r[i-1][j] + r[i][j]*l[i-1][j];
					cur += l[i-1][j] + r[i-1][j];
				}
			} else {
				len = cur = 0;
			}
		}
	}
	
	cout << res << endl;
	



}