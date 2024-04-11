#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
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
#define SFOR(i,a,b,step) for(Re int i = a;i <= b;i += step)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 300000;
const int ha = 1000000000+7;
int N;
int a[MAXN+5];
bool p[MAXN+5][10];

inline LL qpow(LL a,LL n=ha-2){
    LL ret = 1ll;
    while(n){
        if(n & 1) ret = (ret*a)%ha;
        a = (a * a) % ha;
        n >>= 1;
    }
    return ret;
}

LL fac[MAXN+5],inv[MAXN+5];

inline void pre(){
    fac[0] = fac[1] = 1;
    FOR(i,2,MAXN) fac[i] = (fac[i-1]*i)%ha;
    inv[MAXN] = qpow(fac[MAXN]);
    ROF(i,MAXN-1,0)
        inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

void sub(LL &a,LL b){
    a -= b;
    if(a < 0) a += ha;
}

int C(LL up,LL down){
    if(down < 0 || up < down) return 0;
    // DEBUG(fac[up]);DEBUG(inv[down]);DEBUG(inv[up-down]);getchar();
    return fac[up]*inv[down]%ha*inv[up-down]%ha;
}

int cnt[MAXN+5];
LL f[21][MAXN+5];

signed main(){
    pre();
    scanf("%I64d",&N);
    FOR(i,1,N){
        scanf("%I64d",a+i);
        cnt[a[i]]++;
    }
    FOR(i,1,MAXN)
        SFOR(j,i+i,MAXN,i)
            cnt[i] += cnt[j];
    // DEBUG(C(32,2));
    FOR(i,1,20){
        ROF(j,MAXN,1){
            f[i][j] = C(cnt[j],i);
             SFOR(k,j+j,MAXN,j) sub(f[i][j],f[i][k]);
        }
        if(f[i][1] > 0){
            printf("%I64d\n",i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}