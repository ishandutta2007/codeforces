/*
 * Author: RainAir
 * Time: 2019-08-27 18:12:12
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
const int MAXN = 20+5;
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

inline int C(int n,int m){
    if(n < 0) return 1;
    if(n < m) return 0;
    if(!m) return 1;
    int res = 1;
    FOR(i,n-m+1,n) res = 1ll*res*(i%ha)%ha;
    int t = 1;
    FOR(i,1,m) t = 1ll*t*i%ha;
    return 1ll*res*qpow(t)%ha;
}

int n,s;
int a[MAXN];

inline int pc(int x){
    int res = 0;
    while(x) res += x&1,x >>= 1;
    return res;
}

signed main(){
    scanf("%lld%lld",&n,&s);
    FOR(i,1,n) scanf("%lld",a+i);
    LL ans = 0;
    FOR(S,0,(1<<n)-1){
        int t = s;
        FOR(i,0,n-1){
            if((1<<i)&S) t -= a[i+1]+1;
        }
        if(t < 0) continue;
        ans = (ans+(pc(S)&1 ? -1 : 1)*C(t+n-1,n-1)%ha+ha)%ha;
    }
    printf("%lld\n",ans);
    return 0;
}