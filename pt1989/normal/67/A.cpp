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
const int mxn = 1024;
int n;
char a[mxn];
int p[mxn];
vector<int> adj[mxn];
int find(int x){ 
	if(p[x] ==x) return x;
	return p[x] =find(p[x]);
}
int dp[mxn];
int solve(int v) {
	if (dp[v] != -1) return dp[v];
	dp[v] = 1;
	for (int j=0; j < adj[v].size(); j++) {
		dp[v] = max(dp[v], 1 + solve( adj[v][j] ) );
	}
	return dp[v];
}
int main(int argc, char** argv) {
	s(n); 
	scanf("%s", a);
	for (int i=0; i < n; i++) p[i] = i;
	vector<int> F, T;
	for (int i=0; i+1 < n; i++) {
		int f =i, t = i+1;
		if (a[i] == '=') {
			int pf = find(f);
			int pt = find(t);
			p[pf] = pt;
		} else {
			if (a[i] == 'R') {
				swap(f, t);
			}
			F.pb(f); T.pb(t);
		}
	}
	
	for (int i=0; i < (int)F.size(); i++) {
		int f = find( F[i] );
		int t = find( T[i] );
		adj[ f ].pb( t );
	}
	fill(dp, -1);
	for (int i=0; i < n; i++) {
		printf("%d", solve( find(i) ));
		if (i+1 == n) puts("");
		else printf(" ");
	}
	
	
	return 0;
}