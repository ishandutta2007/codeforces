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


ll dp[21][11][11][5][5];
int n;
char a[32];
ll solve( int p, int t1, int t2, int p1, int p2 )
{
    
    if( p == n )
    {
        //if( t1==0 && t2==0 ) cout<< a << endl;
        return t1==0 && t2==0;
    }
    if( t1 < 0 || t2 < 0 )
        return 0;
    
    ll &d = dp[p][t1][t2][p1][p2];
    if( ~d ) return d;
    d = 0;
    for(int p3=1; p3 <= 4; p3++)
    if( p3 != p2 )
    {
        
        int nt1 = t1;
        int nt2 = t2;
        if( p-2 >= 0 )
        if( p1 < p2 && p2 > p3 )
            nt1--;
        if( p-2 >= 0 )
        if( p1 > p2 && p2 < p3 )
            nt2--;
        a[p] = p3+'0';
        d += solve( p+1, nt1, nt2, p2, p3 );
        a[p] = '-';
    }
    return d;
}

int main()
{
    cin>>n;
    int t;
    cin>>t;
    fill( dp,-1 );
    cout<< solve( 0, t, t-1, 0, 0 ) << endl;
    return 0;
}