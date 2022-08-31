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


const int mxn = (int)1e6+2;
int sum[mxn];
int root[mxn];
int rcnt[10];
int Z[10][10][10];


int main()
{
    
    int N;
    cin>>N;
    ll sol = 0;
    for(int i=1; i < mxn; i++)
    {
        sum[i] = sum[i/10] + (i%10);
        if( sum[i] <= 9 )
            root[i] = sum[i];
        else
            root[i] = root[ sum[i] ];
    }
    
    for(int A=1; A <= N; A++)
    {
        rcnt[ root[A] ] ++;
        
        for(int C=A, B=1; C <= N; B++, C+=A)
        {
            Z[ root[ A ] ][ root[ B ] ][ root[ C ] ] ++;
        }
    }
    
    for(int ra=1; ra <= 9; ra++)
    for(int rb=1; rb <= 9; rb++)
    {
        int rc = root[ ra*rb ];
        ll x = rcnt[ ra ]*(ll)rcnt[ rb ]*(ll)rcnt[ rc ] - Z[ ra ][ rb ][ rc ];
        sol += x;
    }
    
    
    cout<<sol<<endl;
    return 0;
}