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
    vector< int > z;
    
    int a, b, x, y;
    cin>>a>>b>>x>>y;
    {
        int gc = gcd( x,y );
        x /= gc; y /= gc;
    }
    ll lo = 0, hi = (int)1e10;
    while( lo+1 < hi )
    {
        ll X = (lo+hi)/2;
        ll A = X*x;
        ll B = X*y;
        if( A <= a && B <= b )
            lo = X;
        else
            hi = X;
    }
    
    cout<< lo*x << " " << lo*y << endl;
    
    return 0;
}