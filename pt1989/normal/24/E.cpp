#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<sstream>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>



#define oo 					(int)13e7
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define fill(a,v) 				memset(a, v, sizeof a)
#define ull 					unsigned long long
#define ll 						long long
#define bitcount 			__builtin_popcount
#define all(x) 				x.begin(), x.end()
#define pb( z ) 				push_back( z )
#define gcd					__gcd
using namespace std;


const int mxn = (int)5e5 + 7;
int x[mxn], v[mxn];
int prevp[mxn];
double len( int a, int b ) {
  if( v[a] < v[b] ) return 1e100;
  return (x[b]-x[a])/( v[a] - v[b] + 0. );  
}
int main()
{
  int n;
  s(n);
  int lastpos = -1;
  double ans = 1e100;
  bool flag = true;
  for(int i=0; i < n; ++i) {
    s(x[i]); s(v[i]);
    int& pp = prevp[i];
    pp = lastpos;
    if( pp != -1 ) {
      int cur = pp;
      while( true ) {
         int ncur = prevp[cur];
         if( ncur == -1 ) break;
         if( len(ncur,i) < len(cur,i) )
           cur = ncur;
         else
           break;
      }
      prevp[i] = cur;
    }
    
    
    if( v[i] >= 0 ) { lastpos = i; }
    else if( v[i] < 0 && prevp[i] != -1 ){ ans = min( ans, len(prevp[i],i) );flag=false; }
  }
  if( flag ) cout<< -1 << endl;
  else printf("%.18lf\n", ans );
  return 0;
}