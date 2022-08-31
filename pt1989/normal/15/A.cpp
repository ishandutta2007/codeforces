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
    int n, t;
    s(n); s(t);
    vector< pair<double,int> > v;
    while( n-- )
    {
        int x, a;
        s(x); s(a);
        v.pb( make_pair( x-a/2.0, 1 ) );
        v.pb( make_pair( x+a/2.0, 0 ) );
    }
    sort( all ( v ) );
    int sz = v.size();
    int ans = 2;
    for(int i=0; i < sz; i++)
    {
        pair<int,int> x = v[i];
        int ni = 0;
        if( !x.second )
        {
            ni = i+1;
            if( ni < sz )
            if( v[ni].first > v[i].first + t)
            {
                //cout<<"placing at "<<x.first << " " << x.second << endl;
                ans++;
            }
        }
        else
        {
            ni = i-1;
            if( ni >= 0 )
            if( v[ni].first <= v[i].first-t )
            {
                //cout<<"placing at "<<x.first << " " << x.second << endl;
                ans++;
            }
        }
        
    }
    
    cout<< ans << endl;
    
    return 0;
    
}