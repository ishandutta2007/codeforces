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


char a[16][16];
char g[16][16];
int main()
{
    for(int i=0; i < 8; i++) scanf("%s", g[i] );
    
    int sol = (int)2e9;
    for(int r=0; r < ( 1<<8 ); r++)
    {
        
        
        for(int c=0; c < ( 1<<8); c++)
        {
            memset( a, 'W', sizeof a );
            for(int x=0; x < 8; x++)
            if( r & 1<<x )
                for(int y=0; y < 8; y++)
                    a[x][y] = 'B';
            for(int y=0; y < 8; y++)
                if( c & 1<<y )
                    for(int x=0; x < 8; x++)
                        a[x][y] = 'B';
            
            bool ok = 1;
            for(int y=0; y < 8; y++)
            for(int x=0; x < 8; x++)
            if( a[x][y] != g[x][y] )
            {
                ok=0; x=y=8;
            }
            if( 0 )
            if( r==2 && c==4 )
            {
                for(int x=0; x < 8; x++, cout<<endl)
                for(int y=0; y < 8; y++)
                cout<< a[x][y] ;
                cout<<endl;
                for(int x=0; x < 8; x++, cout<<endl)
                for(int y=0; y < 8; y++)
                cout<< g[x][y] ;
            }
            if( ok )
            sol = min( sol, bitcount( r ) + bitcount( c ) );
            
        }
        
        
    }
    
    
    cout<< sol << endl;
    return 0;
}