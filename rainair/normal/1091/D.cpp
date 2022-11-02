#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int ha = 998244353;
const int MAXN = 1000000+5;
int fac[MAXN],inv[MAXN];int N;

inline LL qpow(LL a,LL n=ha-2){
    LL ret = 1;
    a %= ha;
    while(n){
        if(n & 1) ret = (ret*a)%ha;
        a = (a*a)%ha;
        n >>= 1;
    }
    return ret%ha;
}

inline void pre(){
    fac[0] = 1;
    FOR(i,1,MAXN-1) fac[i] = (fac[i-1]*i)%ha;
    inv[MAXN-1] = qpow(fac[MAXN-1]);
    ROF(i,MAXN-2,0) inv[i] = (inv[i+1]%ha*(i+1)%ha)%ha;
}

signed main(){
    scanf("%I64d",&N);
    pre();
    int ans = 0;
    FOR(i,1,N){
        ans = (ans + (fac[N] - (fac[N]*inv[i])%ha+ha)%ha)%ha;
    }
    printf("%I64d\n",ans+1);
    return 0;
}