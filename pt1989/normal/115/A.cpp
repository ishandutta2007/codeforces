#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
 
#define oo            (int)13e7
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;

const int mxn = 2048;
vector<int> adj[mxn];

int depth(int v) {
    int r = 1;
    for (int i=0; i < adj[v].size(); i++)
        r = max(r, 1 + depth(adj[v][i]));
    return r;
}

int main(int argc, char** argv) {
	int n; s(n);
    vector <int> roots;
    for (int i=1; i <= n; i++) {
        int x; s(x);
        if ( x == -1 ) {
            roots.pb( i );
        } else {
            adj[x].pb( i );
        }
    }
    
    int ans = 0;
    for (int i=0; i < roots.size(); i++) {
        ans = max(ans, depth(roots[i]));
    }
    printf("%d\n", ans);
	return 0;
}