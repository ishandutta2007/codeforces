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

ll flip[100010];
vi adj[100010];
vi res;

void dfs(ll i, ll f, ll p) {
	flip[i] ^= f;
	if (flip[i]) res.pb(i+1), f = !f;
	for (const ll &j: adj[i]) if (j != p) {
		for (const ll &k: adj[j]) if (k != i) {
			dfs(k,f,j);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	
	ll n; cin >> n;
	FOR(i,0,n-1) {
		ll a, b; cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	memset(flip,0,sizeof(flip));
	FOR(k,0,2) FOR(i,0,n) {
		ll h; cin >> h;
		flip[i] ^= h;
	}
	dfs(0,0,-1);	
	for (const ll &i: adj[0]) dfs(i,0,0);
	cout << sz(res) << endl;
	FOR(i,0,sz(res)) cout << res[i] << endl;

}