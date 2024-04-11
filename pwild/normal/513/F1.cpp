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
#include <queue>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
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

typedef vector<vector<ll>> vvi;

const ll INF = 1000000000000000ll;
const ll maxN = 2000;
ll N, SRC, DST;
vi adj[maxN];
ll residual[maxN][maxN];

ll dx[] = {-1,0,0,1};
ll dy[] = {0,-1,1,0};

struct scayger {
	ll x, y, t;
	vvi distTo;

	void bfs(vs &area) {
		distTo = vvi(sz(area),vi(sz(area[0]),INF));
		queue<ll> q;
		distTo[x][y] = 0;
		q.push(x); q.push(y);
		while (sz(q)) {
			ll cx = q.front(); q.pop();
			ll cy = q.front(); q.pop();
			FOR(k,0,4) {
				ll nx = cx+dx[k], ny = cy+dy[k];
				if (area[nx][ny] == '#' || distTo[nx][ny] < INF) continue;
				distTo[nx][ny] = distTo[cx][cy] + t;
				q.push(nx); q.push(ny);
			}
		}
	}
};

void reset(ll n, ll s, ll t) {
	N = n, SRC=s, DST=t;
	FOR(i,0,N) adj[i].clear();
	FOR(i,0,N) FOR(j,0,N) residual[i][j] = 0;
}

void add_edge(ll a, ll b, ll c) {
	adj[a].pb(b);
	adj[b].pb(a);
	residual[a][b] += c;
}

bool mark[maxN];

ll dfs(ll n, ll cap, ll delta) {
	if (n == DST) return cap;
	mark[n] = true;
	for (const ll &to: adj[n]) {
		if (mark[to] || residual[n][to] < delta) continue;
		if (ll c = dfs(to,min(cap,residual[n][to]),delta)) {
			residual[n][to] -= c;
			residual[to][n] += c;
			return c;
		}
	}
	return 0;
}

ll maxflow() {
	ll flow = 0, delta = 1;
	while (delta) {
		fill_n(mark,N,0);
		ll c = dfs(SRC,INF,delta);
		if (c) flow += c; else delta /= 2;
	}
	return flow;
}

int main() {
	ios_base::sync_with_stdio(false);

	ll n, m, males, females;
	cin >> n >> m >> males >> females;

	if (abs(males-females) != 1) {
		cout << -1 << endl;
		return 0;
	}
	
	vector<string> area(n+2,string(m+2,'#'));
	FOR(i,1,n+1) FOR(j,1,m+1) cin >> area[i][j];

	vector<scayger> scay[2];
	
	ll boss = males > females;
	{
		scayger s;
		cin >> s.x >> s.y >> s.t;
		scay[boss].pb(s);
	}
	FOR(k,0,males) {
		scayger s;	
		cin >> s.x >> s.y >> s.t;
		scay[0].pb(s);
	}
	FOR(k,0,females) {
		scayger s;	
		cin >> s.x >> s.y >> s.t;
		scay[1].pb(s);
	}

	ll k = max(males,females);
	assert(k == sz(scay[0]));
	assert(k == sz(scay[1]));

	FOR(h,0,2) FOR(i,0,k) {
		scay[h][i].bfs(area);

	//	scay[h][i].distTo = vvi(n+2,vi(m+2,INF));
	//	bfs(area,scay[h][i].distTo,scay[h][i].x,scay[h][i].y);
	}
	
	ll tmin = -1, tmax = 100000000000000ll;

	while (tmax - tmin > 1) {
		ll t = (tmin+tmax+1)/2;
	//	cerr << t << endl;
		ll h = 2*(k+n*m);
		reset(h+2,h,h+1);
		FOR(i,0,k) {
			add_edge(h,i,1);
			add_edge(k+i,h+1,1);
		}
		FOR(i,0,k) {
			auto &s = scay[0][i];
			FOR(x,1,n+1) FOR(y,1,m+1) {
				if (s.distTo[x][y] <= t) add_edge(i,2*k+(x-1)*m+y-1,1);
			}
		}
		FOR(i,0,n*m) add_edge(2*k+i,2*k+n*m+i,1);
		FOR(i,0,k) {
			auto &s = scay[1][i];
			FOR(x,1,n+1) FOR(y,1,m+1) {
				if (s.distTo[x][y] <= t) add_edge(2*k+n*m+(x-1)*m+y-1,k+i,1);
			}
		}
	/*	
		FOR(i,0,N) {
			cerr << i << ":";
			for (const ll &j: adj[i]) cerr << " " << j;
			cerr << endl;
		}
	*/
		if (maxflow() == k) tmax = t;
		else tmin = t;
	}
	if (tmax >= 100000000000000ll) cout << -1 << endl;
	else cout << tmax << endl;


}