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

bool comp[100000];

const ll INF = LLONG_MAX/2;
const int maxN = 210;
int N, SRC, DST;
vi adj[maxN];
ll residual[maxN][maxN];

void add_edge(int a, int b, ll c) {
	adj[a].pb(b);
	adj[b].pb(a);
	residual[a][b] += c;
}

bool mark[maxN];

ll dfs(int n, ll cap, ll delta) {
	if (n == DST) return cap;
	mark[n] = true;
	for (const auto &to: adj[n]) {
		if (mark[to] || residual[n][to] < delta) continue;
		if (ll c = dfs(to,min(cap,residual[n][to]), delta)) {
			residual[n][to] -= c;
			residual[to][n] += c;
			return c;
		}
	}
	return 0;
}

ll maxflow() {
	ll flow = 0, delta = 2;
	while (delta) {
		fill_n(mark,N,0);
		ll c = dfs(SRC,INF,delta);
		if (c) flow += c; else delta /= 2;
	}
	return flow;
}

ll a[maxN];

int main() {
	ios_base::sync_with_stdio(false);

	memset(comp,0,sizeof(comp));
	for (int i = 2; i*i < 100000; i++) {
		if (comp[i]) continue;
		for (int j = i*i; j < 100000; j += i) comp[j] = true;
	}

	memset(residual,0,sizeof(residual));
	int n; cin >> n;
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) if (a[i] % 2 == 0) {
		FOR(j,0,n) if(!comp[a[i]+a[j]]) add_edge(i,j,1);
		add_edge(n,i,2);
	} else {
		add_edge(i,n+1,2);
	}


	N = n+2; SRC = n; DST = n+1;
/*	
	FOR(i,0,N) {
		FOR(j,0,sz(adj[i])) cerr << adj[i][j] << " ";
		cerr << endl;
	}
*/	
	
	if (maxflow() == n) {
		
		fill_n(mark,n,0); 
		vector<vi> cyc;
		FOR(i,0,n) if (!mark[i]) {
			vi c;
			int cur = i;
			bool go = true;
			while (go) {
				c.pb(cur+1);
				mark[cur] = true;
				go = false;
				for (const auto &to: adj[cur]) {
					if (to < n && !mark[to] && residual[cur][to] == a[cur] % 2) {
						cur = to; go = true; break;
					}
				}
			}
			cyc.pb(c);
		}
		cout << sz(cyc) << endl;
		for (const auto &c: cyc) {
			cout << sz(c) << " ";
			FOR(i,0,sz(c)-1) cout << c[i] << " ";
			cout << c[sz(c)-1] << endl;
		}
	} else {
		cout << "Impossible" << endl;
	}
}