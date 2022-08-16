//DS includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>

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


const int mxn = (int)1e5 + 7;
pair<int ,int > kay[mxn], cat[mxn];
#define mp make_pair
int ksz, csz;
ll prekay[mxn], precat[mxn];

int main()
{
    int n, v;
    s( n ); s( v );
    for(int i=1; i <= n; i++)
    {
        int ti, pi;
        s( ti ); s( pi );
        if( ti == 1 )
            kay[ksz++] = mp( pi, i );
        else
            cat[csz++] = mp( pi, i );
    }
    sort( kay, kay+ksz ); reverse( kay, kay+ksz );
    sort( cat, cat+csz ); reverse( cat, cat+csz );
    
    for(int i=0; i < ksz; i++)
    {
        prekay[i] = kay[i].first;
        
        if( i )
            prekay[i] += prekay[i-1];
            
    }
    for(int i=0; i < csz; i++)
    {
        precat[i] = cat[i].first;
        if( i )
            precat[i] += precat[i-1];
    }
    
    int best = 0;
    int bestC = 0;
    for(int C=0; 2*C <= v && C <= csz; C++)
    {
        int K = min( ksz, v - 2*C );
        int profit = (C ? precat[C-1] : 0 ) + ( K ? prekay[K-1] : 0 );
        //cout<< C << " " << K << " " << profit << endl;
        if( profit > best )
        {
            best = profit;
            bestC = C;
        }
    }
    int C = bestC;
    int K = min( ksz, v-2*C );
    vector<int> soln;
    for(int i=0; i < C; i++) soln.pb( cat[i].second );
    for(int i=0; i < K; i++) soln.pb( kay[i].second );
    sort( all( soln ) );
    cout<<best<<endl;
    for(int i=0; i < soln.size(); i++)
    {
        cout<<soln[i];
        if( i+1 == soln.size() )
            cout<<"\n";
        else
            cout<<" ";
    }
    
    
    
    return 0;
}