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



#define oo                  (int)13e7
#define s(n)                    scanf("%d",&n)
#define sl(n)                   scanf("%lld",&n)
#define sf(n)                   scanf("%lf",&n)
#define fill(a,v)               memset(a, v, sizeof a)
#define ull                     unsigned long long
#define ll                      long long
#define bitcount            __builtin_popcount
#define all(x)              x.begin(), x.end()
#define pb( z )                 push_back( z )
#define gcd                 __gcd
using namespace std;

const int mxn = 2048; 
ll dp[2][mxn*2];
int t[mxn], c[mxn];
int n;
int norm2( int x )
{
    if( x <= -mxn ) return -mxn;
    if( x >= mxn ) return mxn-1;
    return x;
}
int norm(int x)
{
    return mxn+x;
}

int main()
{
    s(n);
    for(int i=0; i < n; i++) s(t[i]), s(c[i]);
    
    for(int p=n; p >= 0; p--)
    for(int T=-mxn; T < mxn; T++)
    {
        ll& d = dp[p&1][norm(T)];
        if( p==n ) { d= ( T >= 0 ? 0 : (ll)1e18 ); }
        else
        {
            d = dp[ (p&1)^1 ][ norm(T-1) ];
            d = min( d, dp[ (p&1)^1 ][ norm( T + t[p] ) ] + c[p] );
        }
    }
    cout<< dp[0][norm(0)] << endl;
    return 0;
}