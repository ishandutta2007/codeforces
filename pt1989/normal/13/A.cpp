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


int sum( int n, int b )
{
    int ret = 0;
    while( n > 0 )
    {
        ret += n%b;
        n /= b;
    }
    return ret;
}
int main()
{
    int n;
    s( n );
    int num = 0;
    int den = 0;
    for(int b=2; b < n; b++)
    {
        den++;
        num += sum( n, b );
    }
    int gc = gcd( num, den );
    num /= gc;
    den /= gc;
    cout<< num << "/" << den << endl;
    return 0;
}