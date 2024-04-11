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

ll k;
ll a[5010];
set<ll> poss[21];
vi can[21];

ll go(ll x) {
	FOR(res,1,k+1) {
		FOR(left,0,res+1) {
			ll right = res - left;
			ll i = 0, j = sz(can[right])-1;
			while (i < sz(can[left]) && j >= 0) {
				ll cur = can[left][i] + can[right][j];
				if (cur == x) return res;
				else if (cur > x) j--;
				else i++;
			}
		}

	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	ll n;
	cin >> n >> k;
	FOR(i,0,n) cin >> a[i];

	FOR(j,0,n) FOR(i,0,k+1) poss[i].insert(i*a[j]);
	FOR(i,0,k+1) can[i] = vi(all(poss[i]));

	ll q; cin >> q;
	FOR(qq,0,q) {
		ll x;
		cin >> x;
		cout <<go(x) << endl;
			
	}


}