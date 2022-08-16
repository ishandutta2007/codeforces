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

int n, m;
const int mxn = 107;
int parent[mxn];
vector<int> adj[mxn];
int degree[mxn];
int from[mxn];
int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}
void bye(int x) {
	puts(x ? "FHTAGN!" : "NO");
	exit(0);
}
int main(int argc, char** argv) {
	s(n); s(m);
	if (m != n) {
		bye(false);
	}
	for (int i=1; i <= n; i++)
		parent[i] = i;
	for (int j=0; j < m; j++) {
		int f, t;
		s(f); s(t);
		adj[f].pb(t); adj[t].pb(f);
		degree[f]++; degree[t]++;
	}
	fill(from, -1);
	vector<int> leaves;
	for (int i=1; i <= n; i++)
	if (degree[i] == 1) {
		leaves.pb( i );
	}
	
	for (int f=0; f < leaves.size(); f++) {
		int l = leaves[f];
		//cout << "from " << l << ":" << endl;
		for (int j=0; j < adj[l].size(); j++)
		if (adj[l][j] != from[l]) {
			//cout << "\tto " << adj[l][j] << " " << degree[ adj[l][j] ] << endl;
			if (--degree[ adj[l][j] ] == 1) {
				leaves.pb( adj[l][j] );
				from[ adj[l][j] ] = l;
				int A = find(l);
				int B = find(adj[l][j]);
				parent[A] = B;
			}
		}
	}
	set<int> tree( leaves.begin(), leaves.end() );
	vector<int> cycle;
	for (int i=1; i <= n; i++) {
		if (tree.count(i) == 0) {
			cycle.pb( i );
		}
	}
	bool ok = 1;
	set<int> cycVisited;
	int f = cycle[0];
	int previous = -1;
	while (true) {
		//cout << "At " << f <<","<<previous<< endl;
		if (cycVisited.count(f)) break;
		cycVisited.insert(f);
		
		int count = 0;
		for (int j=0; j < (int)adj[f].size(); j++) {
			if (adj[f][j] == previous || tree.count( adj[f][j] ));
			else count++;
		}
		
		if ( !(count == 1 || (previous == -1 && count == 2)) ) {
			ok = 0;
			break;
		}
		
		for (int j=0; j < (int)adj[f].size(); j++)
		if (adj[f][j] == previous || tree.count( adj[f][j] ));
		else {
			previous = f;
			f = adj[f][j];
			break;
		}
	}
		
	if (cycVisited.size() == cycle.size()) 
	if (cycle.size() >= 3) {
		bye(true);
	} 
	bye(false);
	return 0;
}