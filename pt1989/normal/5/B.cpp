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


char a[1024][1024];
int L[1024];
int main()
{
    int n;
    int mxl = 0;
    for(n=0; gets( a[n] ); n++)
    {
        mxl = max( L[n] = strlen( a[n] ), mxl );
    }
    
    for(int i=0; i < mxl+2; i++)
    putchar( '*' ); puts("");
    int odd = 0;
    for(int i=0; i < n; i++)
    {
        putchar( '*' );
        int m = mxl - L[i];
        int left = m/2; int right = m - left;
        if( m&1 ) odd++;
        
        //cout<< m << " " << odd << endl;
        if( !(odd&1) ) { swap( left, right ); }
        
        
        while( left-- ) putchar( ' ' );
        for(int j=0; j < L[i]; j++)
        putchar( a[i][j] );
        while( right-- ) putchar( ' ' );
        putchar('*'); 
        
        
        
        
        puts("");
    }
    for(int i=0; i < mxl+2; i++)
    putchar( '*' ); puts("");
    return 0;
}