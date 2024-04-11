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

ll x[100010], y[100010];
ll MOD = 1000000009;
ll up[100010][3], dn[100010][3];
ll carr[100010], supp[100010];
bool taken[100010];

bool isAvail(ll i) {
	if (taken[i]) return false;
	if (carr[i] == 0) return true;
	FOR(j,0,3) {
		ll h = up[i][j];
		if (h == -1 || taken[h]) continue;
		if (supp[h] <= 1) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);

	ll m; cin >> m;
	map<pii,ll> ind;
	
	FOR(i,0,m) {
		cin >> x[i] >> y[i];
		ind[mp(x[i],y[i])] = i;
	}
	
	memset(up,-1,sizeof(up));
	memset(dn,-1,sizeof(dn));
	memset(taken,0,sizeof(taken));

	FOR(i,0,m) {
		carr[i] = 0;
		FOR(j,0,3) {
			pii p(x[i]-1+j,y[i]+1);
			if (has(ind,p)) up[i][j] = ind[p], carr[i]++; 
		}
		supp[i] = 0;
		FOR(j,0,3) {
			pii p(x[i]-1+j,y[i]-1);
			if (has(ind,p)) dn[i][j] = ind[p], supp[i]++;
		}
		if (y[i] == 0) supp[i] = oo;
	}

	set<ll> avail;
	FOR(i,0,m) if (isAvail(i)) avail.insert(i);
	
	ll res = 0;
	FOR(i,0,m) {
		ll cur;
		if (i % 2 == 1) {
			cur = *avail.begin();
		} else {
			cur = *(--avail.end());
		}

		//cerr << sz(avail) << endl;

		avail.erase(cur);
		taken[cur] = true;

		FOR(j,0,3) if (dn[cur][j] >= 0) {
			carr[dn[cur][j]]--;
			if (isAvail(dn[cur][j])) avail.insert(dn[cur][j]);
		}
		FOR(j,0,3) if (up[cur][j] >= 0 && !taken[up[cur][j]]) {
			supp[up[cur][j]]--;
			if (supp[up[cur][j]] == 1) {
				FOR(k,0,3) avail.erase(dn[up[cur][j]][k]);
			}
		}
		//cerr << cur << endl;	
		res = (m*res + cur) % MOD;

	}
	
	cout << res << endl;



	






}