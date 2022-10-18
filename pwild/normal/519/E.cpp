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

const ll maxN = 100010;

ll n;
vi adj[maxN];
ll par[25][maxN];
ll h[maxN];
ll cnt[maxN];

ll init(ll i, ll ht,  ll p = -1) {
	if (p < 0) p = i;
	h[i] = ht, par[0][i] = p;
	cnt[i] = 1;
	for (const ll &j: adj[i]) if (j != p) {
		cnt[i] += init(j,ht+1,i);
	}
	return cnt[i];
}

ll raise(ll a, ll hd) {
	ll step = 0;
	while (hd) {
		if (hd % 2) a = par[step][a];
		hd /= 2, step++;
	}
	return a;
}

ll lca(ll a, ll b) {
	if (h[a] > h[b]) swap(a,b);
	b = raise(b,h[b]-h[a]);
	ll step = 20;
	if (a == b) return a;
	while (step) {
		step--;
		if (par[step][a] != par[step][b]) a = par[step][a], b = par[step][b];
	}
	assert(par[0][a] == par[0][b]);
	return par[0][a];
}

ll query(ll a, ll b) {
	if (abs(h[a]-h[b]) % 2) return 0;
	if (h[a] > h[b]) swap(a,b);
	ll c = lca(a,b);
	if (h[a] == h[b]) {
		return n - cnt[raise(a,h[a]-h[c]-1)] - cnt[raise(b,h[b]-h[c]-1)];
	} else {
		ll hd = (h[a]+h[b]-2*h[c])/2;
		return cnt[raise(b,hd)] - cnt[raise(b,hd-1)];
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	FOR(i,0,n-1) {
		ll a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	init(1,0);
	FOR(i,1,20) FOR(j,1,n+1) {
		par[i][j] = par[i-1][par[i-1][j]];
	}

	ll m; cin >> m;
	FOR(i,0,m) {
		ll x, y; cin >> x >> y;
		if (x == y) {
			cout << n << endl;
		} else {
			cout << query(x,y) << endl;
		}
	}

}