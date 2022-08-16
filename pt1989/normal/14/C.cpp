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


#define point pair<int,int>
#define segment pair< point, point >


int main()
{
    
    int x1[4], x2[4], y1[4], y2[4];
    set< segment > z;
    for(int i=0; i < 4; i++)
    {
        int xi, yi, xj, yj;
        cin>>xi>>yi>>xj>>yj;
        x1[i] = xi; x2[i] = xj;
        y1[i] = yi; y2[i] = yj;
        
        point f( xi, yi );
        point g( xj, yj );
        if( f > g )
            swap( f, g );
        z.insert( make_pair( f, g ) );
    }
    bool ok = 0;
    #define segcon(x1,y1,x2,y2) make_pair( point(x1,y1), point(x2,y2) )
    for(int i=0; i < 4; i++)
    for(int j=i+1; j < 4; j++)
    {
        int minx = min( min(x1[i],x2[i]), min(x1[j],x2[j]) );
        int miny = min( min(y1[i],y2[i]), min(y1[j],y2[j]) );
        
        
        int maxx = max( max(x1[i],x2[i]), max(x1[j],x2[j]) );
        int maxy = max( max(y1[i],y2[i]), max(y1[j],y2[j]) );
        
        if( minx < maxx )
        if( miny < maxy )
        if( z.count( segcon( minx, miny, minx, maxy ) ) )
        if( z.count( segcon( minx, miny, maxx, miny ) ) )
        if( z.count( segcon( maxx, miny, maxx, maxy ) ) )
        if( z.count( segcon( minx, maxy, maxx, maxy ) ) )
        ok=1;
        
    }
    
    cout<< ( ok ? "YES" : "NO" ) << endl;
    
    return 0;
}