//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>



//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>




#define oo              0xBADC0DE
#define s(n)            scanf("%d",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define fill(a,v)       memset(a, v, sizeof a)
#define ull             unsigned long long
#define ll              long long
#define bitcount        __builtin_popcount
#define all(x)          x.begin(), x.end()
#define pb( z )         push_back( z )
#define gcd             __gcd
using namespace std;

int n;
//f(n,m) = f(n-1,m) + f(n,m-1); f(n,n) = C(2n+1, n+1)
const int mxn = (int)2e5+7;
const int mod = 1000000007;
int primes[mxn/2];
bool sv[mxn];
int psz = 0;

int calc(int n, int p) {
    int ret = 0;
    for (ll i=p; i <= n; i *= p) {
        ret += n/i;
    }
    return ret;
}

int main(){
    
    
    for (int i=2; i < mxn; i++)
    if (!sv[i]) {
        for (int j=i+i; j < mxn; j += i) {
            sv[j] = 1;
        }
        primes[psz++] = i;
    }
    
    cin>>n;
    --n;
    ll ans = 1;
    for (int i=0; i < psz && primes[i] <= 2*n+1; i++) {
        int pw = calc(2*n+1, primes[i]) - calc(n, primes[i]) - calc(n+1, primes[i]);
        ll cp = primes[i];
        while (pw > 0) {
            if (pw&1) {
                ans = ( ans * cp ) % mod;
            }
            cp = ( cp * cp ) % mod;
            pw >>= 1;
        }
    }
    
    ans = (2*ans - n - 1 + mod)%mod;
    
    cout << ans << endl;
    
    return 0;
}