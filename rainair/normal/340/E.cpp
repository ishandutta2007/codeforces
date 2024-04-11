/*
 * Author: RainAir
 * Time: 2019-08-28 07:52:42
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
const int MAXN = 2000+5;
const int ha = 1e9 + 7;

inline int qpow(int a,int n=ha-2){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}

int a[MAXN],fac[MAXN],inv[MAXN];

inline void prework(int n){
    fac[0] = 1;
    FOR(i,1,n) fac[i] = 1ll*fac[i-1]*i%ha;
    inv[n] = qpow(fac[n]);
    ROF(i,n-1,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}
int n,m;
bool vis1[MAXN],vis2[MAXN];

inline int C(int n,int m){
    if(n < m) return 0;
    if(!m) return 1;
    return fac[n]*inv[m]%ha*inv[n-m]%ha;
}

inline int calc(int s){
    int ans = fac[m];
    FOR(i,1,s)
        ans = (ans + ((i&1) ? -1 : 1)*C(s,i)*fac[m-i]%ha+ha)%ha;
    return ans;
}

signed main(){
    scanf("%lld",&n);prework(n);
    FOR(i,1,n) scanf("%lld",a+i);
    FOR(i,1,n){
        if(a[i] == -1) m++;
        else{
            vis1[i] = true;
            vis2[a[i]] = true;
        } 
    }
    int cnt = 0;
    FOR(i,1,n) if(!vis1[i] && !vis2[i]) cnt++;
    printf("%lld\n",calc(cnt));
    return 0;
}