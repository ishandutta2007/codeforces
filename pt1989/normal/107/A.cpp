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

const int mxn = 1024;
int n, p;

int in[mxn], out[mxn];
vector<int> adj[mxn];
int vis[mxn];

int main(int argc, char** argv) {
	s(n); s(p);
  
  for (int i=0; i < p; i++) {
    int f, t, d;
    s(f); s(t); s(d);
    in[ t ]++;
    out[ f ]++;
    adj[f].pb( t ); adj[f].pb( d );
  }
  fill(vis, 0);
  vector< pair< pair<int,int>, int > > sol;
  for (int i=1; i <= n; i++) {
      if (out[i] == 1 && in[i] == 0) {
        int v = i;
        int minD = (int)2e9;
        while (adj[v].size() > 0) {
          minD = min(minD, adj[v][1]);
          v = adj[v][0];
        }
        sol.pb( make_pair( make_pair(i, v), minD ) );
      }
  }
  sort( all(sol) );
  printf("%d\n", sol.size());
  for (int i=0;i < sol.size(); i++) {
    printf("%d %d %d\n", sol[i].first.first, sol[i].first.second, sol[i].second);
  }
  
  
	return 0;
}