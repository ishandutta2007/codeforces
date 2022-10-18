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
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll a[310], c[310];

ll gcd(ll x, ll y) { return y ? gcd(y,x%y) : x; }

int main() {
	ios_base::sync_with_stdio(false);

	ll n; cin >> n;
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) cin >> c[i];

	unordered_map<ll,ll> minCost;
	//FOR(i,0,n) minCost[a[i]] = c[i];
	FOR(i,0,n) {
		map<ll,ll> mC;
		for (const auto &k: minCost) {
			ll x = gcd(k.first,a[i]);
			if (!has(mC,x)) {
				mC[x] = k.second + c[i];
			} else {
				mC[x] = min(mC[x],k.second + c[i]);
			}
		}
		for (const auto &k: mC)	{
			if (!has(minCost,k.first)) minCost[k.first] = k.second;
			else minCost[k.first] = min(minCost[k.first],k.second);
		}
		if (has(minCost,a[i])) minCost[a[i]] = min(minCost[a[i]],c[i]);
		else minCost[a[i]] = c[i];
		//for (const auto &k: minCost) {
		//		cout << k.first << " " << k.second << endl;
		//		}
		//		cout << endl;
	}
	if (has(minCost,1)) {
		cout << minCost[1] << endl;
	} else {
		cout << -1 << endl;
	}

}