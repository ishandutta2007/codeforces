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
    int n, x0;
    cin>>n>>x0;
    vector<int> events;
    events.pb( x0 );
    vector<int> a(n), b(n);
    for(int i=0; i < n; i++)
    {
        cin>>a[i]>>b[i];
        if( a[i] > b[i] ) swap( a[i], b[i] );
        events.pb( a[i] );
        events.pb( b[i] );
    }
    
    int mind = (int)2e9;
    for(int i=0; i < events.size(); i++)
    {
        bool ok = 1;
        for(int j=0; j < n; j++)
        if( !( a[j] <= events[i] && events[i] <= b[j] ) )
        {
            ok=  0;
            break;
        }
        if( ok )
        mind = min( mind, abs( events[i]-x0 ) );
    }
    if( mind == (int)2e9 )
        mind = -1;
    cout<<mind<<endl;
    return 0;
}