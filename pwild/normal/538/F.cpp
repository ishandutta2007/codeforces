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

const ll maxN = 200010;
ll n;
ll ar[maxN];

ll lvl[20][maxN];

void init(ll l, ll i, ll j) {
	if (i == j) return;
	init(l+1,i,(i+j)/2);
	init(l+1,(i+j)/2+1,j);
	sort(lvl[l]+i,lvl[l]+j+1);
}

void init() { init(0,0,n-1); }

ll query(ll l, ll x, ll i, ll j, ll a, ll b) {
	if (j < a || i > b) return 0;
	if (a <= i && j <= b) return lower_bound(lvl[l]+i,lvl[l]+j+1,x)-(lvl[l]+i);
	return query(l+1,x,i,(i+j)/2,a,b) + query(l+1,x,(i+j)/2+1,j,a,b);
}

ll query(ll x, ll a, ll b) { return query(0,x,0,n-1,a,b); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	n++;
	FOR(i,1,n) cin >> ar[i];
	FOR(l,0,20) FOR(i,1,n) lvl[l][i] = ar[i];
	init();

	FOR(k,1,n-1) {
		if (k > 1) cout << " ";
		ll cnt = 0;
		for (ll v = 1; k*(v-1)+2 < n; v++) {
			cnt += query(ar[v],k*(v-1)+2,min(k*v+1,n-1));
		}
		cout << cnt;
	}
	cout << endl;

}