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
inline ll lcm(ll a, ll b) {
	return a*(b/gcd(a,b));
}
struct edge {
	int to, l, g;
	edge(int _to, int _l, int _g) {
		to = _to; l = _l; g = _g;
	}
};
const int mxn = 102;
ll v[mxn];
int n, m;
vector<edge> adj[mxn];
int G[mxn][mxn], L[mxn][mxn];

bool input() {
	s(n); s(m);
	fill(v, -1);
	while (m-- > 0) {
		int f, t, l, g;
		s(f); s(t); s(g); s(l);
		if (G[f][t]==0) {
			G[f][t] = g;
			L[f][t] = l;
			G[t][f] = g;
			L[t][f] = l;
		} else {
			if (G[f][t] != g || L[f][t] != l)
				return 0;
		}
		
		if (l%g != 0) return 0;
		
		adj[f].pb( edge(t, l, g) );
		adj[t].pb( edge(f, l, g) );
	}
	return 1;
}


inline void no() {
	puts("NO");
	exit(0);
}

int vis[mxn], vid;


bool go(int x) {
	if (vis[x] == vid) return 1;
	vis[x] = vid;
	for (int i=0; i < adj[x].size(); i++) {
		int y = adj[x][i].to;
		int g = adj[x][i].g;
		int l = adj[x][i].l;
		ll other = g*(ll)l;
		if (other%v[x] != 0) return 0;
		v[y] = other/v[x];
		if (!go(y))
			return 0;
	}
	return 1;
}
bool check() {
	for (int i=1; i <= n; i++) 
	if (vis[i]) {
		for (int j=0; j < adj[i].size(); j++) {
			if ( gcd( v[i] , v[ adj[i][j].to ] ) != adj[i][j].g ) return 0;
			if ( lcm( v[i] , v[ adj[i][j].to ] ) != adj[i][j].l ) return 0;
		}
	}
	return 1;
}
bool solve(int x) {
	if (adj[x].size() == 0) {
		vis[x] = 1;
		v[x] = 1; return 1;
	}
	
	int g = adj[x][0].g;
	int l = adj[x][0].l;
	int prod = l/g;
	for (int i=1; i*i <= prod; i++)
		if (prod%i == 0) {
			++vid;
			v[x] = i*g;
			if (go(x)) {
				if (check())
				return 1;
			}
			++vid;
			v[x] = g*(prod/i);
			if (go(x)) {
				if (check())
				return 1;
			}
		}
	return 0;
}

int main() {
	if (!input()) {
		no();
	}
	for (int i=1; i <= n; i++) 
	if (!vis[i]) {
		if (!solve(i)) {
			no();
		}
	} 
	puts("YES");
	for (int i=1; i <= n; i++)
	cout << v[i] << " "; puts("");
	
	return 0;
}