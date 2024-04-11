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
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const int maxN = 100005;
int dist[maxN], pred[maxN], most[maxN];
vector<pair<int,bool>> adj[maxN];

int main() {
	ios_base::sync_with_stdio(false);
	
	int n, m; cin >> n >> m;
	
	set<pii> good; 
	FOR(i,0,m) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].eb(y,z);
		adj[y].eb(x,z);
		if (x > y) swap(x,y);
		if (z) good.emplace(x,y);
	}

	memset(dist,oo,sizeof(dist));

	set<pii> q;
	q.emplace(0,1);
	dist[1] = 0; pred[1] = -1; most[1] = 0;
	while (!q.empty()) {
		int from = q.begin()->yy; q.erase(q.begin());
		for (const auto &e: adj[from]) {
			if (mp(dist[from]+1,-most[from]-e.yy) < mp(dist[e.xx],-most[e.xx])) {
				q.erase(mp(dist[e.xx],e.xx));
				dist[e.xx] = dist[from] + 1;
				most[e.xx] = most[from] + e.yy;
				pred[e.xx] = from;
				q.emplace(dist[e.xx],e.xx);
			}
		}
	}

	cout << dist[n] + sz(good) - 2*most[n] << endl;
	
	int cur = n;
	FORD(k,1,dist[n]+1) {
		int x = pred[cur], y = cur;
		if (x > y) swap(x,y);
		if (has(good,mp(x,y))) {
			good.erase(mp(x,y));
		} else {
			cout << x << " " << y << " 1" << endl;
		}
		cur = pred[cur];
	}
	for (const auto &e: good) {
		cout << e.xx << " " << e.yy << " 0" << endl;
	}
	
}