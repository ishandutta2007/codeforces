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
    char buf[1024];
    int P = 0;
    ll ans = 0;
    while( gets(buf ) )
    {
        
        if( buf[0] == '+' )
        P++;
        else if( buf[0] == '-' )
        P--;
        else
        {
            bool flag = 0;
            int L = 0;
            for(int i=0; buf[i]; i++)
            {
                if( flag ) L++;
                if( buf[i] == ':' ) flag = 1;
            }
            ans += P * (ll) L ;
        }
    }
    cout<< ans << endl;
    return 0;
}