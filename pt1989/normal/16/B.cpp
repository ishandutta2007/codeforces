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

#define pii pair< int, int >

int main()
{
    int n, m;
    cin>>n>>m;
    vector< pii > v;
    while( m-- > 0 )
    {
        int a, b;
        cin>>a>>b;
        v.pb( make_pair( b, a ) );
    }
    sort( all( v ) ); reverse( all( v ) );
    ll ans = 0;
    for(int i=0; i < v.size(); i++)
    {
        ll A = v[i].second, B = v[i].first;
        
        ll cur = min( n+0LL, A );
        ans += cur*B;
        n -= cur;
    }
    cout<< ans << endl;
    return 0;
}