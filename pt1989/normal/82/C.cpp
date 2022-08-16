//      hello world


//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>

#define oo 			0xBADC0DE
#define s(n)			scanf("%d",&n)
#define sl(n) 			scanf("%lld",&n)
#define sf(n) 			scanf("%lf",&n)
#define fill(a,v) 		memset(a, v, sizeof a)
#define ull 			unsigned long long
#define ll 				long long
#define bitcount 		__builtin_popcount
#define all(x) 			x.begin(), x.end()
#define pb( z ) 		push_back( z )
#define gcd				__gcd

#define FOR(i,n) for (int i=0; i < (n); i++)

using namespace std;

const int mxn = 5007;
int prio[mxn];
struct edge {
	int to, cap;
	edge(int _t, int _c) {
		to = _t; cap = _c;
	}
	
};
struct cmp {
bool operator () (const int a, const int b)  {
		return prio[a] > prio[b];
} };
vector<edge> adj[mxn];
int n;
int parent[mxn];
int cap[mxn];
int sol[mxn];
int timer[mxn];
priority_queue< int, vector<int>, cmp > q[ mxn ];
set<int> vis;
vector< pair<int, int> > z;
void dfs(int v, int par, int dep) {
	for (int i=0; i < (int)adj[v].size(); i++) {
		int nv = adj[v][i].to;
		if (nv == par) 
			continue;
		int ncap = adj[v][i].cap;
		parent[nv] = v;
		cap[nv] = ncap;
		dfs(nv, v, dep+1);
	}
	vis.insert( v );
	q[v].push( v );
	z.pb( make_pair( dep, v ) );
}



int main(int argc, char** argv) {
	s(n);
	for (int i=1; i <= n; i++)
		s(prio[i]);
	for (int i=1; i < n; i++) {
		int f, t, cap;
		s(f); s(t); s(cap);
		adj[f].pb( edge(t, cap) );
		adj[t].pb( edge(f, cap) );
	}
	dfs(1,1, 0);
	vector<int> order;
	sort( all(z) );
	for (int i=0; i < z.size(); i++)
		order.pb( z[i].second );
	while (true) {
		bool change = false;
		for (int qi=1; qi < n; qi++) {
			int i = order[qi];
			if (q[i].size() == 0) continue;
			change = 1;
			int upCap = cap[i];
			while (upCap -- && q[i].size() > 0) {
				int v = q[i].top(); q[i].pop();
				sol[v] = 1 + timer[i];
				q[ parent[i] ].push( v );
			}
			timer[i]++;
		}
		if (!change)
			break;
	}
	
	for (int i=1; i <= n; i++) {
		printf("%d%c", sol[i], i==n ? '\n' : ' ');
	}
	return 0;
}