/*
 * Author: RainAir
 * Time: 2019-08-28 08:59:34
 */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 300+5;
const int ha = 1e9 + 7;
int fac[MAXN],inv[MAXN];

inline int qpow(int a,int n=ha-2){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}

inline void prepare(){
    fac[0] = 1;
    FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
    inv[MAXN-1] = qpow(fac[MAXN-1]);
    ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
    if(n < m) return 0;
    if(!m) return 1;
    return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}


int n,a[MAXN];
bool vis[MAXN];int sz[MAXN],cnt;
int f[MAXN][MAXN];

inline int pd(int x){
    int q = std::sqrt(1.0*x);
    return q*q == x;
}

signed main(){
    scanf("%lld",&n);prepare();
    FOR(i,1,n) scanf("%lld",a+i);
    FOR(i,1,n){
        if(vis[i]) continue;
        sz[++cnt] = 1;vis[i] = true;
        FOR(j,1,n){
            if(vis[j]) continue;
            if(pd(a[i]*a[j])){
                vis[j] = true;sz[cnt]++;
            }
        }
    }
    f[0][0] = 1;int tot = 0;
    FOR(i,1,cnt){
        FOR(j,0,tot){
            FOR(k,1,std::min(sz[i],tot+1)){
                FOR(d,0,std::min(j,k)){
                    int T = C(j,d)*C(sz[i]-1,k-1)%ha*C(tot-j+1,k-d)%ha;
                    (f[i][j-d+sz[i]-k] += f[i-1][j]*T%ha)%=ha;
                }
            }
        }
        tot += sz[i];
    }
    int ans = f[cnt][0];
    FOR(i,1,cnt) ans = 1ll*ans*fac[sz[i]]%ha;
    printf("%lld\n",ans);
    return 0;
}