#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
 
#define oo            (int)13e7
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;

const int mod = 1000000007;
int expo(int _a, int p) {
    ll r = 1, a = _a;
    while (p > 0) {
        if (p&1) {
            r = (r * a) % mod;
        }
        a = (a * a) % mod;
        p >>= 1;
    }
    return r;
}
int modInv(int a) {
    return expo(a, mod-2);
}

const int mxn = 1000007;
int f[mxn];
int finv[mxn];

int comb(int n, int k) {
    if (n < k) return 0;
    ll w = f[n];
    w = ( w * finv[k] ) % mod;
    w = ( w * finv[n-k] ) % mod;
    return w;
}
int tilings[mxn];

int main(int argc, char** argv) {
    f[0] = 1;
    for (int i=1; i < mxn; i++) {
        f[i] = ( f[i-1] * (ll) i ) % mod;
    }
    for (int i=0; i < mxn; i++) {
        finv[i] = modInv(f[i]);
    }
    
    
    int n, m, k;
    cin>>n>>m>>k;
    
    for (int distinct=1; distinct <= n && distinct <= k; distinct++) {
        if (distinct == 1) {
            tilings[distinct] = 1;
        } else {
            ll ans = expo(distinct, n);
            for (int j=distinct-1; j >= 1; j--) {
                ans -= comb(distinct, j)* (ll) tilings[j];
                ans %= mod; 
            } 
            ans = (ans + mod)%mod;
            tilings[distinct] = ans;
        }
        //cout << distinct << " colors in " << n << " tiles " << tilings[distinct] << endl;
    }
    
    
    if (m==1) {
        cout << expo(k, n) << endl;
    } else {
        ll ans = 0;
        for (int distinct=1; distinct <= n; distinct++) {
            for (int common=0; common <= distinct; common++) {
                int total = 2*distinct - common;
                if (total > k) continue;
                int side = distinct - common;
                ll waysToPick = comb(k, common); //cout << waysToPick << endl;
                waysToPick *= comb(k-common, side); waysToPick %= mod; //cout << waysToPick << endl;
                waysToPick *= comb(k-common-side, side); waysToPick %= mod;  //cout << waysToPick << endl;
                
                //printf("C(%d, %d) * C(%d, %d) * C(%d, %d)\n", k, common, k-common, side, k-common-side, side);
                
                ll waysToColor = expo( common, n*(m-2) );
                waysToColor *= tilings[distinct]; waysToColor %= mod;
                waysToColor *= tilings[distinct]; waysToColor %= mod;
                
                ans = (ans + waysToColor*waysToPick) % mod;
            }
        }
        cout << ans << endl;
    }
    
	return 0;
}