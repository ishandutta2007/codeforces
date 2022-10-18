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

ll n;
ll len[100000];
vi adj[100000];
ll h[100000];
map<pii,int> e;

bool vis[100000];
ll dfs(int p, int i) {
	vis[i] = true;
	ll res = 1;
	for (const int &j: adj[i]) 
		if (!vis[j]) 
			res += dfs(i,j);
	if (p >= 0) h[e[mp(p,i)]] = res*(n-res);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	FOR(i,1,n) {
		int a, b;
		cin >> a >> b >> len[i];
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
		e[mp(a,b)] = e[mp(b,a)] = i;
	}
	
	memset(vis,false,sizeof(vis));
	dfs(-1,0);

	double x = 6.0/(n*(n-1));
	//FOR(i,1,n) cerr << h[i] << endl;

	double res = 0;
	FOR(i,1,n) res += double(len[i])*double(h[i]);
	int q; cin >> q;
	FOR(i,0,q) {
		int j, w; cin >> j >> w;
		res -= double(len[j]-w)*double(h[j]);
		len[j] = w;
		cout << setprecision(12) << res*x << endl;
	}

}