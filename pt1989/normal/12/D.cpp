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
#define getcx getchar
inline void s( int &n )
{
    n=0;
    int ch=getcx();
    while( ch < '0' || ch > '9' ) ch=getcx();
    
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}
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

const int mxn = (int)5e5 + 7;
int b[mxn], l[mxn], r[mxn];
pair<int , pair<int, int> > a[mxn];
int n;
int tmp[mxn];
inline void solve( int * a )
{
    memcpy( tmp, a, 4*n );
    sort( tmp, tmp+n );
    int sz = unique( tmp, tmp+n ) - tmp;
    for(int i=0; i < n; i++)
        a[i] = lower_bound( tmp, tmp+sz, a[i] ) - tmp;
}

int tree[4*mxn];
int mp[mxn];
const int inf = 2;//(int)2e9;
inline void create( int node, int lo, int hi )
{
    if( lo == hi ) 
    {
        //cout<< lo << " goes to " << node << endl;
        mp[lo] = node;
        tree[node] = -inf;
        return;
    }
    int mid = (lo+hi)/2;
    create( node*2, lo, mid );
    create( node*2 + 1, mid+1, hi );
    tree[node] = max( tree[node*2], tree[node*2+1] );
}
inline int query( int node, int lo, int hi, int qlo, int qhi )
{
    if( lo > qhi || hi < qlo ) return -inf;
    if( qlo <= lo && hi <= qhi )
        return tree[node];
    int mid = (lo+hi)/2;
    return max( query( node*2 + 1, mid+1, hi, qlo, qhi ), query( node*2, lo, mid, qlo, qhi ) );
}

inline void update( int p, int v )
{
    int node = mp[p];
    if( tree[node] >= v ) return;
    
    tree[ node ] = v;
    
    node /= 2;
    while( node > 0 )
    {
        int old = tree[node];
        tree[node] = max( tree[node*2], tree[node*2+1] );
        
        if( old == tree[node] ) break;
        node /= 2;
    }
    //cout<<"doing " << node << " " << tree[node] << endl;
}

int main()
{
    s( n );
    for(int i=0; i < n; i++) s( b[i] );
    for(int i=0; i < n; i++) s( l[i] );
    for(int i=0; i < n; i++) s( r[i] );
    
    solve( b );
    solve( l );
    solve( r );
    
    for(int i=0; i < n; i++)
    {
        a[i] = make_pair( b[i], make_pair( l[i], r[i] ) );
    }
    sort( a, a+n );
    int sol = 0;
    create( 1, 0, n );
    for(int i=n-1; i >= 0; i--)
    {
        
        int y = a[i].second.first, z = a[i].second.second;
        int mx = query( 1, 0, n, y+1, n );
        if( mx > z ) 
        {
            sol++;
        }
        if( i-1 >= 0 && a[i-1].first == a[i].first ) continue;
        int j = i;
        while( j < n && a[j].first == a[i].first )
        {
            update( a[j].second.first, a[j].second.second );
            j++;
        }
    }
    cout<< sol << endl;
    return 0;
}