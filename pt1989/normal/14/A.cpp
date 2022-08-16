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
char a[64][64];
int n, m;

int main()
{
    cin>>n>>m;
    
    for(int i=0; i < n; i++)
    cin>>a[i];
    
    int mnx=100, mny=100;
    int mxx=0, mxy=0;
    
    for(int i=0; i < n; i++)
    for(int j=0; j < m; j++)
    if( a[i][j] == '*' )
    {
        mnx = min( mnx, i );
        mxx = max( mxx, i );
        
        mny = min( mny, j );
        mxy = max( mxy, j );
    }
    
    for(int x=mnx; x <= mxx; x++, cout<<endl)
    for(int y=mny; y <= mxy; y++)
    cout<<a[x][y];
    
    
    return 0;
}