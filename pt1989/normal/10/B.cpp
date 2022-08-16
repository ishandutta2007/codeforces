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



int main()
{
    int n, k;
    cin>>n>>k;
    
    int a[128][128];
    ll sum[128];
    fill( a, 0 );
    fill( sum, 0 );
    
    
    
    
    int xc = ceil( k/2. ), yc = ceil( k/2. );
    
    for(int y=1; y <= k; y++)
    sum[ y ] = sum[y-1] + abs( y-yc );
    
    while( n-- )
    {
        int L;
        cin>>L;
        ll dir = (ll)1e18;
        int X=-1, yl=-1, yr=-1;
        for(int x=1; x <= k; x++)
        {
            for(int y=1; y+L-1 <= k; y++)
            {
                int in = 0;
                for(int z=y; z < y+L; z++)
                    if( a[x][z] ) 
                    {
                        in++;
                        break;
                    }
                
                if( in==0 )
                {
                    ll nu = L*(ll)abs(x-xc) + sum[ y+L-1 ] - sum[y-1];
                    if( nu < dir )
                    {
                        dir = nu;
                        X = x; yl=y; yr = y+L-1;
                    }
                    //cout<<"\t"<<x<<" " <<y<< " " << y+L-1 <<" " << nu <<  endl;
                }
            }
        }
        
        if( X==-1 ) cout<< -1 << endl;
        else
        {
            for(int y=yl; y <= yr; y++)
            {
                a[X][y] = 1;
            }
            cout<< X << " " << yl << " " << yr << endl;
        }
        
    }
    
    
    return 0;
}