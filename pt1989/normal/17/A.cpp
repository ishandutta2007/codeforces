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

const int mxn = 2048;
bool sv[mxn];
int main()
{
    vector<int> primes;
    sv[0] = sv[1] = 1;
    for(int i=2; i < mxn; i++)
    if( !sv[i] )
    {
        primes.pb( i );
        for(int j=2*i; j < mxn; j+=i)
        sv[j] = 1;
    }
    
    vector<int> sol;
    for(int i=0; i+1 < primes.size(); i++)
    sol.pb( primes[i] + primes[i+1] + 1 );
    sort( all ( sol ) );
    
    int n, k;
    cin>>n>>k;
    for(int i=0; k > 0 && i < sol.size(); i++)
    if( sol[i] <= n ) 
    if( !sv[sol[i]] )
    {
        //cout<< sol[i] << endl;
        k--;
    }
    
    string zz = (k<=0) ? "YES" : "NO";
    cout<< zz << endl;
    return 0;
}