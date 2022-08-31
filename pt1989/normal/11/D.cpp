//DS includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>

//Other Includes
#include<sstream>
#include<fstream>
#include<iostream>
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

const int mxn = 19;
int n, m;
vector<int> adj[mxn];
bool neigh[mxn][mxn];
int bitc[1<<mxn];
int lob[1<<mxn];
vector<int> loMask[mxn];
string conv( int x )
{
    string ret = "{" ;
    for(int i=0; i < n; i++)
    if( x & 1<< i )
        ret += (char)(i+'1') , ret += ",";
    ret[ ret.size()-1 ]  = '}';
    return ret;
}

int lowest;
ll dp[mxn][1<<mxn];
short vis[mxn][1<<mxn], vid;
ll solve( int v, int mask )
{
    if( mask == (1<<v) )
        return neigh[v][lowest];
    short &visd = vis[v][mask];
    ll& ret = dp[v][mask];
    if( visd == vid ) return ret;
    visd = vid;
    ret = 0;
    for(int i=0; i < (int)adj[v].size(); i++)
    {
        int ai = adj[v][i];
        if( mask & 1<<ai )
            ret += solve( ai, mask ^ 1<<v );
    }
    return ret;
}


int main()
{
    
    s( n ); s( m );
    while( m-- )
    {
        int f, t;
        s( f ); s( t );
        --f; --t;
        adj[f].pb( t ); adj[t].pb( f );
        neigh[ f ][ t ] = neigh[ t ][ f ] = 1;
    }
    
    ll sol = 0;
    for(int mask=1; mask < (1<<n); mask++)
    {
        bitc[ mask ] = bitc[mask>>1] + (mask&1);
        if( mask & 1 )
            lob[mask] = 0;
        else
            lob[mask] = 1 + lob[mask>>1];
        loMask[ lob[mask] ].pb( mask );
    }
    
    
    for(int loBit = 0; loBit < n; loBit++)
    {
        lowest = loBit; ++vid;
        for(int i=0; i < (int)loMask[ loBit ].size(); i++)
        {
            int mask = loMask[ loBit ][ i ] ;
            if( bitc[mask] <= 2 ) continue;
            ll cur = solve( loBit, mask );
            sol += cur;
            //cout<< conv(mask) << " " << loBit << " " << cur << endl;
        }
    }
    
    
    
    cout<< (sol/2) << endl;
    return 0;
}