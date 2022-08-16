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

ll A, B, C;
void bad()
{
    cout<< -1 << endl;
}
void print( ll x, ll y )
{
    ll tmp = A*x + B*y + C;
    //cout<<  tmp << " whoa \n";// << A << " " << B << " " << C << endl;
    if( tmp ) { assert( false ); return bad(); }
    cout<< x << " " << y << endl;
}


#define sp(x,y,z) make_pair( x, make_pair( y, z ) )
pair< ll, pair< ll , ll > > euclid( ll a, ll b )
{
    ll x = 0   , lastx = 1;
    ll y = 1    ,lasty = 0;
    while ( b != 0 )
    {
        ll quotient = a / b;
        
        ll temp = b;
        b = a % b;
        a = temp;
        
        temp = x;
        x = lastx-quotient*x;
        lastx = temp;
        
        temp = y;
        y = lasty-quotient*y;
        lasty = temp;
    }
    return sp(lastx, lasty, a);
}

ll phi( ll z )
{
    z = abs( z );
    ll r = z;
    for(int i=2; i*i <= z; i++)
    if( z%i == 0 )
    {
        z /= i;
        while( z%i == 0 ) z /= i;
        r = (r/i)*(i-1);
    }
    if( z > 1)
        r = (r/z)*(z-1);
    return r;
}
ll expo( ll z, ll p, ll mod )
{
    ll r = 1;
    while( p > 0 )
    {
        if( p&1 )
            r = ( r*z ) % mod;
        z = (z*z)%mod;
        p /= 2;
    }
    return r;
}

void solve( ll a, ll b, ll n )
{
    ll d = gcd( a, n );
    if( b%d )
    {
        bad(); return ;
    }
    a /= d; b /= d; n /= d;
    
    ll inva = expo( a, phi( n ) - 1, n );
    ll x = (b*inva)%n;
    print( x, -(A*x+C)/B );
    
}

int main()
{
    ll a, b, c;
    cin>>a>>b>>c;
    ll Z = gcd( abs( a ), gcd( abs( b ), abs( c ) ) );
    
    if( a==0 )
    {
        if( c%b == 0 )
        {
            print( 0, -c/b );
        }
        else 
            bad();
        
        return 0;
    }
    if( b==0 )
    {
        if( c%a == 0 )
        {
            print( -c/a, 0 );
        }
        else
            bad();
        return 0;
    }
    A = a; B = b; C = c;
    b = abs( b );
    solve( (a%b + b)%b, ((-c)%b + b)%b , b );
    
    return 0;
}