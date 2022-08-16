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

const int mxn = 1024;
int q[mxn];
int p[mxn];
int haveParent[mxn];
int n;
int find( int x )
{
    if( p[x] == x )
        return x;
    return p[x] = find( p[x] );
}
int main()
{
    s(n);
    for(int i=1; i <= n; i++) s(q[i]);
    for(int i=0; i < mxn; i++)
    p[i] = i;
    
    int m;
    s(m);
    
    vector< pair< int, pair<int,int> > > e;
    while( m-- )
    {
        int a, b, c;
        s(a); s(b); s(c);
        e.pb( make_pair( c, make_pair(a,b) ) );
    }
    sort( all( e ) );
    ll cost = 0;
    for(int i=0; i < e.size(); i++)
    {
        int C = e[i].first;
        int A = e[i].second.first;
        int B = e[i].second.second;
        
        
        if( find(A)==find(B) ) continue;
        if( haveParent[B] ) continue;
        //cout<< A << " to " << B << " = " << C << endl;
        haveParent[B] = 1;
        p[B] = A;
        cost += C;
    }
    
    bool ok = 1;
    for(int i=2; i <= n; i++)
    if( find(i) != find(1) )
    {
        //cout<< i << " and " << find(i) << endl;
        ok = 0;
        break;
    }
    if( !ok ) cost = -1;
    cout<< cost << endl;
    
    return 0;
}