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

struct rect
{
    ll x0, y0, x1, y1;
    rect( ll A, ll B, ll C, ll D , bool flag=0)
    {
        x0=A; y0=B; x1=C; y1=D;
        if( flag ) return;
        if( x0 > x1 ) swap( x0, x1 );
        if( y0 > y1 ) swap( y0, y1 );
    }
    ll area( )
    {
        ll z = x1-x0+1;
        ll g = y1-y0+1;
        if( z < 0 || g < 0 ) return 0;
        return z*g;
    }
    rect intersect( const rect& r )
    {
        rect a( max( x0, r.x0 ), max( y0, r.y0 ), min( x1, r.x1 ), min( y1, r.y1 ), 1 );
        return a;
    }
    void print()
    {
        cout<< x0 << " " << y0 << " , " << x1 << " " << y1 << "\t";
    }
};
int main()
{
    int runs;
    s( runs );
    while( runs-- )
    {
        int n, m;
        s(n); s(m);
        int x1, y1, x2, y2;
        s(x1); s(y1); s(x2); s(y2);
        ll tot = n;
        tot *= m;
        ll ux = min( n-x1, n-x2 );
        ll uy = min( m-y1, m-y2 );
        ll lx = min( x1-1, x2-1 );
        ll ly = min( y1-1, y2-1 );
        
        rect f( x1-lx, y1-ly, x1+ux, y1+uy );
        rect g( x2-lx, y2-ly, x2+ux, y2+uy );
        rect z = f.intersect( g );
        
        
        //cout<< lx << " " << ly << " " << ux << " " << uy << endl;
        //f.print(); g.print(); z.print(); cout<<endl;
        
        ll area = f.area() + g.area() - z.area();
        cout<< (tot-area) << endl;
    }
    return 0;
}