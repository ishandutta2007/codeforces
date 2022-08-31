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
    int n, m;
    cin>>n>>m;
    string a;
    bool bad = 0;
    vector< char > y;
    for(int i=0; !bad && i < n; i++)
    {
        cin>>a;
        set< char > x;
        for(int j=0; j < m; j++)
        {
            x.insert( a[j] );
        }
        if( x.size() > 1 )
        {
            bad = 1;
        }
        y.pb( *x.begin() );
        if( y.size() > 0 && y[i-1] == y[i] )
        {
            bad = 1;
        }
        
    }
    cout<< ( bad ? "NO" : "YES" ) << endl;
    return 0;
}